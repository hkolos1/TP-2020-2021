/* 
    TP 16/17 (LV 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>

class ApstraktniStudent {
protected:
  std::string ime;
  std::string prezime;
  int index;
  int br_polozenih;
  double prosjecna_ocjena;

public:
  ApstraktniStudent(std::string i, std::string p, int indeks)
      : ime(i), prezime(p), index(indeks) {
    br_polozenih = 0;
    prosjecna_ocjena = 5;
  }
  virtual ~ApstraktniStudent() {}
  virtual std::string DajIme() const { return ime; }
  virtual std::string DajPrezime() const { return prezime; }
  virtual int DajBrojIndeksa() const { return index; }
  virtual int DajBrojPolozenih() const { return br_polozenih; }
  virtual double DajProsjek() const { return prosjecna_ocjena; }

  virtual void RegistrirajIspit(int ocjena) {
    if (ocjena < 5 || ocjena > 10) {
      throw std::domain_error("Neispravna ocjena");
    } else if (ocjena > 5) {
      double suma_ocjena = prosjecna_ocjena * br_polozenih;
      br_polozenih++;
      prosjecna_ocjena = (ocjena + suma_ocjena) / (br_polozenih);
    } else if (ocjena == 5) {
      br_polozenih = br_polozenih + 0;
      prosjecna_ocjena = prosjecna_ocjena + 0;
    }
  }
  virtual void PonistiOcjene() {
    br_polozenih = 0;
    prosjecna_ocjena = 5;
  }
  virtual void IspisiPodatke() const = 0;
  virtual ApstraktniStudent *DajKopiju() const = 0;
};

class StudentBachelor : public ApstraktniStudent {
public:
  StudentBachelor(std::string i, std::string p, int indeks)
      : ApstraktniStudent(i, p, indeks){};
  ApstraktniStudent *DajKopiju() const override {
    return new StudentBachelor(*this);
  }
  void IspisiPodatke() const override {
    std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime()
              << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl
              << "ima prosjek " << DajProsjek() << "." << std::endl;
  }
};

class StudentMaster : public ApstraktniStudent {
private:
  int godina;

public:
  StudentMaster(std::string i, std::string p, int indeks, int god)
      : ApstraktniStudent(i, p, indeks) {
    godina = god;
  };
  ApstraktniStudent *DajKopiju() const override {
    return new StudentMaster(*this);
  }
  void IspisiPodatke() const override {
    std::cout << "Student master studija " << DajIme() << " " << DajPrezime()
              << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl
              << "zavrsio bachelor studij godine " << godina << ",ima prosjek "
              << DajProsjek() << "." << std::endl;
  }
};

int main() { return 0; }