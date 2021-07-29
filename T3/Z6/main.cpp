// TP 2018/2019: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>

int NajvecaSirina(std::vector<std::vector<int>> m) {
  int sirina{0}, najveca_sirina{0};
  for (std::vector<int> red : m) {
    for (int element : red) {
      if (element < 0)
        sirina++;
      while (element != 0) {
        sirina++;
        element /= 10;
      }
      if (sirina > najveca_sirina) {
        najveca_sirina = sirina;
      }
      sirina = 0;
    }
  }
  return najveca_sirina;
}
std::vector<std::vector<int>> KroneckerovProizvod (std::vector<int> a, std::vector<int> b){
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(b.size()));
    for(int i{0}; i<a.size(); i++){
        for(int j{0}; j<b.size(); j++){
            c.at(i).at(j)=a.at(i)*b.at(j);
        }
    }
    return c;
}

int main() {
  int n1{0};
  std::cout << "Unesite broj elemenata prvog vektora: ";
  std::cin >> n1;
  std::vector<int>v1;
  std::cout<<"Unesite elemente prvog vektora: ";
  int element{0};
  for(int i=0; i<n1; i++){
      std::cin>>element;
      v1.push_back(element);
  }
  int n2{0};
  std::cout<<"Unesite broj elemenata drugog vektora: ";
  std::cin>> n2;
  std::vector<int>v2;
  std::cout<<"Unesite elemente drugog vektora: " <<std::endl;
  for( int i=0; i<n2; i++){
      std::cin>>element;
      v2.push_back(element);
  }
  std::vector<std::vector<int>>m(KroneckerovProizvod(v1,v2));
  int sirina{NajvecaSirina(m)};
  for(std::vector<int> red: m){
      for(int e: red){
          std::cout<<std::right<<std::setw(sirina+1)<<e;
      }
      std::cout<<std::endl;
  }


  return 0;
}