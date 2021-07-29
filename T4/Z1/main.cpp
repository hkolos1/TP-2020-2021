// TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <limits>

int Cifre(long long int n, int &c_min, int &c_max) {
  int broj_cifre{0};
  c_min = 9;
  c_max = 0;
  if (n == 0) {
    c_min = 0;
    return 1;
  }
  if (n < 0) {
    while (n != 0) {
      if (-(n % 10) < c_min)
        c_min = -(n % 10);
      if (-(n % 10) > c_max)
        c_max = -(n % 10);
      broj_cifre++;
      n /= 10;
    }
  } else {
    while (n != 0) {
      if (n % 10 < c_min)
        c_min = n % 10;
      if (n % 10 > c_max)
        c_max = n % 10;
      broj_cifre++;
      n /= 10;
    }
  }
  return broj_cifre;
}

int main() {
  long long int broj;
  int a{0}, b{0};
  std::cout << "Unesite broj: ";
  std::cin >> broj;
  int cifre{Cifre(broj, a, b)};
  std::cout << "Broj "
            << " ima " << cifre << " cifara, najveca je " << b << " a najmanja "
            << a << ".";
  return 0;
}