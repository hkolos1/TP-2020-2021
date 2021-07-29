/*
    TP 2018/2019: Tutorijal 5, Zadatak 5

        Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
        mozete slati na mail nslamnik1@etf.unsa.ba.

        NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
                          da se koristi indeksiranje niz[i] ili simulacija
   indeksiranja npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

                          To ce tutori rucno pregledati u toku tutorijala te ako
                          student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se
   da za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <cmath>
#include <iomanip>
#include <iostream>


void Clan(double (*F)(double), double a, double b, int k, int n, double &clan) {
  if (k >= n) {
    clan += 1. / 2 * F(a) + 1. / 2 * F(b);
    clan *= (b - a) / n;
    return;
  }
  clan += F(a + ((b - a) / double(n)) * k);
  Clan(F, a, b, ++k, n, clan);
}
double TrapeznoPravilo(double (*F)(double), double a, double b, int n) {
  double clan = 0;
  int k = 1;
  Clan(F, a, b, k, n, clan);
  return clan;
}
int main() {
  const double PI = 4 * std::atan(1);
  int podinterval;
  std::cout << "Unesite broj podintervala: ";
  std::cin >> podinterval;
  std::cout
      << "Za taj broj podintervala priblizne vrijednosti integrala iznose:"
      << std::endl;
  std::cout << "- Za funkciju sin x na intervalu (0,pi): " << std::fixed
            << std::setprecision(5)
            << TrapeznoPravilo(std::sin, 0, PI, podinterval) << std::endl;
  std::cout << "- Za funkciju x^3 na intervalu (0,10): " << std::fixed
            << std::setprecision(2)
            << TrapeznoPravilo([](double x) { return x * x * x; }, 0, 10,
                               podinterval)
            << std::endl;
  std::cout << "- Za funkciju 1/x na intervalu (1,2): " << std::fixed
            << std::setprecision(5)
            << TrapeznoPravilo([](double x) { return 1 / x; }, 1, 2,
                               podinterval);
  return 0;
}