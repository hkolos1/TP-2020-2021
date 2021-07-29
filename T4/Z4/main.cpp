// TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
template <typename NekiTip>
void UnosBroja(std::string s1, std::string s2, NekiTip &broj) {
  NekiTip unos;
  std::cout << s1;
  std::cin >> unos;
  while (!std::cin) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << s2 << std::endl;
    std::cout << s1;
    std::cin >> unos;
  }
  broj = unos;
}
double Eksponent(double baza, int eksponent) {
  for (int i{0}; i < eksponent; i++) {
    baza *= baza;
  }
  return baza;
}
int main() {
  double baza;
  UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", baza);
  int eksponent;
  UnosBroja("Unesite cjelobrojni eksponent: ",
            "Neispravan unos, pokusajte ponovo...", eksponent);
  std::cout << baza << " na " << eksponent << " iznosi "
            << Eksponent(baza, eksponent);
  return 0;
}