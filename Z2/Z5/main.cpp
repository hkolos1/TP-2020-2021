// TP 2018/2019: Zadaća 2, Zadatak 5
#include <cstring>
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>

int PotencijalniKrivci(char **&a, std::vector<std::string> imena) {
  // std::cout << "CCCCC";
  if (imena.size() == 0)
    return 0;
  int c = 0;
  try {
    a = new char *[imena.size()] {};
    try {
      for (int i{0}; i < imena.size(); i++) {
        a[i] = new char[imena.at(i).size() + 1]{};
        char *p = a[i];
        int b{0};
        while (b < imena.at(i).size()) {
          *p = imena.at(i).at(b);
          b++;
          p++;
        }
        *p = '\0';
        c++;
      }
    } catch (std::bad_alloc) {
      for (int i{0}; i < imena.size(); i++)
        delete[] a[i];
      delete[] a;
      throw;
    }
  } catch (std::bad_alloc) {
    delete[] a;
    throw;
  }
  return c;
}

int OdbaciOptuzbu(char **&a, int n, std::string krivac) {
  // std::cout << "VVVV";
  int brojac{0};
  bool ima{false};
  for (int i{0}; i < n; i++) {
    bool jesu{false};
    int b{0};
    while (b < krivac.length() && a[i][b] == krivac.at(b)) {
      b++;
    }
    if (b == krivac.length()) {
      delete[] a[i];
      a[i] = nullptr;
      brojac++;
      ima = true;
    }

    if (a[i] == nullptr)
      brojac++;
  }
  // std::cout << "AAAA" << ima;
  if (!ima)
    throw std::domain_error("Osoba sa imenom " + krivac +
                            " nije bila optuzena!");
  char **p{nullptr};

  if (brojac > 10) {
    int b{0};
    p = new char *[n - brojac] {};
    for (int i{0}; i < n; i++) {
      if (a[i] != nullptr) {
        int g{0};
        while (g < std::strlen(a[i])) {
          p[b][g] = a[i][g];
          g++;
        }
        p[b][g] = '\0';
        b++;
      }
    }
    for (int i{0}; i < n; i++)
      delete[] a[i];
    delete[] a;
    a = p;
    n = b;
  }
  return n;
}

int DodajOptuzbu(char **&a, int n, std::string krivac) {
  // std::cout<<"GGGGG";
  if (n == 0) {
    a = new char *[1];
    a[0] = new char[krivac.length() + 1];
    int b{0};
    while (b < krivac.length()) {
      a[0][b] = krivac[b];
      b++;
    }
    a[0][b] = '\0';
    n++;
    return n;
  }
  int ima_mjesta{false};
  for (int i{0}; i < n; i++) {
    if (a[i] == nullptr) {
      a[i] = new char[krivac.length() + 1]{};
      int b{0};
      while (b < krivac.length()) {
        a[i][b] = krivac[b];
        b++;
      }
      a[i][b] = '\0';
      ima_mjesta = true;
      break;
    }
  }
  if (!ima_mjesta) {
    char **p = new char *[n + 1] {};
    for (int i{0}; i < n; i++) {
      p[i] = new char[std::strlen(a[i]) + 1];
      int b{0};
      while (b < std::strlen(a[i])) {
        p[i][b] = a[i][b];
        b++;
      }
      p[i][b] = '\0';
    }
    try {
      p[n] = new char[krivac.length() + 1];

      int b{0};
      while (b < krivac.length()) {
        p[n][b] = krivac[b];
        b++;
      }
      p[n][b] = '\0';

      for (int i{0}; i < n; i++)
        delete[] a[i];
      delete[] a;
      n++;
      a = p;
    } catch (std::bad_alloc) {
      delete[] p[n];
      throw;
    }
  }
  return n;
}

void IzlistajOptuzbu(char **a, int n) {
  std::cout << "Spisak trenutno optuzenih:" << std::endl;
  for (int i{0}; i < n; i++) {
    if (a[i] != nullptr)
      std::cout << a[i] << std::endl;
  }
}


int main() {
  int a{0};
  char **p{nullptr};
  try {
    int n;

    std::cout
        << "Unesite broj ljudi koji su optuzeni za prepisivanje/prodavanje "
           "zadaca: ";
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(100000, '\n');
    std::vector<std::string> v(n);
    for (int i{0}; i < n; i++) {
      std::string s;
      std::cout << "Unesite ime optuzenog: ";
      std::getline(std::cin, s);
      v.at(i) = s;
    }

    a = PotencijalniKrivci(p, v);
    std::cout << "Duzina spiska: " << a << std::endl;
    IzlistajOptuzbu(p, a);
    std::cout << "Unesite ime osobe oslobodjene optuzbi: ";
    std::string oslobodjeni;
    std::getline(std::cin, oslobodjeni);
    a = OdbaciOptuzbu(p, a, oslobodjeni);
    IzlistajOptuzbu(p, a);
    std::cout << "Unesite ime novog optuzenog: ";
    std::string optuzeni;
    std::getline(std::cin, optuzeni);
    a = DodajOptuzbu(p, a, optuzeni);
    IzlistajOptuzbu(p, a);
  } catch (std::domain_error e) {
    std::cout << e.what();
  } catch (...) {
    std::cout << "Nedovoljno memorije!";
  }
  for (int i{0}; i < a; i++)
    delete[] p[i];
  delete[] p;

  return 0;
}