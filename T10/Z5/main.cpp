/* 
    TP 16/17 (Tutorijal 10, Zadatak 5)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iomanip>
#include <iostream>

const double pi = 4 * std::atan(1);
class Ugao {
  double ugaoRad;

public:
  Ugao(double radijani);
  Ugao(int stepeni, int minute, int sekunde);
  void Postavi(double radijani);
  void Postavi(int stepeni, int minute, int sekunde);
  double DajRadijane() const { return ugaoRad; }
  void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde) const;
  int DajStepene() const { return int(DajRadijane() * 180 / pi); }
  int DajMinute() const {
    return int(((DajRadijane() * 180 / pi) - DajStepene()) * 60);
  }
  int DajSekunde() const {
    return ((DajRadijane() * 180 / pi) - DajStepene() - DajMinute() / 60) *
           3600;
  }
  void Ispisi() const {
    std::cout << std::fixed << std::setprecision(5) << ugaoRad;
  }
  void IspisiKlasicno() const {
    std::cout << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde()
              << "sec";
  }
  Ugao &SaberiSa(Ugao u) {
    ugaoRad += u.ugaoRad;
    return *this;
  }
  Ugao &PomnoziSa(Ugao u) {
    ugaoRad *= u.ugaoRad;
    return *this;
  }
  friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
  friend Ugao ProduktUglaSaBrojem(double broj);
};

Ugao::Ugao(double radijani = 0) {
	if (radijani < 0) {
		radijani = std::abs(radijani); 
		if (radijani > 2 * pi)
			while (radijani -= 2 * pi, radijani > 2 * pi); 
		ugaoRad = 2 * pi - radijani; 
	} else if (radijani > 2 * pi) {
		while (radijani -= 2 * pi, radijani > 2 * pi);
		ugaoRad = radijani;
	} else 
		ugaoRad = radijani; 
}

Ugao::Ugao(int stepeni, int minute, int sekunde) {
  double radijani = ((stepeni + (minute / 60.) + (sekunde / 3600.)) * pi) / 180;
  if (radijani < 0) {
    radijani = std::abs(radijani);
    if (radijani > 2 * pi)
      while (radijani -= 2 * pi, radijani > 2 * pi)
        ;
    ugaoRad = 2 * pi - radijani;
  } else if (radijani > 2 * pi) {
    while (radijani -= 2 * pi, radijani > 2 * pi)
      ;
    ugaoRad = radijani;
  } else
    ugaoRad = radijani;
}
void Ugao::Postavi(double radijani = 0) {
  if (radijani < 0) {
    radijani = std::abs(radijani);
    if (radijani > 2 * pi)
      while (radijani -= 2 * pi, radijani > 2 * pi)
        ;
    ugaoRad = 2 * pi - radijani;
  } else if (radijani > 2 * pi) {
    while (radijani -= 2 * pi, radijani > 2 * pi)
      ;
    ugaoRad = radijani;
  } else
    ugaoRad = radijani;
}
void Ugao::Postavi(int stepeni, int minute, int sekunde) {
  double radijani = ((stepeni + (minute / 60.) + (sekunde / 3600.)) * pi) / 180;
  if (radijani < 0) {
    radijani = std::abs(radijani);
    if (radijani > 2 * pi)
      while (radijani -= 2 * pi, radijani > 2 * pi)
        ;
    ugaoRad = 2 * pi - radijani;
  } else if (radijani > 2 * pi) {
    while (radijani -= 2 * pi, radijani > 2 * pi)
      ;
    ugaoRad = radijani;
  } else
    ugaoRad = radijani;
}
void Ugao::OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde ) const{
    long double decStepeni =ugaoRad*180/pi;
    stepeni=int(decStepeni);
    decStepeni -= stepeni;
    minute = int(decStepeni*60);
    decStepeni *=60; decStepeni -=minute;
    sekunde = int(decStepeni *60);

}
Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
    return u1.ugaoRad + u2.ugaoRad;
}
int main() { 
    Ugao u(90, 0, 0), v(180, 0, 0), f(90, 0, 0);
    u=ZbirUglova(u, v);
	u.IspisiKlasicno(); std::cout << std::endl;
	ZbirUglova(u, f).IspisiKlasicno(); std::cout << std::endl;
	u=ZbirUglova(u, 90);
	u.IspisiKlasicno(); std::cout << std::endl;
	return 0;
 }