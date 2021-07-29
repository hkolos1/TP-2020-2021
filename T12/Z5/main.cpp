/*
    TP 16/17 (LV 12, Zadatak 5)
        Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: khodzic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int brojElemenata;
  std::cout << "Koliko zelite elemenata: ";
  std::cin >> brojElemenata;
  std::vector<double> elementi(brojElemenata);
  std::cout << "Unesite elemente: ";
  for (int i = 0; i < brojElemenata; i++)
    std::cin >> elementi.at(i);
  std::transform(elementi.begin(), elementi.end(), elementi.begin(),
                 std::bind(std::divides<double>(), 1, std::placeholders::_1));
  std::cout << "Transformirani elementi: ";
  for (int i = 0; i < brojElemenata; i++)
    std::cout << elementi.at(i) << " ";

  return 0;
}