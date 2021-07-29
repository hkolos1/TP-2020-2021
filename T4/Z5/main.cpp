// TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
template <typename NekiTip>
std::vector<NekiTip> Presjek(std::vector<NekiTip> v1, std::vector<NekiTip> v2) {
  std::vector<NekiTip> presjek;
  bool jesu_li_jednaki{true};
  for (NekiTip x : v1) {
    for (NekiTip y : v2) {
      if (x == y) {
        jesu_li_jednaki = true;
        for (NekiTip z : presjek) {
          if (x == z) {
            jesu_li_jednaki = false;
          }
        }
        if (jesu_li_jednaki) {
          presjek.push_back(x);
        }
      }
    }
  }
  return presjek;
}
int main() {
  std::cout << "Test za realne brojeve..." << std :: endl;
  int n1;
  std::cout << "Unesite broj elemenata prvog vektora: ";
  std::cin >> n1;
  std::cout << "Unesite elemente prvog vektora: ";
  std::vector<int> v1 (n1);
  for (int i{0}; i < n1; i++)
    std::cin >> v1.at(i);

    int n2;
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>n2;
    std::cout<<"Unesite elemente drugog vektora: ";
    std::vector<int>v2(n2);
    for(int i{0}; i<n2; i++){
        std::cin>>v2.at(i);
    }
    std::cout<<"Zajednicki elementi su: ";
    std::vector<int> zajednicki{Presjek(v1, v2)};
    for(int i{0}; i<zajednicki.size(); i++)
    std::cout<<zajednicki.at(i)<<" ";
/*Test za realne brojeve..
Unesite broj elemenata drugog vektora
Unesite elemente drugog vektora
Zajednicki elementu su */

  return 0;
}