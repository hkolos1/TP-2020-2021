/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

        Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
        i sugestije saljite na mail: khodzic2@etf.unsa.ba

        Napomene: testovi su konacni tek pred tutorijal
                          za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>

template <typename NekiTip>
auto KreirajIzvrnutiNiz(NekiTip pocetak, NekiTip iza_kraja) ->
    typename std::remove_reference<decltype(*pocetak)>::type * {
  NekiTip p(pocetak);
  int n{0};
  while (p != iza_kraja) {
    n++;
    p++;
  }
  typename std::remove_reference<decltype(*pocetak)>::type *q(nullptr);
  try {
    q = new typename std::remove_reference<decltype(*pocetak)>::type[n];
  } catch (std::bad_alloc) {
    delete[] q;
    throw;
  }
  for (int i{0}; i < n; i++) {
    q[n - 1 - i] = *pocetak;
    pocetak++;
  }
  return q;
}

int main() {
  int n;
  std::cout << "Koliko zelite elemenata: ";
  std::cin >> n;
  double *p{nullptr};
  try {
    std::vector<double> v(n);
    std::cout << "Unesite elemente: ";
    for (int i{0}; i < n; i++) {
      std::cin >> v.at(i);
    }
    try {
      p = KreirajIzvrnutiNiz(v.begin(), v.end());
    } catch (std::bad_alloc) {
      std::cout << "Nedovoljno memorije!";
      delete[] p;
      return 0;
    }
  }
  catch(...){
      std::cout<<"Nedovoljno memorije!";
      return 0;
  }
  std::cout<<"Kreirani niz: ";
  for(int i{0}; i<n; i++){
      std::cout<<p[i]<<" ";
  }
  delete[] p;
  return 0;
}