/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

        Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
        i sugestije saljite na mail: khodzic2@etf.unsa.ba

        Napomene: testovi su konacni tek pred tutorijal
                          za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>


template <typename NekiTip> NekiTip *GenerirajStepeneDvojke(int n) {
  if (n <= 0)
    throw std::domain_error("Broj elemenata mora biti pozitivan");
  NekiTip *p{nullptr};
  try {
    p = new NekiTip[n];
  } catch (std::bad_alloc) {
    delete[] p;
    throw std::runtime_error("Alokacija nije uspjela");
  }
  NekiTip stepen_dvojke{1};
  for (int i{0}; i < n; i++) {
    if (stepen_dvojke >
        (std::numeric_limits<long double>::max() || stepen_dvojke <= 0)) {
      delete[] p;
      throw std::overflow_error("Prekoracen dozvoljeni opseg");
    }
    p[i] = stepen_dvojke;
    stepen_dvojke *= 2;
  }
  return p;
}

int main() {
  int n;
  std::cout << "Koliko zelite elemenata: ";
  std::cin >> n;
  int *pok{nullptr};
  try {
    pok = GenerirajStepeneDvojke<int>(n);

  } catch (std::domain_error izuzetak1) {
    std::cout << "Izuzetak: " << izuzetak1.what();
    delete[] pok;
    return 0;

  } catch (std::runtime_error izuzetak2) {
    std::cout << "Izuzetak: " << izuzetak2.what();
    delete[] pok;
    return 0;
  }

  for (int i{0}; i < n; i++) {
    std::cout << pok[i] << " ";
  }
  delete[] pok;

  return 0;
}