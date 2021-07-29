// TP 2020/2021: Tutorijal 2, Zadatak 3
#include <complex>
#include <iostream>

int main() {
  int a;
  std::cout << "Unesite broj elemenata: ";
  std::cin >> a;
  std::cout << std::endl;
  std::complex<double> impedansa(0, 0);

  for (int i = 0; i < a; i++) {
    std::complex<double> z;
    std::cout << "Z_" << i + 1 << " = ";
    std::cin >> z;
    impedansa += 1. / z;
  }
  impedansa = 1. / impedansa;
  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima impedansu Z_ = " << impedansa
            << ".";

  return 0;
}
