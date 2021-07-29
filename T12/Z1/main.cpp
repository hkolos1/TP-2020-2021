/*
    TP 16/17 (LV 12, Zadatak 1)
        Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: khodzic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class Sat {
  int sati, minute, sekunde;

public:
  static bool DaLiJeIspravno(int sati, int minute, int sekunde) {
    if (sati > 23 || sati < 0 || minute > 59 || minute < 0 || sekunde > 59 ||
        sekunde < 0)
      return false;
    return true;
  }
  void Postavi(int sati, int minute, int sekunde) {
    if (!DaLiJeIspravno(sati, minute, sekunde))
      throw std::domain_error("Neispravno vrijeme");
    Sat::sati = sati;
    Sat::minute = minute;
    Sat::sekunde = sekunde;
  }
  void PostaviNormalizirano(int sati, int minute, int sekunde);
  Sat &Sljedeci();
  Sat &Prethodni();
  Sat &PomjeriZa(int b);
  int DajSate() const { return sati; }
  int DajMinute() const { return minute; }
  int DajSekunde() const { return sekunde; }
  friend int BrojSekundiIzmedju(Sat s1, Sat s2);
  static int Razmak(Sat s1, Sat s2) {
    return ((s1.sati * 3600 + s1.minute * 60 + s1.sekunde) -
            (s2.sati * 3600 + s2.minute * 60 + s2.sekunde));
  }
  void Ispisi() const;
};
void Sat::PostaviNormalizirano(int sati, int minute, int sekunde) {
  int ukupne_sekunde{0};
  if (sati < 0 || minute < 0 || sekunde < 0) {
    ukupne_sekunde = 86400;
    int pomocna{3600 * sati + minute * 60 + sekunde};
    ukupne_sekunde += pomocna;
    while (ukupne_sekunde < 0)
      ukupne_sekunde += 86400;
    sati = ukupne_sekunde / 3600;
    while (sati > 24)
      sati -= 24;
    minute = (ukupne_sekunde % 3600) / 60;
    sekunde = ukupne_sekunde % 60;
    if (sekunde == 60) {
      sekunde = 0;
      minute++;
    }
    if (minute == 60) {
      minute = 0;
      sati++;
    }
    if (sati == 24)
      sati = 0;
  } else {
    ukupne_sekunde = 3600 * sati + minute * 60 + sekunde;
    sati = ukupne_sekunde / 3600;
    while (sati > 24)
      sati -= 24;
    minute = (ukupne_sekunde % 3600) / 60;
    sekunde = ukupne_sekunde % 60;
    if (sekunde == 60) {
      sekunde = 0;
      minute++;
    }
    if (minute == 60) {
      minute = 0;
      sati++;
    }
    if (sati == 24)
      sati = 0;
  }
  this->sati = sati;
  this->minute = minute;
  this->sekunde = sekunde;
}
Sat &Sat::Sljedeci() {
  int ukupne_sekunde = (3600 * sati + minute * 60 + sekunde + 1);
  while (ukupne_sekunde < 0)
    ukupne_sekunde += 86400;
  sati = ukupne_sekunde / 3600;
  while (sati > 24)
    sati += 24;
  minute = (ukupne_sekunde % 3600) / 60;
  sekunde = ukupne_sekunde % 60;
  if (sekunde == 60) {
    sekunde = 0;
    minute++;
  }
  if (minute == 60) {
    minute = 0;
    sati++;
  }
  if (sati == 24)
    sati = 0;
  return *this;
}
Sat &Sat::Prethodni() {
  int ukupne_sekunde = (3600 * sati + minute * 60 + sekunde - 1);
  while (ukupne_sekunde < 0)
    ukupne_sekunde += 86400;
  sati = ukupne_sekunde / 3600;
  while (sati > 24)
    sati -= 24;
  minute = (ukupne_sekunde % 3600) / 60;
  sekunde = ukupne_sekunde % 60;
  if (sekunde == 60) {
    sekunde = 0;
    minute++;
  }
  if (minute == 60) {
    minute = 0;
    sati++;
  }
  if (sati == 24)
    sati = 0;
  return *this;
}
Sat &Sat::PomjeriZa(int b) {
  int ukupne_sekunde = (3600 * sati + minute * 60 + sekunde + b);
  while (ukupne_sekunde < 0)
    ukupne_sekunde += 86400;
  sati = ukupne_sekunde / 3600;
  while (sati > 24)
    sati -= 24;
  minute = (ukupne_sekunde % 3600) / 60;
  sekunde = ukupne_sekunde % 60;
  if (sekunde == 60) {
    sekunde = 0;
    minute++;
  }
  if (minute == 60) {
    minute = 0;
    sati++;
  }
  if (sati == 24)
    sati = 0;
  return *this;
}
int BrojSekundiIzmedju(Sat s1, Sat s2) {
  return ((s1.sati * 3600 + s1.minute * 60 + s1.sekunde) -
          (s2.sati * 3600 + s2.minute * 60 + s2.sekunde));
}
void Sat::Ispisi() const {
  DaLiJeIspravno(sati, minute, sekunde);
  if (sati > 9 && minute > 9 && sekunde < 10)
    std::cout << sati << ":" << minute << ":0" << sekunde;
  else if (sati > 9 && minute < 10 && sekunde > 9)
    std::cout << sati << ":"
              << "0" << minute << ":" << sekunde;
  else if (sati < 10 && minute > 9 && sekunde > 9)
    std::cout << "0" << sati << ":" << minute << ":" << sekunde;
  else if (sati > 9 && minute < 10 && sekunde < 10)
    std::cout << sati << ":"
              << "0" << minute << ":"
              << "0" << sekunde;
  else if (sati < 10 && minute < 10 && sekunde > 9)
    std::cout << "0" << sati << ":"
              << "0" << minute << ":" << sekunde;
  else if (sati < 10 && minute > 9 && sekunde < 10)
    std::cout << "0" << sati << ":" << minute << ":"
              << "0" << sekunde;
  else if (sati < 10 && minute < 10 && sekunde < 10)
    std::cout << "0" << sati << ":"
              << "0" << minute << ":"
              << "0" << sekunde;
  else
    std::cout << sati << ":" << minute << ":" << sekunde;
}
int main() { return 0; }