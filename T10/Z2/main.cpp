/*
    TP 16/17 (Tutorijal 10, Zadatak 2)
        Autotestove pisala Nina Slamnik. Za sva pitanja,
        sugestije i primjedbe poslati mail na:
        nslamnik1@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

const double pi{4 * std::atan(1)};

class Krug {
  double poluprecnik;

public:
  explicit Krug(double r) { Postavi(r); }
  void Postavi(double r) {
    if (r <= 0)
      throw std::domain_error("Neispravan poluprecnik");
    poluprecnik = r;
  }
  double DajPoluprecnik() const { return poluprecnik; }
  double DajPovrsinu() const { return poluprecnik * poluprecnik * pi; }
  double DajObim() const { return 2 * pi * poluprecnik; }
  void Skaliraj(double faktor_skaliranja) {
    if (faktor_skaliranja <= 0)
      throw std::domain_error("Neispravan faktor skaliranja");
    poluprecnik *= faktor_skaliranja;
  }
  void Ispisi() const;
};
class Valjak {
  Krug baza;
  double visina;

public:
  explicit Valjak(double b, double h) : baza(b) {
    if (h < 0)
      throw std::domain_error("Neispravna visina");
    visina = h;
  };
  void Postavi(double r_b, double h) {
    if (r_b < 0)
      throw std::domain_error("Neispravan poluprecnik");
    if (h < 0)
      throw std::domain_error("Neispravna visina");
    visina = h;
    baza.Postavi(r_b);
  }
  Krug DajBazu() const { return baza; }
  double DajPoluprecnikBaze() const { return baza.DajPoluprecnik(); }
  double DajVisinu() const { return visina; }
  double DajPovrsinu() const {
    return 2 * baza.DajPovrsinu() + visina * baza.DajObim();
  }
  double DajZapreminu() const { return baza.DajPovrsinu() * visina; }
  void Skaliraj(double faktor_skaliranja) {
    if (faktor_skaliranja <= 0)
      std::domain_error("Neispravan faktor skaliranja");
    baza.Skaliraj(faktor_skaliranja);
  }
  void Ispisi() const;
};
int main() { return 0; }

void Krug::Ispisi() const {
  std::cout << std::setprecision(5) << std::fixed << "R=" << DajPoluprecnik()
            << std::fixed << std::setprecision(5) << " O=" << DajObim()
            << " P=" << DajPovrsinu();
}
void Valjak::Ispisi() const {
  std::cout << "R=" << DajPoluprecnikBaze() << std::setprecision(5)
            << std::fixed << " H=" << DajVisinu() << " P=" << DajPovrsinu()
            << " V=" << DajZapreminu();
}