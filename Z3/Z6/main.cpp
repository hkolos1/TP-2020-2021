// TP 2018/2019: Zadaća 3, Zadatak 5
#include <iostream>
#include <memory>
#include <vector>


struct Blok {
  int redni_broj;
  std::shared_ptr<Blok> sljedeci;
};

std::vector<int> Razbrajanje(int N, int M) {
  std::vector<int> izdvojeni;
  std::shared_ptr<Blok> pocetak{nullptr}, prethodni{nullptr};
  for (int i{1}; i <= N; i++) {
    std::shared_ptr<Blok> novi = std::make_shared<Blok>();
    novi->redni_broj = i;
    novi->sljedeci = nullptr;
    if (!pocetak)
      pocetak = novi;
    else
      prethodni->sljedeci = novi;
    prethodni = novi;
  }

  prethodni->sljedeci = pocetak;
  std::shared_ptr<Blok> p{pocetak};
  int n{N};
  while (n > 1) {
    // std::cout << p->redni_broj << " ";
    if (n == N) {
      izdvojeni.push_back(p->redni_broj);
      std::shared_ptr<Blok> temp{p};
      prethodni->sljedeci = p->sljedeci;
      p = p->sljedeci;
    } else {
      std::shared_ptr<Blok> temp{p->sljedeci};
      p->sljedeci = temp->sljedeci;
      p = temp->sljedeci;
      izdvojeni.push_back(temp->redni_broj);
    }
    int i{0};
    while (i < M - 2) {
      p = p->sljedeci;
      i++;
    }
    n--;
  }
  izdvojeni.push_back(p->redni_broj);
  p->sljedeci = nullptr;

  /*for (int i{0}; i < izdvojeni.size(); i++)
      std::cout << izdvojeni.at(i) << " ";*/
  return izdvojeni;
}

int OdabirKoraka(int N, int K) {
  if (N <= 0 || K <= 0 || K > N)
    throw std::domain_error(
        "Broj blokova i redni broj bloka su pozitivni cijeli brojevi i redni "
        "broj bloka ne moze biti veci od broja blokova");
  for (int i{2}; i < N; i++) {
    std::vector<int> v{Razbrajanje(N, i)};
    if (v.at(v.size() - 1) == K)
      return i;
  }
  return 0;
}

int main() {
  try {
    int n;
    std::cout << "Unesite broj blokova u gradu: ";
    std::cin >> n;
    int m;
    std::cout
        << "Unesite redni broj bloka u kojem se nalazi sjediste stranke: ";
    std::cin >> m;
    std::cout << "Trazeni korak: " << OdabirKoraka(n, m);
  } catch (std::domain_error e) {
    std::cout << e.what();
  }
  /*std::vector<int> a = Razbrajanje(10, 0);
  std::cout<<"aaa"<<a.size();*/
  return 0;
}