// TP 2018/2019: Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>

enum class Kriterij { Veca, Manja, Jednaka };

bool DaLiJeUVektoru(int broj, std::vector<int> v) {
  if (v.size() == 0)
    return true;
  for (int i{0}; i < v.size(); i++) {
    if (v.at(i) == broj) {
      return false;
    }
  }
  return true;
}

std::vector<int> IBSZMU(std::vector<int> vektor, int n, Kriterij kriterij) {
  std::vector<int> konacni;
  for (int i{0}; i < vektor.size(); i++) {
    int broj{vektor.at(i)};
    if (broj < 0)
      broj *= -1;
    int pro{1};
    int otpornost{1};
    if (broj == 1) {
      otpornost = 0;
    } else {
      while (broj != 0) {
        pro *= broj % 10;
        broj /= 10;
        if (broj == 0 && pro > 9) {
          otpornost++;
          broj = pro;
          pro = 1;
        }
      }
    }
    //std::cout << broj << " " << n << " " << otpornost << "\n";
    // std::cout << otpornost << std::endl;
    if (kriterij == Kriterij::Veca && otpornost > n &&
        DaLiJeUVektoru(vektor.at(i), konacni)) {
      konacni.push_back(vektor.at(i));
    } else if (kriterij == Kriterij::Manja && otpornost < n &&
               DaLiJeUVektoru(vektor.at(i), konacni)) {
      konacni.push_back(vektor.at(i));
    } else if (kriterij == Kriterij::Jednaka && otpornost == n &&
               DaLiJeUVektoru(vektor.at(i), konacni)) {
      konacni.push_back(vektor.at(i));
    }
  }
  return konacni;
}

int main() {
  std::vector<int> v;
  std::cout << "Unesite slijed brojeva (0 za kraj): ";
  while (1) {
    int broj;
    std::cin >> broj;
    if (broj == 0)
      break;
    else
      v.push_back(broj);
  }
  int mo;
  std::cout << "Unesite zeljeni prag za multiplikativnu otpornost: ";
  std::cin >> mo;
  std::cout << "\nBrojevi cija je multiplikativna otpornost manja od zadane: ";
  std::vector<int> temp;
  temp = IBSZMU(v, mo, Kriterij::Manja);
  if (temp.size() == 0) {
    std::cout << "Nema takvih brojeva";
  } else {
    for (int i{0}; i < temp.size(); i++)
      std::cout << temp.at(i) << " ";
  }
  std::cout << "\nBrojevi cija je multiplikativna otpornost veca od zadane: ";
  temp = IBSZMU(v, mo, Kriterij::Veca);
  if (temp.size() == 0) {
    std::cout << "Nema takvih brojeva";
  } else {
    for (int i{0}; i < temp.size(); i++)
      std::cout << temp.at(i) << " ";
  }
  std::cout << "\nBrojevi cija je multiplikativna otpornost jednaka zadanoj: ";
  temp = IBSZMU(v, mo, Kriterij::Jednaka);
  if (temp.size() == 0) {
    std::cout << "Nema takvih brojeva";
  } else {
    for (int i{0}; i < temp.size(); i++)
      std::cout << temp.at(i) << " ";
  }
  return 0;
}