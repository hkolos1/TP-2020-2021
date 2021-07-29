/*
    TP 16/17 (Tutorijal 11, Zadatak 3)
        Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: hhasic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Tim {
  char imeTima[20];
  int brOdigranih, brPobjeda, brNerijesenih, brPoraza, brDatih, brPrimljenih,
      brPoena;

public:
  Tim(const char *ime);
  void ObradiUtakmicu(int brojDatih, int brojPrimljenih);
  const char *DajImeTima() const { return imeTima; }
  int DajBrojPoena() const { return brPoena; }
  int DajGolRazliku() const { return brDatih - brPrimljenih; }
  void IspisiPodatke() const {
    std::cout << std::left << std::setw(20) << imeTima << std::right
              << std::setw(4) << brOdigranih << std::setw(4) << brPobjeda
              << std::setw(4) << brNerijesenih << std::setw(4) << brPoraza
              << std::setw(4) << brDatih << std::setw(4) << brPrimljenih
              << std::setw(4) << brPoena << std::endl;
  }
};

Tim::Tim(const char *ime)
    : brOdigranih(0), brPobjeda(0), brNerijesenih(0), brPoraza(0), brDatih(0),
      brPrimljenih(0), brPoena(0) {
  int velicina = 0;
  for (int i = 0; ime[i] != '\0'; i++)
    velicina++;
  if (velicina > 19)
    throw std::range_error("Predugacko ime tima");
  std::strcpy(imeTima, ime);
}

void Tim::ObradiUtakmicu(int brojDatih, int brojPrimljenih) {
  if (brojDatih < 0 || brojPrimljenih < 0)
    throw std::range_error("Neispravan broj golova");
  brOdigranih++;
  brDatih += brojDatih;
  brPrimljenih += brojPrimljenih;
  if (brojDatih > brojPrimljenih) {
    brPobjeda++;
    brPoena += 3;
  } else if (brojDatih == brojPrimljenih) {
    brNerijesenih++;
    brPoena += 1;
  } else
    brPoraza++;
}

int main() {
  /* Tim t1("NK Zeljeznicar");
   Tim t2("FK Sarajevo");
   Tim t3("HSK Zrinjski");

   t1.ObradiUtakmicu(1, 0);
   t1.ObradiUtakmicu(3, 0);
   t1.ObradiUtakmicu(2, 1);
   t2.ObradiUtakmicu(1, 1);
   t2.ObradiUtakmicu(1, 0);
   t2.ObradiUtakmicu(0, 5);
   t3.ObradiUtakmicu(0, 1);
   t3.ObradiUtakmicu(0, 2);
   t3.ObradiUtakmicu(1, 1);

   t1.IspisiPodatke();
   t2.IspisiPodatke();
   t3.IspisiPodatke();*/
  return 0;
}