/*
    TP 2018/2019: Tutorijal 6, Zadatak 6

        Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
        i sugestije saljite na mail: khodzic2@etf.unsa.ba

        Napomene: testovi su konacni tek pred tutorijal
                          za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <new>
#include <type_traits>
#include <deque>
#include <vector>

template <typename DvaDStruct>
auto KreirajDinamickuKopiju2D(DvaDStruct matrica) ->
    typename std::remove_reference<decltype(matrica[0][0])>::type ** {
  typename std::remove_reference<decltype(matrica[0][0])>::type **matricaCpy =
      nullptr;
  try {
    matricaCpy =
        new typename std::remove_reference<decltype(matrica[0][0])>::type
            *[matrica.size()] {};
    matricaCpy[0] =
        new typename std::remove_reference<decltype(matrica[0][0])>::type
            [matrica.size() * matrica[matrica.size() - 1].size()];
    for (int i = 1; i < matrica.size(); i++)
      matricaCpy[i] = matricaCpy[i - 1] + matrica[i].size();
    for (int i = 0; i < matrica.size(); i++)
      for (int j = 0; j < matrica.at(i).size(); j++)
      matricaCpy[i][j]=matrica[i][j];
  } catch(std::bad_alloc){
      if(matricaCpy) delete[] matricaCpy[0];
      delete[] matricaCpy;
      throw;
  }
  return matricaCpy;
}

int main() {
    int redovi;
    std::cout<<"Unesite broj redova kvadratne matrice: ";
    std::cin>>redovi;
    try{
        std::vector<std::deque<int>> matrica(redovi, std::deque<int>(redovi));
        std::cout<<"Unesite elemente matrice: ";
        for(int i=0; i<redovi; i++)
        for(int j=0; j<redovi; j++)
        std::cin>>matrica.at(i).at(j);
        auto dynamicMat = KreirajDinamickuKopiju2D(matrica);
        for(int i=0; i<redovi; i++){
            for(int j=0; i<redovi; j++)
            std::cout<<dynamicMat[i][j]<<" ";
            std::cout<< std::endl;
        }
        delete[] dynamicMat[0]; delete[] dynamicMat;
    } catch(std::bad_alloc){
        std::cout<<"Nedovoljno memorije" << std::endl;
    }
    
     return 0;
      }