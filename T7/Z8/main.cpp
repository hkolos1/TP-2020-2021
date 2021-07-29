/*
    TP 16/17 (Tutorijal 7, Zadatak 8)
        Autotestove pisao Elmir Hodzic. Sva pitanja,
        prijave gresaka i sugestije slati na mail
        ehodzic3@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

std::string IzvrniBezRazmaka(std::string s) {
  std::string bezRazmaka;
  std::remove_copy(s.rbegin(), s.rend(), std::back_inserter(bezRazmaka), ' ');
  return bezRazmaka;
}
int main() {
  std::string recenica;
  std::cout << "Unesite recenicu: ";
  std::getline(std::cin, recenica);
  std::cout << "Izvrnuta bez razmaka recenica glasi: "
            << IzvrniBezRazmaka(recenica) << std::endl;
  return 0;
}