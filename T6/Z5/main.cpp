/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

        Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
        i sugestije saljite na mail: khodzic2@etf.unsa.ba

        Napomene: testovi su konacni tek pred tutorijal
                          za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <deque>
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>

template <typename NekiTip>
auto KreirajDinamickuKopiju2D(NekiTip mat) ->
    typename std::remove_reference<decltype(mat.at(0))>::type * {
  typename std::remove_reference<decltype(mat.at(0).at(0))>::type **p(nullptr);
  try {
    p = new double *[mat.size()] {};
    try {
      for (int i{0}; i < mat.size(); i++)
       // p[i] = new double[mat.at(i)];
    } catch (...) {
      for (int i{0}; i < mat.size(); i++)
        delete[] p[i];
      delete[] p;
      throw;
    }
  } catch (...) {
    throw;
  }
  for (int i{0}; i < mat.size(); i++) {
    for (int j{0}; j < mat.at(i).size(); j++) {
      p[i][j] = mat.at(i).at(j);
    }
  }
  return p;
}
int main() {
  try {
    std::deque<std::vector<double>> m{};
    auto m1(KreirajDinamickuKopiju2D(m));
    for (int i = 0; i < 4; i++) {
      for (int j = 0; i < 3; j++)
        std::cout << m1[i][j] << " ";
      std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++)
    delete[] m1;
  } catch (std::bad_alloc) {
    std::cout << "Nedovoljno memorije!";
  }
  return 0;
}