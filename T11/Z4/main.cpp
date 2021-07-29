/*
    TP 16/17 (Tutorijal 11, Zadatak 4)
        Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
        i pitanja slati na mail: hhasic2@etf.unsa.ba.

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cstring>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Tim {
  char imeTima[20];
  int brOdigranih, brPobjeda, brNerijesenih, brPoraza, brDatih, brPrimljenih,
      brPoena;

public:
  friend class Liga;
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
class Liga {
  int brojTimova;
  Tim **timovi = nullptr;
  const int maxBrTimova;

public:
  explicit Liga(int velicinaLige)
      : timovi(new Tim *[velicinaLige] {}), maxBrTimova(velicinaLige) {}
  explicit Liga(std::initializer_list<Tim> listaTimova);
  ~Liga();
  Liga(const Liga &l);
  Liga(Liga &&l);
  Liga &operator=(const Liga &l);
  Liga &operator=(Liga &&l);
  void DodajNoviTim(const char imeTima[]);
  void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat1,
                           int rezultat2);
  void IspisiTabelu() const;
};
Liga::Liga(std::initializer_list<Tim> listaTimova)
    : timovi(new Tim *[listaTimova.size()] {}), maxBrTimova(listaTimova.size()),
      brojTimova(listaTimova.size()) {
  auto p = listaTimova.begin();
  for (int i = 0; i < maxBrTimova; i++) {
    timovi[i] = new Tim(p->imeTima);
    p++;
  }
}
Liga::~Liga() {
  for (int i = 0; i < maxBrTimova; i++)
    delete timovi[i];
  delete[] timovi;
}
Liga &Liga::operator=(const Liga &l) {
  if (l.maxBrTimova != this->maxBrTimova)
    throw std::logic_error("Nesaglasni kapaciteti liga");
}
Liga &Liga::operator=(Liga &&l) {
  if (l.maxBrTimova != this->maxBrTimova)
    throw std::logic_error("Nesaglasni kapaciteti liga");
}
void Liga::DodajNoviTim(const char imeTima[]) {
  if (brojTimova >= maxBrTimova)
    throw std::range_error("Liga popunjena");
}
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],
                               int rezultat1, int rezultat2) {
  if (rezultat1 < 0 || rezultat2 < 0)
    throw std::range_error("Neispravan broj golova");
  bool ima = false;
  for (int i = 0; i < brojTimova; i++)
    if (!strcmp(tim1, timovi[i]->imeTima) &&
        !strcmp(tim2, timovi[i]->imeTima)) {
      ima = true;
      break;
    }
  if (!ima)
    throw std::logic_error("Tim nije nadjen");
}
void Liga::IspisiTabelu()const {
    std::sort (timovi, timovi+brojTimova, [](Tim *tim1, Tim *tim2){
       if (tim1->DajBrojPoena() > tim2->DajBrojPoena()) return true;
	    if (tim1->DajBrojPoena() == tim2->DajBrojPoena()) 
	        if (tim1->DajGolRazliku() > tim2->DajGolRazliku()) return true;
	    if (tim1->DajBrojPoena() == tim2->DajBrojPoena())
	        if (tim1->DajGolRazliku() == tim2->DajGolRazliku())
	            if (strcmp(tim1->DajImeTima(), tim2->DajImeTima()) < 0) return true;
	    return false;
    });
    for (int i{0}; i < brojTimova; i++) timovi[i] -> IspisiPodatke();
        
}
int main() {
  /*Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo",
          "FK Sloboda",     "FK Krupa",     "FK Radnik Bijeljina"};
  l1.RegistrirajUtakmicu("NK Zeljeznicar", "HSK Zrinjski", 2, 0);

  Liga l2 = l1;

  std::cout << "Orginalna Liga za Prvaka: " << std::endl;
  l1.IspisiTabelu();
  std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
  l2.IspisiTabelu();

  l2.RegistrirajUtakmicu("FK Krupa", "FK Sloboda", 1, 1);

  std::cout << std::endl << "Nakon izmjene kopije: " << std::endl << std::endl;

  std::cout << "Orginalna Liga za Prvaka: " << std::endl;
  l1.IspisiTabelu();
  std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
  l2.IspisiTabelu();
*/
  return 0;
}
