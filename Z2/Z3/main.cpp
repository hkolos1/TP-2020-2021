// TP 2018/2019: Zadaća 2, Zadatak 3
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

template <typename nekiTip1, typename nekiTip2, typename nekiTip3>
nekiTip3 ZajednickiElementiBlokova(nekiTip1 p1, nekiTip1 p2, nekiTip2 p3,
                                   nekiTip2 p4, nekiTip3 p5) {
  nekiTip1 poc1{p1};
  nekiTip2 poc2{p3};
  nekiTip3 poc3{p5};
  nekiTip3 kraj{p5};
  while (poc1 != p2) {
    poc2 = p3;
    while (poc2 != p4) {
      poc3 = p5;
      if (*poc2 == *poc1) {
        while (poc3 != kraj) {
          if (*poc3 == *poc1)
            break;
          poc3++;
        }
        if (poc3 == kraj) {
          *poc3 = *poc1;
          kraj++;
        }
      }
      poc2++;
    }
    poc1++;
  }
  return kraj;
}
int main() {
  int n;
  std::cout << "Unesi broj elemenata niza (ne vise od 100): " << std::endl;
  std::cin >> n;
  int niz[100];
  std::cout << "Unesi elemente niza: " << std::endl;
  for (int i{0}; i < n; i++) {
    std::cin >> niz[i];
  }
  std::deque<int> d;
  int n2;
  std::cout << "Unesi broj elemenata deka: " << std::endl;
  std::cin >> n2;
  int broj;
  std::cout<<"Unesi elemente deka: "<<std::endl;
  for (int i{0}; i < n2; i++) {
    std::cin >> broj;
    d.push_back(broj);
  }
  std::vector<int> v(100);
  auto p =
      ZajednickiElementiBlokova(niz, niz + n, d.begin(), d.end(), v.begin());
  int a{p - v.begin()};
  std::cout << "Vektor zajednickih elemenata niza i deka ima " << a
            << " elemenata" << std::endl;
  std::cout << "Zajednicki elementi glase: ";
  for (int i{0}; i < a; i++) {
    std::cout << v.at(i) << " ";
  }
  return 0;
}