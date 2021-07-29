/*
    TP 16/17 (Tutorijal 7, Zadatak 3)
        Autotestove pisao Elmir Hodzic. Sva pitanja,
        prijave gresaka i sugestije slati na mail
        ehodzic3@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <new>
#include <string>

int main() {
  int brojRecenica;
  std::cout << "Koliko zelite recenica: ";
  std::cin >> brojRecenica;
  std::cout << "Unesite recenice: " << std::endl;
  std::cin.ignore(10000, '\n');
  std::string **recenice = nullptr;
  try {
    recenice = new std::string *[brojRecenica] {};
    for (int i = 0; i < brojRecenica; i++) {
      recenice[i] = new std::string;
      std::getline(std::cin, *recenice[i]);
    }
    std::sort(recenice, recenice + brojRecenica,
              [](std::string *s1, std::string *s2) { return *s1 < *s2; });
    std::cout << "Sortirane recenice: " << std::endl;
    for (int i = 0; i < brojRecenica; i++)
      std::cout << *recenice[i] << std::endl;
    for (int i = 0; i < brojRecenica; i++)
      delete[] recenice[i];
    delete[] recenice;
  } catch (std::bad_alloc) {
    if (recenice)
      for (int i = 0; i < brojRecenica; i++)
        delete[] recenice[i];
    delete[] recenice;
    std::cout << "Problemi s memorijom!" << std::endl;
  }
  return 0;
}