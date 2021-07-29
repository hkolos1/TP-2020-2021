/*
    TP 16/17 (Tutorijal 7, Zadatak 4)
        Autotestove pisao Elmir Hodzic. Sva pitanja,
        prijave gresaka i sugestije slati na mail
        ehodzic3@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
typedef std::shared_ptr<std::string> SmartPtr;

int main() {
  int brojRecenica;
  std::cout << "Koliko zelite recenica: ";
  std::cin >> brojRecenica;
  std::cout << "Unesite recenice: " << std::endl;
  std::cin.ignore(10000, '\n');
  try {
    std::unique_ptr<SmartPtr[]> recenice(new SmartPtr[brojRecenica]);
    for (int i = 0; i < brojRecenica; i++) {
      recenice[i] = std::make_shared<std::string>();
      std::getline(std::cin, *recenice[i]);
    }
    std::sort(recenice.get(), recenice.get() + brojRecenica,
              [](SmartPtr s1, SmartPtr s2) { return *s1 < *s2; });
    std::cout << "Sortirane recenice: " << std::endl;
    for (int i = 0; i < brojRecenica; i++)
      std::cout << *recenice[i] << std::endl;
  } catch (std::bad_alloc) {
    std::cout << "Problemi s memorijom!" << std::endl;
  }
  return 0;
}