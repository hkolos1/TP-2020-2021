/*
    TP 2018/2019: Tutorijal 5, Zadatak 6

        Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
        mozete slati na mail nslamnik1@etf.unsa.ba.

        NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
                          da se koristi indeksiranje niz[i] ili simulacija
   indeksiranja npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

                          To ce tutori rucno pregledati u toku tutorijala te ako
                          student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se
   da za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <algorithm>
#include <iostream>
#include <vector>

void Suma(int &suma, int x) {
  if (x == 0)
    return;
  suma += std::abs(x % 10);
  Suma(suma, x /= 10);
}

bool SumaCifara(int x, int y) {
  int sumaX = 0, sumaY = 0;
  Suma(sumaX, x);
  Suma(sumaY, y);
  if(sumaX == sumaY)
  return x < y;
  return sumaX < sumaY;
}

int main() {
  int vel;
  std::cout << "Unesite broj elemenata: ";
  std::cin >> vel;
  std::vector<int> v(vel);
  std::cout << "Unesite elemente: ";
  std::for_each(v.begin(), v.end(), [](int &x) { std::cin >> x; });
  std::sort(v.begin(), v.end(),SumaCifara);
  std::cout<<"Niz sortiran po sumi cifara glasi: ";
  std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
  int broj;
  std::cout << std::endl << "Unesite broj koji trazite: ";
  std::cin >> broj;
  if (!std::binary_search(v.begin(), v.end(), broj, SumaCifara))
    std::cout << "Trazeni broj ne nalazi se u nizu!" << std::endl;
  else {
    std::vector<int>::iterator poz = std::find(v.begin(), v.end(), broj);
    std::cout << "Trazeni broj nalazi se na poziciji " << poz - v.begin();
  }
  return 0;
}