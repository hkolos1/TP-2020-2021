/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
        Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: hhasic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
class StedniRacun {
  double stanje_racuna;
  static int kreiranih;
  static int aktivnih;

public:
  StedniRacun(double s_r = 0) {
    if (s_r < 0)
      throw std::logic_error("Nedozvoljeno pocetno stanje");
    stanje_racuna = s_r;
    kreiranih++;
    aktivnih++;
  }
  StedniRacun(const StedniRacun &s_r) {
    if (s_r.stanje_racuna < 0)
      throw std::logic_error("Nedozvoljeno pocetno stanje");
    stanje_racuna = s_r.stanje_racuna;
    kreiranih++;
    aktivnih++;
  }
  ~StedniRacun() { aktivnih--; }
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
  static int DajBrojKreiranih() { return kreiranih; }
  static int DajBrojAktivnih() { return aktivnih; }
};
int StedniRacun::aktivnih = 0;
int StedniRacun::kreiranih = 0;
int main() { return 0; }
