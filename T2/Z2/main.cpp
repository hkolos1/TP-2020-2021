// TP 2020/2021: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

/*Funkcija koja provjerava broj perioda*/
bool TestPerioda(std::vector<double> v, int p) {
  bool dali{true};
  if (v.size() == 1 || p >= v.size()) {
    return false;
  }
  for (int i = 0; i < int(v.size() - p); i++) {
    if (v.at(i) != v.at(p + i)) {
      dali = false;
      break;
    }
  }
  return dali;
}
/*Funkcija za pronalazak broja perioda*/
int OdrediOsnovniPeriod(std::vector<double> v) {
  int period{0};
  for (int i = 1; i < v.size(); i++) {
    if (TestPerioda(v, i)) {
      period = i;
      break;
    }
  }
  return period;
}

int main() {
  std::vector<double> v;
  std::cout << "Unesite slijed brojeva (0 za kraj): ";
  double broj;
  for (;;) {
    std::cin >> broj;
    if (broj == 0) {
      break;
    }
    v.push_back(broj);
  }
  int period{OdrediOsnovniPeriod(v)};
  if (period == 0) {
    std::cout << "Slijed nije periodican!";
  } else {
    std::cout << "Slijed je periodican sa osnovnim periodom " << period << ".";
  }

  return 0;
}
