// TP 2018/2019: Zadaća 4, Zadatak 5
#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class Student {
  int broj_indeksa;
  std::string godina_studija, ime_i_prezime, adresa, broj_telefona;

public:
  Student(int brojindeksa, std::string godina, std::string ime,
          std::string adress, std::string telefon);
  int DajIndeks() const { return broj_indeksa; }
  std::string DajGodinuStudija() const { return godina_studija; }
  std::string DajImePrezime() const { return ime_i_prezime; }
  std::string DajAdresu() const { return adresa; }
  std::string DajTelefon() const { return broj_telefona; }
  void Ispisi() {
    std::cout << "Broj indeksa: " << broj_indeksa << std::endl
              << "Godina studija: " << godina_studija << std::endl
              << "Ime i prezime: " << ime_i_prezime << std::endl
              << "Adresa: " << adresa << std::endl
              << "Telefon: " << broj_telefona << std::endl;
  }
};
class Laptop {
  int ev_broj;
  std::string naziv;
  std::string karakteristike;
  Student *kod_koga_je;

public:
  Laptop(int broj, std::string ime, std::string karakt) {
    if (broj < 0)
      throw std::domain_error("Neispravni parametri");
    ev_broj = broj;
    naziv = ime;
    karakteristike = karakt;
    kod_koga_je = nullptr;
  }
  int DajEvidencijskiBroj() const { return ev_broj; }
  std::string DajKarakteristike() const { return karakteristike; }
  void Zaduzi(Student &s) {
    if (DaLiJeZaduzen())
      throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = &s;
  }
  void Razduzi() {
    if (DaLiJeZaduzen())
      kod_koga_je = nullptr;
  }
  bool DaLiJeZaduzen() {
    if (kod_koga_je == nullptr)
      return false;
    return true;
  }
  Student &DajKodKogaJe() {
    if (!DaLiJeZaduzen())
      throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
  }
  Student *DajPokKodKogaJe() { return kod_koga_je; }
  void Ispisi() {
    std::cout << "Evidencijski broj: " << ev_broj << std::endl
              << "Naziv: " << naziv << std::endl
              << "Karakteristike: " << karakteristike << std::endl;
  }
};
class Administracija {
  std::map<int, Student *> studenti;
  std::map<int, Laptop *> laptopi;

public:
  Administracija() {}
  Administracija(const Administracija &ad) {
    for (auto x : ad.studenti)
      studenti[x.first] = new Student(*x.second);
    for (auto x : ad.laptopi)
      laptopi[x.first] = new Laptop(*x.second);
  }
  Administracija &operator=(const Administracija &ad) {
    for (auto x : ad.studenti)
      studenti[x.first] = new Student(*x.second);
    for (auto x : ad.laptopi)
      laptopi[x.first] = new Laptop(*x.second);
    return *this;
  }
  Administracija &operator=(Administracija &ad) {
    std::swap(studenti, ad.studenti);
    std::swap(laptopi, ad.laptopi);
    return *this;
  }
  ~Administracija() {
    for (auto x : studenti)
      delete x.second;
    for (auto x : laptopi)
      delete x.second;
  }
  void RegistrirajNovogStudenta(int brojindeksa, std::string godina,
                                std::string ime, std::string adress,
                                std::string telefon) {
    if (studenti.find(brojindeksa) != studenti.end())
      throw std::domain_error("Student s tim indeksom vec postoji");
    studenti[brojindeksa] =
        new Student(brojindeksa, godina, ime, adress, telefon);
  }
  void RegistrirajNoviLaptop(int broj, std::string ime, std::string karakt) {
    if (laptopi.find(broj) == laptopi.end())
      throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    (laptopi[broj]) = new Laptop(broj, ime, karakt);
  }
  Student &NadjiStudenta(int brojindeksa) {
    if (studenti.find(brojindeksa) == studenti.end())
      throw std::domain_error("Student nije nadjen");
    return *studenti[brojindeksa];
  }
  Student &NadjiStudenta(int brojindeksa) const {
    auto studenti_copy = studenti;
    if (studenti_copy.find(brojindeksa) == studenti_copy.end())
      throw std::domain_error("Student nije nadjen");
    return *studenti_copy[brojindeksa];
  }
  Laptop &NadjiLaptop(int broj) {
    if (laptopi.find(broj) == laptopi.end())
      throw std::domain_error("Laptop nije nadjen");
    return *laptopi[broj];
  }
  Laptop &NadjiLaptop(int broj) const {
    auto laptopi_copy = laptopi;
    if (laptopi_copy.find(broj) == laptopi_copy.end())
      throw std::domain_error("Laptop nije nadjen");
    return *laptopi_copy[broj];
  }
  void IzlistajStudente() const {
    for (auto it = studenti.begin(); it != studenti.end(); it++) {
      it->second->Student::Ispisi();
      std::cout << std::endl;
    }
  }
  void IzlistajLaptope() const {
    for (auto it = laptopi.begin(); it != laptopi.end(); it++) {
      it->second->Laptop::Ispisi();
      if (it->second->DaLiJeZaduzen())
        std::cout << "Zaduzio(la): "
                  << it->second->DajKodKogaJe().DajImePrezime() << " ("
                  << it->second->DajKodKogaJe().DajIndeks() << ")";
      std::cout << std::endl;
    }
  }
  void ZaduziLaptop(int brojindeksa, int evbroj) {
    if (studenti.find(brojindeksa) == studenti.end())
      throw std::domain_error("Student nije nadjen");
    if (laptopi.find(evbroj) == laptopi.end())
      throw std::domain_error("Laptop nije nadjen");
    if (laptopi[evbroj]->Laptop::DaLiJeZaduzen())
      throw std::domain_error("Laptop vec zaduzen");
    for (auto it = laptopi.begin(); it != laptopi.end(); it++)
      if ((it->second)->Laptop::DaLiJeZaduzen() &&
          (it->second)->Laptop::DajKodKogaJe().Student::DajImePrezime() ==
              studenti[brojindeksa]->Student::DajImePrezime())
        throw std::domain_error("Student je vec zaduzio laptop");
    laptopi[evbroj]->Laptop::Zaduzi(*studenti[brojindeksa]);
  }

  int NadjiSlobodanLaptop() const {
    for (auto it = laptopi.begin(); it != laptopi.end(); it++)
      if (!(it->second->Laptop::DaLiJeZaduzen()))
        return it->second->Laptop::DajEvidencijskiBroj();
    throw std::domain_error("Nema slobodnih laptopa");
  }

  void RazduziLaptop(int evbroj) {
    if (laptopi.find(evbroj) == laptopi.end())
      throw std::domain_error("Laptop nije nadjen");
    if (!laptopi[evbroj]->Laptop::DaLiJeZaduzen())
      throw std::domain_error("Laptop nije zaduzen");
    laptopi[evbroj]->Laptop::Razduzi();
  }

  void PrikaziZaduzenja() const {
    bool zaduzen = false;
    for (auto it = laptopi.begin(); it != laptopi.end(); it++)
      if (it->second->Laptop::DaLiJeZaduzen())
        zaduzen = true;
    if (!zaduzen)
      std::cout << "Nema zaduzenja" << std::endl;
    else
      for (auto it = laptopi.begin(); it != laptopi.end(); it++)
        if (it->second->Laptop::DaLiJeZaduzen())
          std::cout
              << "Student "
              << it->second->Laptop::DajKodKogaJe().Student::DajImePrezime()
              << " (" << it->second->Laptop::DajKodKogaJe().Student::DajIndeks()
              << ") zaduzio/la laptop broj"
              << it->second->Laptop::DajEvidencijskiBroj() << std::endl;
  }
};
Student::Student(int brojindeksa, std::string godina, std::string ime,
                 std::string adress, std::string telefon) {
  int br = brojindeksa;
  for (int i = 0; i < 5; i++) {
    br /= 10;
  }
  if (br != 0)
    throw std::domain_error("Neispravni parametri");
  broj_indeksa = brojindeksa;
  if (godina != "1" && godina != "2" && godina != "3" && godina != "1/B" &&
      godina != "2/B" && godina != "1/M" && godina != "2/M" &&
      godina != "3/M" && godina != "1/D" && godina != "2/D" && godina != "3/D")
    throw std::domain_error("Neispravni parametri");
  if (godina == "1" || godina == "2" || godina == "3") {
    std::string b = "/B";
    godina.insert(1, b);
  }
  godina_studija = godina;
  for (int i = 0; i < ime.length(); i++) {
    if (i == 0 && ime.at(0) == ' ')
      while (ime.at(i) == ' ') {
        ime.erase(ime.begin() + i);
      }
    while (i != ime.length() - 1 && ime.at(i) != ' ')
      i++;
    while (i != 0 && i != ime.length() - 1 && ime.at(i) == ' ')
      if (ime.at(++i) == ' ')
        ime.erase(ime.begin() + (--i));
    if (i == ime.length() - 1 && ime.at(i) == ' ')
      ime.erase(ime.begin() + i);
  }
  ime_i_prezime = ime;
  for (int i = 0; i < adress.length(); i++) {
    if (i == 0 && adress.at(0) == ' ')
      while (adress.at(i) == ' ') {
        adress.erase(adress.begin() + i);
      }
    while (i != adress.length() - 1 && adress.at(i) != ' ')
      i++;
    while (i != 0 && i != adress.length() - 1 && adress.at(i) == ' ')
      if (adress.at(++i) == ' ')
        adress.erase(adress.begin() + (--i));
    if (i == adress.length() - 1 && adress.at(i) == ' ')
      adress.erase(adress.begin() + i);
  }
  ime_i_prezime = ime;
  for (int i = 0; i < adress.length(); i++) {
    if (i == 0) {
      while (i != telefon.length() - 1 && telefon.at(i) >= '0' &&
             telefon.at(i) <= '9')
        i++;
      if (i == telefon.length() - 1)
        throw std::domain_error("Neispravni parametri");
    } else if (i != telefon.length() - 1 && telefon.at(i) == '/') {
      i++;
      while (i != telefon.length() - 1 && telefon.at(i) >= '0' &&
             telefon.at(i) <= '9')
        i++;
      if (i == telefon.length() - 1)
        throw std::domain_error("Neispravni parametri");
    } else if (i != telefon.length() - 1 && telefon.at(i) == '-') {
      while (i != telefon.length() - 1 && telefon.at(i) >= '0' &&
             telefon.at(i) <= '9')
        i++;
      if (i == telefon.length() - 1)
        throw std::domain_error("Neispravni parametri");
    }
  }
  broj_telefona = telefon;
}
int main() {
  Administracija etf;

  return 0;
}