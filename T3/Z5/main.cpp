// TP 2018/2019: Tutorijal 3, Zadatak 5
#include <deque>
#include <iostream>
#include <limits>

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

std::deque<int> IzdvojiElemente(std::deque<int> v, bool l_vrijednosti) {
  std::deque<int> izdvojeni_elementi;
  for (int i=v.size()-1; i>=0; i--) {
    if (DaLiJeSumaParna(v.at(i)) && l_vrijednosti) {
      izdvojeni_elementi.push_front(v.at(i));
    } else if (!DaLiJeSumaParna(v.at(i)) && !l_vrijednosti) {
      izdvojeni_elementi.push_front(v.at(i));
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
  std::deque<int> elementi;
  std::cout << "Unesite elemente: ";
  for (int i{0}; i < broj_elemenata; i++) {
    std::cin >> element;
    elementi.push_back(element);
  }
  std::deque<int> parni{IzdvojiElemente(elementi, true)};
  std::deque<int> neparni{IzdvojiElemente(elementi, false)};

  for (int i{0}; i < parni.size(); i++) {
    if (i == parni.size() - 1) {
      std::cout << parni.at(i) << std::endl;
    } else {
      std::cout << parni.at(i) << ",";
    }
  }
  if (parni.size() == 0)
    std::cout << std::endl;

  for (int i{0}; i < neparni.size(); i++) {
    if (i == neparni.size() - 1) {
      std::cout << neparni.at(i) << std::endl;
    } else {
      std::cout << neparni.at(i) << ",";
    }
  }

  return 0;
}