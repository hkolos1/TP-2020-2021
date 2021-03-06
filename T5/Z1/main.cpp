/*
    TP 2018/2019: Tutorijal 5, Zadatak 1

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
int main() {
  char recenica[1000];
  std::cout << "Unesite recenicu: ";
  std::cin.getline(recenica, sizeof recenica);
  char *pokNaRecenicu = recenica;
  bool razmak = true;
  while (*pokNaRecenicu != '\0') {
    if (*pokNaRecenicu == ' ') {
      razmak = true;
      while (*pokNaRecenicu == ' ') {
        char *tmp = pokNaRecenicu;
        while (*tmp != '\0') {
          *tmp = *(tmp + 1);
          tmp++;
        }
      }
    } else if (razmak) {
      razmak = false;
      while (*pokNaRecenicu != ' ' && *pokNaRecenicu != '\0') {
        char *tmp = pokNaRecenicu;
        while (*tmp != '\0') {
          *tmp = *(tmp + 1);
          tmp++;
        }
      }
    }
    if (!razmak)
      break;
  }
  while (*pokNaRecenicu == ' ') {
    char *tmp = pokNaRecenicu;
    while (*tmp != '\0') {
      *tmp = *(tmp + 1);
      tmp++;
    }
  }
  std::cout << "Recenica bez prve rijeci glasi: " << recenica << std::endl;
  return 0;
}