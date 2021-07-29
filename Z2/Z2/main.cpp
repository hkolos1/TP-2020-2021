// TP 2018/2019: Zadaća 2, Zadatak 2
#include <iostream>
#include <vector>
#include <cmath>

int Kvadrat(int n) { return n * n; }
void SumaCetiriKvadrata(int n, int &a, int &b, int &c, int &d) {
  if (n < 0)
    throw std::domain_error("Broj koji se rastavlja mora biti nenegativan");
  int temp{0};
  std::vector<int> brojevi;
  if (n == 0) {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return;
  }
  for (int i{0}; i <= std::sqrt(n); i++) {
    for (int j{0}; j <= std::sqrt(n); j++) {
      for (int k{0}; k <= std::sqrt(n); k++) {
        for (int l{0}; l <= std::sqrt(n); l++) {
          temp = Kvadrat(l) + Kvadrat(k) + Kvadrat(i) + Kvadrat(j);
          if (temp == n) {
            brojevi.push_back(i);
            brojevi.push_back(j);
            brojevi.push_back(k);
            brojevi.push_back(l);
            break;
          }
        }
        if (brojevi.size() != 0)
          break;
      }
      if (brojevi.size() != 0)
        break;
    }
    if (brojevi.size() != 0)
      break;
  }
  for (int i{0}; i < brojevi.size(); i++) {
    for (int j{i + 1}; j < brojevi.size(); j++) {
      if (brojevi.at(j) > brojevi.at(i)) {
        int temp{brojevi.at(j)};
        brojevi.at(j) = brojevi.at(i);
        brojevi.at(i) = temp;
      }
    }
  }
  a = brojevi.at(0);
  b = brojevi.at(1);
  c = brojevi.at(2);
  d = brojevi.at(3);
}

int main() {
  try {
    int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int a, b, c, d;
    SumaCetiriKvadrata(n, a, b, c, d);
    std::cout << "Broj " << n
              << " se moze zapisati kao zbir kvadrata brojeva: " << a << ", "
              << b << ", " << c << ", " << d << ".";
  } catch (std::domain_error e) {
    std::cout << e.what();
  }

  return 0;
}