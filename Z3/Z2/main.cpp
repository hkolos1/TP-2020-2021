// TP 2018/2019: Zadaća 3, Zadatak 2
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <vector>


typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool DaLiJeSlovo(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return true;
  return false;
}

bool VecIma(std::vector<std::string> v, std::string s) {
  for (int i{0}; i < v.size(); i++)
    if (v.at(i) == s)
      return true;
  return false;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>>
KreirajIndeksPojmova(Knjiga k) {
  std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa;
  std::vector<std::string> v;

  for (Knjiga::iterator it{k.begin()}; it != k.end(); it++) {
    std::vector<std::string> sadrzaj{it->second};
    std::set<std::tuple<std::string, int, int>> set;

    for (int i{0}; i < sadrzaj.size(); i++) {
      std::vector<std::string> rijeci;
      int sklj{0};
      for (int j{0}; j < sadrzaj.at(i).length(); j++) {
        std::string rijec{};
        while (j < sadrzaj.at(i).length() && DaLiJeSlovo(sadrzaj.at(i).at(j))) {
          rijec.push_back(sadrzaj.at(i).at(j));
          j++;
        }

        if (!VecIma(rijeci, rijec)) {
          rijeci.push_back(rijec);
          sklj++;
          for (int k{0}; k < sadrzaj.at(i).length(); k++) {
            std::string rijec2{};
            int duzina{0};
            while (k < sadrzaj.at(i).length() &&
                   DaLiJeSlovo(sadrzaj.at(i).at(k))) {
              rijec2.push_back(sadrzaj.at(i).at(k));
              k++;
              duzina++;
            }
            std::transform(rijec.begin(), rijec.end(), rijec.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            std::transform(rijec2.begin(), rijec2.end(), rijec2.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            if (rijec == rijec2) {
              set.insert(std::make_tuple(it->first, i + 1, k - duzina));
            }
          }

          auto temp{mapa.find(rijec)};
          if (temp == mapa.end()) {
            mapa.insert({rijec, set});
          } else {
            std::set<std::tuple<std::string, int, int>> temp1{temp->second};
            for (auto pom{set.begin()}; pom != set.end(); pom++) {
              temp1.insert(*pom);
            }
            temp->second = temp1;
          }
        }
        set.clear();
      }
    }
  }
  return mapa;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(
    std::string s,
    std::map<std::string, std::set<std::tuple<std::string, int, int>>>
        pojmovi) {
  if (!pojmovi.count(s)) {
    throw std::logic_error("Pojam nije nadjen.");
  }
  return pojmovi.at(s);
}

void IspisiIndeksPojmova(
    std::map<std::string, std::set<std::tuple<std::string, int, int>>>
        pojmovi) {
  for (std::map<std::string,
                std::set<std::tuple<std::string, int, int>>>::iterator it{
           pojmovi.begin()};
       it != pojmovi.end(); it++) {
    std::cout << it->first << ": ";
    for (std::set<std::tuple<std::string, int, int>>::iterator it1{
             it->second.begin()};
         it1 != it->second.end(); it1++) {
      if (std::next(it1) == it->second.end()) {
        std::cout << std::get<0>(*it1) << "/" << std::get<1>(*it1) << "/"
                  << std::get<2>(*it1);
      } else {
        std::cout << std::get<0>(*it1) << "/" << std::get<1>(*it1) << "/"
                  << std::get<2>(*it1) << ", ";
      }
    }
    std::cout << std::endl;
  }
}
int main() {
  std::vector<std::string> stranice;
  std::string naziv;
  Knjiga knjiga;
  while (naziv != ".") {
    std::cout << "Unesite naziv poglavlja: " << std::endl;
    std::getline(std::cin, naziv);
    if (naziv == ".")
      break;
    std::string stranica{};
    int i{1};
    while (stranica != ".") {
      std::cout << "Unesite sadrzaj stranice " << i << ": " << std::endl;
      std::getline(std::cin, stranica);
      if (stranica == ".")
        break;
      stranice.push_back(stranica);
      i++;
    }
    knjiga.insert({naziv, stranice});
  }
  std::map<std::string, std::set<std::tuple<std::string, int, int>>>
      indeks_pojmova{KreirajIndeksPojmova(knjiga)};
  std::cout << "Kreirani indeks pojmova: " << std::endl;
  IspisiIndeksPojmova(indeks_pojmova);
  std::string rijec1{};
  while (rijec1 != ".") {
    std::cout << "Unesite rijec: " << std::endl;
    std::getline(std::cin, rijec1);
    if (rijec1 == ".")
      break;
    try {
      std::set<std::tuple<std::string, int, int>> indeksi{
          PretraziIndeksPojmova(rijec1, indeks_pojmova)};
      int i{0};
      for (auto x : indeksi) {
        if (i == indeksi.size() - 1)
          std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/"
                    << std::get<2>(x);
        else
          std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/"
                    << std::get<2>(x) << ", ";
        i++;
      }
      std::cout << std::endl;
    } catch (std::logic_error e) {
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}