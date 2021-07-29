/*
    TP 16/17 (Tutorijal 11, Zadatak 1)
        Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: hhasic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
class NeobicnaKlasa {
  int a;

public:
  explicit NeobicnaKlasa(int b) {
    a = b;
    std::cout << "Direktna inicijalizacija" << std::endl;
  }
  NeobicnaKlasa(double c) {
    a = c;
    std::cout << "Kopirajuca inicijalizacija";
  }
};
int main() {
  NeobicnaKlasa k1(5);  // Proizvodi ispis "Direktna inicijalizacija"
  NeobicnaKlasa k2 = 5; // Proizvodi ispis "Kopirajuca inicijalizacija"

  return 0;
}