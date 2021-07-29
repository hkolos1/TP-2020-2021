// TP 2018/2019: Tutorijal 3, Zadatak 8
#include <iostream>
#include <stdexcept>
#include <string>

std::string IzdvojiRijec(std::string recenica, int n) {
  if (n < 0)
    throw std::domain_error("Pogresan redni broj rijeci!");
  std::string rijec;
  int raz{1}, br_rijeci{0};
  for (int i{0}; i < recenica.length(); i++) {
    if (recenica.at(i) == ' ')
      raz = 1;
    else if (raz == 1) {
      raz = 0;
      br_rijeci++;
    }
    if (br_rijeci == n) {
      while (i < recenica.length() && recenica.at(i) != ' ') {
        rijec.push_back(recenica.at(i));
        i++;
      }
      break;
    }
  }
  if (br_rijeci < n)
    throw std::domain_error("Pogresan redni broj rijeci!");
  return rijec;
}

int main() {
  try {
    int n;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::string recenica;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::string rijec{IzdvojiRijec(recenica, n)};
    std::cout << "Rijec na poziciji " << n << " je " << rijec;
  } catch (std::domain_error izuzetak) {
    std::cout << "IZUZETAK: " << izuzetak.what();
  }

  return 0;
}