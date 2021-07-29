/*
    TP 2018/2019: Tutorijal 5, Zadatak 2

        Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
        mozete slati na mail nslamnik1@etf.unsa.ba.

        NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
                          da se koristi indeksiranje niz[i] ili simulacija
   indeksiranja npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

                          To ce tutori rucno pregledati u toku tutorijala te ako
                          student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se
   da za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <vector>
template <typename IterTip1, typename IterTip2>
IterTip2 RazmijeniBlokove(IterTip1 pocetak, IterTip1 kraj, IterTip2 odrediste) {
  while (pocetak != kraj) {
    auto tmp = *pocetak;
    *pocetak = *odrediste;
    *odrediste = tmp;
    pocetak++;
    odrediste++;
  }
  return odrediste;
}
int main() {
  int n1;
  std::cout << "Unesite broj elemenata prvog niza: ";
  std::cin >> n1;
  std::vector<double> v1(n1);
  std::cout << "Unesite elemente prvog niza: ";
  for (int i = 0; i < n1; i++)
    std::cin >> v1.at(i);

  int n2;
  std::cout << "Unesite broj elemenata prvog niza: ";
  std::cin >> n2;
  std::vector<double> v2(n2);
  std::cout << "Unesite elemente prvog niza: ";
  for (int i = 0; i < n2; i++)
    std::cin >> v2.at(i);

  std::vector<double>::iterator v1Begin = v1.begin();
  std::vector<double>::iterator v2Begin = v2.begin();
  std::vector<double>::iterator v1End = v1.end();
  std::vector<double>::iterator v2End =
      RazmijeniBlokove(v1Begin, v1End, v2Begin);
  std::cout << "Funkcija \"RazmijeniBlokove\" razmijenjuje dva bloka!"
            << std::endl;
  std::cout << "Prvi niz glasi: ";
  while (v1Begin != v1End) {
    std::cout << *v1Begin << " ";
    v1Begin++;
  }
  std::cout << std::endl << "Drugi niz glasi: ";
  while (v2Begin != v2End) {
    std::cout << *v2Begin << " ";
    v2Begin++;
  }

  return 0;
}