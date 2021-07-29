/*
    TP 16/17 (Tutorijal 7, Zadatak 2)
        Autotestove pisao Elmir Hodzic. Sva pitanja,
        prijave gresaka i sugestije slati na mail
        ehodzic3@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <new>

int main() {
  int brojRecenica;
  std::cout << "Koliko zelite recenica: ";
  std::cin >> brojRecenica;
  char **recenice = nullptr;
  std::cout << "Unesite recenice: " << std::endl;
  try {
    recenice = new char *[brojRecenica] {};
    std::cin.ignore(10000, '\n');
    for (int i = 0; i < brojRecenica; i++) {
      char tmp[1000];
      std::cin.getline(tmp, sizeof tmp);
      recenice[i] = new char[std::strlen(tmp) + 1];
      std::strcpy(recenice[i], tmp);
    } /*
     for(int i=0; i<brojRecenica; i++){
         int minIndex=i;
         for(int j=i+1; j<brojRecenica; j++)
         if(std::strcmp(recenice[j], recenice[minIndex])<0)
         minIndex=j;
         char *tmp=recenice[i];
         recenice[i]=recenice[minIndex];
         recenice[minIndex]=tmp;

     }
     */
    std::sort(
        recenice, recenice + brojRecenica,
        [](const char *s1, const char *s2) { return std::strcmp(s1, s2) < 0; });
    std::cout << "Sortirane recenice: " << std::endl;
    for (int i = 0; i < brojRecenica; i++)
      std::cout << recenice[i] << std::endl;
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