/*
    TP 16/17 (Tutorijal 10, Zadatak 1)
        Autotestove pisala Nina Slamnik. Za sva pitanja,
        sugestije i primjedbe poslati mail na:
        nslamnik1@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun {
  double stanje_racuna;

public:
  StedniRacun(double s_r = 0) {
    if (s_r < 0)
      throw std::logic_error("Nedozvoljeno pocetno stanje");
    stanje_racuna = s_r;
  }
  void Ulozi(double x) {
    if ((x * (-1)) > stanje_racuna)
      throw std::logic_error("Transakcija odbijena");
    stanje_racuna += x;
  }
  void Podigni(double x) {
    if (x > stanje_racuna)
      throw std::logic_error("Transakcija odbijena");
    stanje_racuna -= x;
  }
  double DajStanje() const { return stanje_racuna; }
  void ObracunajKamatu(double k) {
    if (k < 0)
      throw std::logic_error("Nedozvoljena kamatna stopa");
    stanje_racuna += k / 100 * stanje_racuna;
  }
};
int main() { return 0; }