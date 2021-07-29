// TP 2016/2017: Tutorijal 1, Zadatak 4
#include <cmath>
#include <iostream>

int main() {
  double broj;
  int suma{0};
  for (;;) {
    suma = 0;
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    std::cin >> broj;
    if (broj == 0 && std::cin) {
      std::cout << "Dovidjenja!";
      return 0;
    } else if (!(std::cin) || broj < 0 || broj - int(broj) != 0) {
      std::cout << "Niste unijeli prirodan broj!" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    } else {
      for (int i = 1; i < broj; i++) {
        if (int(broj) % i == 0)
          suma += i;
      }

      if (suma < broj)
        std::cout << "Broj " << broj << " je manjkav!" << std::endl;
      else if (suma > broj)
        std::cout << "Broj " << broj << " je obilan!" << std::endl;
      else
        std::cout << "Broj " << broj << " je savrsen!" << std::endl;
    }
  }
  return 0;
}