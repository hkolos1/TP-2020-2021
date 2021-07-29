// TP 2020/2021: Tutorijal 2, Zadatak 5
#include <complex>
#include <iostream>

const double pi{4 * std::atan(1)};

int main() {
  int a;
  std::cout << "Unesite broj elemenata: ";
  std::cin >> a;
  std::cout << std::endl;
  std::complex<double> z, impedansa;
  double trenutna(0), ugao(0);
  for (int i = 0; i < a; i++) {
    std::cout << "Z" << i + 1 << " = ";
    std::cin >> trenutna;
    std::cout << "fi" << i + 1 << " = ";
    std::cin >> ugao;
    z = std::polar(trenutna, (ugao * pi) / 180);
    impedansa += 1. / z;
    std::cout << std::endl;
  }
  impedansa = 1. / impedansa;
  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima Z = " << std::abs(impedansa)
            << " i fi = " << std::arg(impedansa) * 180 / pi << ".";

  return 0;
}
