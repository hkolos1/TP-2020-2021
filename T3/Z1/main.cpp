// TP 2018/2019: Tutorijal 3, Zadatak 1
#include <iostream>
#include <vector>

bool DaLiJeSumaParna(int broj) {
  int suma{0};
  while (broj != 0) {
    suma += broj % 10;
    broj /= 10;
  }
  if (suma % 2 == 0)
    return true;
  else
    return false;
}

std::vector<int> IzdvojiElemente(std::vector<int> v, bool l_vrijednosti) {
  std::vector<int> izdvojeni_elementi;
  for (int element : v) {
    if (DaLiJeSumaParna(element) && l_vrijednosti) {
      izdvojeni_elementi.push_back(element);
    } else if (!DaLiJeSumaParna(element) && !l_vrijednosti) {
      izdvojeni_elementi.push_back(element);
    }
  }
  return izdvojeni_elementi;
}

int main() {
  int broj_elemenata{0}, element;
  std::cout << "Koliko zelite unijeti elemenata: ";
  std::cin >> broj_elemenata;
  if (broj_elemenata == 0) {
    std::cout << "Broj elemenata mora biti veci od 0!";
    return 0;
  }
  std::vector<int> elementi;
  std::cout << "Unesite elemente: ";
  for (int i{0}; i < broj_elemenata; i++) {
    std::cin >> element;
    elementi.push_back(element);
  }
  std::vector<int> parni{IzdvojiElemente(elementi, true)};
  std::vector<int> neparni{IzdvojiElemente(elementi, false)};

  for (int e : parni)
    std::cout << e << " ";
  std::cout << std::endl;

  for (int e : neparni)
    std::cout << e << " ";
  std::cout << std::endl;

  return 0;
}