// TP 2016/2017: Tutorijal 1, Zadatak 1
#include <cmath>
#include <iostream>
int main() {
  int a, b, c;
  std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
  std::cin >> a >> b >> c;
  int d;
  std::cout << "Unesite sirinu plocice u centimetrima: \n";
  std::cin >> d;

  int povrsina;
  povrsina = (2 * b * c + 2 * a * c + a * b) * 10000;
  double Z = double(povrsina) / (d * d);
  int povrsina1 = povrsina;

  if ((a * b * 10000) % (d * d) == 0 && (b * c * 10000) % (d * d) == 0 &&
      (a * c * 10000) % (d * d) == 0 && (a * 100) % d == 0 &&
      (b * 100) % d == 0 && (c * 100) % d == 0) {
    std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x"
              << c << "m sa plocicama dimenzija " << d << "x" << d << "cm\n"
              << "potrebno je " << Z << " plocica.";
  } else
    std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c
              << "m sa plocicama dimenzija " << d << "x" << d << "cm\n"
              << "nije izvodljivo bez lomljenja plocica!";
  return 0;
}