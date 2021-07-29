/*
    TP 16/17 (LV 13, Zadatak 1)
        Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave
   gresaka slati na mail iivkovic2@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class Lik {
public:
  virtual ~Lik() {}
  virtual void IspisiSpecificnosti() const = 0;
  virtual double DajObim() const = 0;
  virtual double DajPovrsinu() const = 0;
  virtual void Ispisi() const {
    IspisiSpecificnosti();
    std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu()
              << std::endl;
  }
};

class Krug : public Lik {
private:
  double poluprecnik;
  static constexpr double PI = 3.14159265358973;

public:
  Krug(double r) {
    if (r <= 0) {
      throw std::domain_error("Neispravni parametri");
    }
    poluprecnik = r;
  }
  double DajObim() const override { return 2 * PI * poluprecnik; }
  double DajPovrsinu() const override { return std::pow(poluprecnik, 2) * PI; }
  void IspisiSpecificnosti() const override {
    std::cout << "Krug poluprecnika " << poluprecnik << std::endl;
  }
};

class Pravougaonik : public Lik {
private:
  double a, b;

public:
  Pravougaonik(double x, double y) {
    if (x <= 0 || y <= 0) {
      throw std::domain_error("Neispravni parametri");
    }
    a = x;
    b = y;
  }
  double DajObim() const override { return 2 * a + 2 * b; }
  double DajPovrsinu() const override { return a * b; }
  void IspisiSpecificnosti() const override {
    std::cout << "Pravougaonik sa stranicama duzine " << a << " i " << b
              << std::endl;
  }
};

class Trougao : public Lik {
private:
  double a, b, c;

public:
  Trougao(double x, double y, double z) {
    if (x <= 0 || y <= 0 || z <= 0 || (x + y) <= z || (x + z) <= y ||
        (y + z) <= x) {
      throw std::domain_error("Neispravni parametri");
    }
    a = x;
    b = y;
    c = z;
  }
  double DajObim() const override { return a + b + c; }
  double DajPovrsinu() const override {
    return std::sqrt((DajObim() / 2) * (DajObim() / 2 - a) *
                     (DajObim() / 2 - b) * (DajObim() / 2 - c));
  }
  void IspisiSpecificnosti() const override {
    std::cout << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c
              << std::endl;
  }
};

int main() {
  int br;
  std::cout << "Koliko zelite likova: ";
  std::cin >> br;

  std::vector<std::shared_ptr<Lik>> vek(br);
  for (int i = 0; i < br; i++) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Lik " << i + 1 << ": ";
    char lik;
    std::cin >> lik;
    char znak;
    if (lik == 'K') {
      double r;
      std::cin >> r;
      if (!std::cin || std::cin.peek() != '\n') {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
        continue;
      }
      try {
        vek[i] = std::make_shared<Krug>(r);
      } catch (std::domain_error izuzetak) {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
        continue;
      }
    } else if (lik == 'P') {
      double a, b;
      std::cin >> a >> znak >> b;
      if (!std::cin || znak != ',' || std::cin.peek() != '\n') {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
        continue;
      }
      try {
        vek[i] = std::make_shared<Pravougaonik>(a, b);
      } catch (std::domain_error izuzetak) {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
        continue;
      }
    } else if (lik == 'T') {
      double a, b, c;
      std::cin >> a >> znak >> b >> znak >> c;
      if (!std::cin || znak != ',' || std::cin.peek() != '\n') {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
        continue;
      }
      try {
        vek[i] = std::make_shared<Trougao>(a, b, c);
      } catch (std::domain_error izuzetak) {
        std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
        i--;
      }
    } else {
      std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
      i--;
    }
  }
  std::cout << std::endl;
  for (auto x : vek) {
    x->Ispisi();
  }

  return 0;
}