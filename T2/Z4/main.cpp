// TP 2020/2021: Tutorijal 2, Zadatak 4
#include <complex>
#include <iostream>

int main() {
  int a;
  std::cout << "Unesite broj elemenata: ";
  std::cin >> a;
  std::cout << std::endl;
  std::complex<double> impedansa(0, 0);
  double realan(0), imaginaran(0);

  for (int i = 0; i < a; i++) {
    std::complex<double> z;
    std::cout << "R" << i + 1 << " = ";
    std::cin >> realan;
    std::cout << "X" << i + 1 << " = ";
    std::cin >> imaginaran;
    z = std::complex<double>(realan, imaginaran);
    impedansa += 1. / z;
    std::cout << std::endl;
  }
  impedansa = 1. / impedansa;
  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima R = " << impedansa.real()
            << " i X = " << impedansa.imag() << ".";

  return 0;
}
