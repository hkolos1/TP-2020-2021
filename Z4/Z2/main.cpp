// TP 2018/2019: Zadaća 4, Zadatak 2
#include <cmath>
#include <iostream>

class GradjaninBiH {
  std::string ime;
  long long int JMBG;
  GradjaninBiH *prethodni;
  static GradjaninBiH *posljednji;

public:
  enum Pol { Musko, Zensko };
  GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
  GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
               int godina_rodjenja, int sifra_regije, Pol pol);
  GradjaninBiH(const GradjaninBiH &g) = delete;
  GradjaninBiH operator=(const GradjaninBiH &g) = delete;
  std::string DajImeIPrezime() const { return ime; }
  long long int DajJMBG() const { return JMBG; }
  int DajDanRodjenja() const;
  int DajMjesecRodjenja() const;
  int DajGodinuRodjenja() const;
  int DajSifruRegije() const;
  Pol DajPol() const;
  void PromijeniImeIPrezime(std::string novo_ime) { ime = novo_ime; }
};
GradjaninBiH *GradjaninBiH::posljednji = nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
  auto jmbg_copy = jmbg;
  int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
  for (int i = 0; i < 13; i++) {
    if (i == 0)
      c13 = jmbg_copy % 10;
    else if (i == 1)
      c12 = jmbg_copy % 10;
    else if (i == 2)
      c11 = jmbg_copy % 10;
    else if (i == 3)
      c10 = jmbg_copy % 10;
    else if (i == 4)
      c9 = jmbg_copy % 10;
    else if (i == 5)
      c8 = jmbg_copy % 10;
    else if (i == 6)
      c7 = jmbg_copy % 10;
    else if (i == 7)
      c6 = jmbg_copy % 10;
    else if (i == 8)
      c5 = jmbg_copy % 10;
    else if (i == 9)
      c4 = jmbg_copy % 10;
    else if (i == 10)
      c3 = jmbg_copy % 10;
    else if (i == 11)
      c2 = jmbg_copy % 10;
    else if (i == 12)
      c1 = jmbg_copy % 10;
    jmbg_copy /= 10;
  }
  int dan = c1 * 10 + c2;
  int mjesec = c3 * 10 + c4;
  int godina = c5 * 100 + c6 * 10 + c7;
  if (godina >= 917)
    godina += 1000;
  else
    godina += 2000;
  int c = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) +
                3 * (c5 + c11) + 2 * (c6 + c12)) %
                   11;
  if (c == 11)
    c = 0;
  if (c13 != c)
    throw std::logic_error("JMBG nije validan");
  int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
    broj_dana[1]++;
  if (godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 ||
      dan > broj_dana[mjesec - 1])
    throw std::logic_error("JMBG nije validan");
  auto zadnji = posljednji;
  while (zadnji != nullptr) {
    if ((*zadnji).JMBG == jmbg_copy)
      throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    zadnji = (*zadnji).prethodni;
  }
  ime = ime_i_prezime;
  JMBG = jmbg;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja,
                           int mjesec_rodjenja, int godina_rodjenja,
                           int sifra_regije, Pol pol) {
  if (godina_rodjenja < 1921 || godina_rodjenja > 2021 || mjesec_rodjenja < 1 ||
      mjesec_rodjenja > 12 || dan_rodjenja < 1 || dan_rodjenja > 31 ||
      sifra_regije < 0 || sifra_regije > 99)
    throw std::logic_error("Neispravni podaci");
  int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 ||
      godina_rodjenja % 400 == 0)
    broj_dana[1]++;

  ime = ime_i_prezime;
  JMBG = dan_rodjenja * pow(10, 11) + mjesec_rodjenja * pow(10, 9) +
         (godina_rodjenja % 1000) * pow(10, 6) + sifra_regije * 10000;
  int kod = 0;
  if (pol == GradjaninBiH::Pol::Zensko)
    kod = 500;
  auto zadnji = posljednji;
  auto jmbg_copy = JMBG;
  int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
  if (zadnji == nullptr) {
    c10 = kod / 100;
    c11 = (kod % 100) / 10;
    c12 = kod % 10;
    for (int i = 0; i < 13; i++) {
      if (i == 4)
        c9 = jmbg_copy % 10;
      else if (i == 5)
        c8 = jmbg_copy % 10;
      else if (i == 6)
        c7 = jmbg_copy % 10;
      else if (i == 7)
        c6 = jmbg_copy % 10;
      else if (i == 8)
        c5 = jmbg_copy % 10;
      else if (i == 9)
        c4 = jmbg_copy % 10;
      else if (i == 10)
        c3 = jmbg_copy % 10;
      else if (i == 11)
        c2 = jmbg_copy % 10;
      else if (i == 12)
        c1 = jmbg_copy % 10;
      jmbg_copy /= 10;
    }
    c13 = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) +
                3 * (c5 + c11) + 2 * (c6 + c12)) %
                   11;
    if (c13 == 11)
      c13 = 0;
  }
  while (zadnji != nullptr) {
    c10 = kod / 100;
    c11 = (kod % 100) / 10;
    c12 = kod % 10;
    for (int i = 0; i < 13; i++) {
      if (i == 4)
        c9 = jmbg_copy % 10;
      else if (i == 5)
        c8 = jmbg_copy % 10;
      else if (i == 6)
        c7 = jmbg_copy % 10;
      else if (i == 7)
        c6 = jmbg_copy % 10;
      else if (i == 8)
        c5 = jmbg_copy % 10;
      else if (i == 9)
        c4 = jmbg_copy % 10;
      else if (i == 10)
        c3 = jmbg_copy % 10;
      else if (i == 11)
        c2 = jmbg_copy % 10;
      else if (i == 12)
        c1 = jmbg_copy % 10;
      jmbg_copy /= 10;
    }
    c13 = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) +
                3 * (c5 + c11) + 2 * (c6 + c12)) %
                   11;
    if (c13 == 11)
      c13 = 0;
    else if (c13 == 10) {
      kod++;
      zadnji = posljednji;
      continue;
    }
    if ((*zadnji).JMBG == JMBG + kod * 10 + c13) {
      kod++;
      zadnji = posljednji;
      continue;
    }
    zadnji = (*zadnji).prethodni;
  }
  JMBG += kod * 10 + c13;
}
int GradjaninBiH::DajDanRodjenja() const { return JMBG / pow(10, 11); }
int GradjaninBiH::DajMjesecRodjenja() const {
  return (JMBG / (long long int)(pow(10, 9))) % 100;
}
int GradjaninBiH::DajGodinuRodjenja() const {
  int godina = (JMBG / (long long int)(pow(10, 6))) % 1000;
  if (godina >= 917)
    godina += 1000;
  else
    godina += 2000;
  return godina;
}
int GradjaninBiH::DajSifruRegije() const {
  auto jmbg_copy = JMBG;
  int c9, c8;
  for (int i = 0; i < 6; i++) {
    if (i == 4)
      c9 = jmbg_copy % 10;
    else if (i == 5)
      c8 = jmbg_copy % 10;
    jmbg_copy /= 10;
  }
  return c8 * 10 + c9;
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const {
  if ((JMBG % 10000) / 10 < 500)
    return GradjaninBiH::Pol::Musko;
  else
    return GradjaninBiH::Pol::Zensko;
}
int main() {
  std::cout << "Unesite broj gradjana koje zelite unijeti po JMBG: "
            << std::endl;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "Unos podataka za " << i + 1 << ". gradjanina" << std::endl;
    std::cout << "Unesite ime i prezime (u istom redu): ";
    std::string ime_i_prezime;
    std::cin.ignore(10000, '\n');
    std::cin.clear();
    std::getline(std::cin, ime_i_prezime);
    std::cout << "Unesite JMBG: ";
    long long int jmbg;
    std::cin >> jmbg;
    try {
      GradjaninBiH g(ime_i_prezime, jmbg);
      std::cout << "Ime i prezime: " << g.DajImeIPrezime()
                << ", JMBG: " << g.DajJMBG() << std::endl;
      std::cout << std::endl;
    } catch (std::logic_error e) {
      std::cout << e.what() << std::endl;
      i--;
    }
  }
  int pokupi = n;
  std::cout << "Unesite broj gradjana koje zelite unijeti po datumu rodjenja, "
               "regiji i polu: "
            << std::endl;
  int m;
  std::cin >> m;
  for (int i = 0 + pokupi; i < m + pokupi; i++) {
    std::cout << "Unos podataka za " << i + 1 << ". gradjanina" << std::endl;
    std::cout << "Unesite ime i prezime (u istom redu): ";
    std::cin.ignore(10000, '\n');
    std::cin.clear();
    std::string ime_i_prezime;
    std::getline(std::cin, ime_i_prezime);
    std::cout << "Unesite datum rodjenja(format dd/mm/gggg): ";
    int dan, mjesec, godina;
    char crta;
    std::cin >> dan >> crta >> mjesec >> crta >> godina;
    std::cout << "Unesite sifru regije: ";
    int regija;
    std::cin >> regija;
    std::cout << "Unesite M za musko, Z za zensko: ";
    char znak;
    std::cin >> znak;
    GradjaninBiH::Pol pol;
    if (znak == 'M')
      pol = GradjaninBiH::Pol::Musko;
    else if (znak == 'Z')
      pol = GradjaninBiH::Pol::Zensko;
    try {
      GradjaninBiH g(ime_i_prezime, dan, mjesec, godina, regija, pol);
      std::cout << "Ime i prezime: " << g.DajImeIPrezime()
                << ", JMBG: " << g.DajJMBG() << std::endl;
    } catch (std::logic_error e) {
      std::cout << e.what() << std::endl;
      i--;
    }
  }
  return 0;
}