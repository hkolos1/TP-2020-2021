// TP 2018/2019: Zadaća 2, Zadatak 4
#include <algorithm>
#include <cmath>
#include <iostream>

bool KriterijSortiranja(int n1, int n2) {
  int brojac1{0}, brojac2{0};
  if (n1 > 9 && n2 > 9) {
    for (int i{1}; i <= std::sqrt(n1); i++) {
      if (n1 % i == 0) {
        brojac1++;
      }
    }
    for (int i{1}; i <= std::sqrt(n2); i++) {
      if (n2 % i == 0) {
        brojac2++;
      }
    }
  } else {
    for (int i{1}; i <= n1; i++) {
      if (n1 % i == 0)
        brojac1++;
    }
    for (int i{1}; i <= n2; i++) {
      if (n2 % i == 0)
        brojac2++;
    }
  }
  //std::cout << n1 << " " << n2 << " " << brojac1 << " " << brojac2 << std::endl;
  if (brojac1 == brojac2)
    return n1 < n2;
  return brojac1 > brojac2;
}

void SortirajPoBrojuDjelilaca(int *niz, int n) {
  std::sort(niz, niz + n, KriterijSortiranja);
}
bool PretraziBinarno(int *niz, int n, int e){
 return std::binary_search(niz,niz+n, e);
}

int main() {
    int *p{nullptr};
  try {
    int n;
    std::cout << "Unesite broj elemenata niza: "<<std::endl;
    std::cin >> n;
    p = new int[n]{};
    std::cout << "Unesite elemente niza: "<<std::endl;
    for (int i{0}; i < n; i++) {
      std::cin >> p[i];
    }
    SortirajPoBrojuDjelilaca(p, n);
    std::cout << "Sortiran niz glasi: ";
    for (int i{0}; i < n; i++) {
      std::cout << p[i] << " ";
    }
    int e;
    std::cout<<std::endl;
    std::cout<<"Unesite element koji treba binarno pretraziti: "<<std::endl;
    std::cin>>e;
    if (PretraziBinarno(p,n,e))
        std::cout<<"Trazeni element se nalazi u nizu.";
    else 
        std::cout<<"Trazeni element se ne nalazi u nizu.";
  } catch (std::bad_alloc) {
    std::cout << "Problemi sa memorijom.";
    delete[] p;
  }
  delete[] p;
  return 0;
}