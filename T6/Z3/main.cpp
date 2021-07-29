/*
    TP 2018/2019: Tutorijal 6, Zadatak 3

        Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
        i sugestije saljite na mail: khodzic2@etf.unsa.ba

        Napomene: testovi su konacni tek pred tutorijal
                          za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <new>
#include <stdexcept>

int **KreirajTrougao(int n) {
  if (n <= 0)
    throw std::domain_error("Broj redova mora biti pozitivan");
  int **p{nullptr};
  try {
    p = new int *[n] {};
    try {
      for (int i{0}; i < n; i++)
        p[i] = new int[2 * i + 1];
    } catch (...) {
      for (int i{0}; i < n; i++)
        delete[] p[i];
      delete[] p;
      throw;
    }
  } catch (...) {
    throw;
  }
  int broj{0}, broj1{0};
  for (int i{0}; i < n; i++) {
    broj1 = 2;
    for (int j{0}; j < 2 * i + 1; j++) {
      broj = i + 1;
      if (j == 0 || j == 2 * i)
        p[i][j] = i + 1;
      else if (j != 0 && j <= (2 * i + 1) / 2)
        p[i][j] = broj - j;
      else if (j > (2 * i + 1) / 2)
        p[i][j] = broj1++;
    }
  }
  return p;
}

int main() {
  int n;
  std::cout << "Koliko zelite redova: ";
  std::cin >> n;
  int **p{nullptr};
  try {
    p = KreirajTrougao(n);
  } 
  catch (std::domain_error e){
      std::cout<<"Izuzetak: "<<e.what();
      return 0;
  }
  catch (...) {
    std::cout << "Izuzetak: Nedovoljno memorije!";
    return 0;
  }
  for (int i{0}; i < n; i++) {
    for (int j{0}; j < i * 2 + 1; j++) {
      std::cout << p[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i{0}; i < n; i++) {
    delete[] p[i];
    delete[] p;
  }

  return 0;
}