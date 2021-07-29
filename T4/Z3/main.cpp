// TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>


using Stringovi = std::vector<std::string>;
void PretvoriUMala(std::string &str) {
  for (char &s : str)
    if (s >= 'A' && s <= 'Z')
      s += 'a' - 'A';
}
void IzdvojiKrajnjeRijeci(const Stringovi &niz, std::string &prva,
                          std::string &zadnja) {
  if (!niz.size()) {
    prva = "";
    zadnja = "";
    return;
  }
  prva = "z";
  zadnja = "a";
  for (int i = 0; i < niz.size(); i++) {
    std::string tmp = niz.at(i);
    std::string tmpMin = prva;
    std::string tmpMax = zadnja;
    PretvoriUMala(tmp);
    PretvoriUMala(tmpMin);
    PretvoriUMala(tmpMax);
    if (tmp < tmpMin)
      prva = niz.at(i);
    if (tmp > tmpMax)
      zadnja = niz.at(i);
  }
}
void ZadrziDuplikate(Stringovi &stringovi) {
  std::vector<int> brojaci(stringovi.size());
  for (int i = 0; i < brojaci.size(); i++)
    for (int j = i + 1; j < brojaci.size(); j++)
      if (stringovi.at(i) == stringovi.at(j))
        brojaci.at(i)++;

  for (int i = 0; i < stringovi.size(); i++)
    if (brojaci.at(i) != 1) {
      for (int j = i; j < stringovi.size() - 1; j++) {
        stringovi.at(j) = stringovi.at(j + 1);
        brojaci.at(j) = brojaci.at(j + 1);
      }
      i--;
      stringovi.resize(stringovi.size() - 1);
    }
}

int main() {
  int brojRijeci;
  std::cout << "Koliko zelite unijeti rijeci: ";
  std::cin >> brojRijeci;
  std::cin.ignore(1000, 'n');
  Stringovi nizRijeci(brojRijeci);
  std::cout << "Unesite rijeci:" << std::endl;
  for (int i = 0; i < brojRijeci; i++)
    std::cin >> nizRijeci.at(i);
  std::string prva, posljednja;
  IzdvojiKrajnjeRijeci(nizRijeci, prva, posljednja);
  std::cout << "Prva rijec po abecednom poretku je: " << prva << std::endl;
  std::cout << "Posljednja rijec po abecednom poretku je: " << posljednja
            << std::endl;
  ZadrziDuplikate(nizRijeci);
  std::cout << "Rijeci koje se ponavljaju su: ";
  for (std::string &s : nizRijeci)
    std::cout << s << " ";

  return 0;
}