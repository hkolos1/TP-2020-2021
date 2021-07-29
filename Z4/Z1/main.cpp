// TP 2018/2019: Zadaća 4, Zadatak 1
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <new>
#include <stdexcept>
#include <vector>

typedef std::pair<double, double> Tacka;

class Trougao {
  Tacka tacke[3];

public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1, t2, t3) == 0)
      throw std::domain_error("Nekorektne pozicije tjemena");
    tacke[0] = t1;
    tacke[1] = t2;
    tacke[2] = t3;
  }
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1, t2, t3) == 0)
      throw std::domain_error("Nekorektne pozicije tjemena");
    tacke[0] = t1;
    tacke[1] = t2;
    tacke[2] = t3;
  }
  void Postavi(int indeks, const Tacka &t) {
    if (indeks != 1 && indeks != 2 && indeks != 3)
      throw std::range_error("Nekorektan indeks");
    tacke[indeks - 1] = t;
  }
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int izraz = t1.first * (t2.second - t3.second) -
                t2.first * (t1.second - t3.second) +
                t3.first * (t1.second - t2.second);
    if (izraz > 0)
      return 1;
    else if (izraz < 0)
      return -1;
    return 0;
  }
  Tacka DajTjeme(int indeks) const {
    if (indeks == 1)
      return tacke[0];
    else if (indeks == 2)
      return tacke[1];
    return tacke[2];
  }
  double DajStranicu(int indeks) const {
    if (indeks == 1)
      return sqrt((tacke[1].first - tacke[2].first) *
                      (tacke[1].first - tacke[2].first) +
                  (tacke[1].second - tacke[2].second) *
                      (tacke[1].second - tacke[2].second));
    else if (indeks == 2)
      return sqrt((tacke[0].first - tacke[2].first) *
                      (tacke[0].first - tacke[2].first) +
                  (tacke[0].second - tacke[2].second) *
                      (tacke[0].second - tacke[2].second));
    return sqrt((tacke[1].first - tacke[0].first) *
                    (tacke[1].first - tacke[0].first) +
                (tacke[1].second - tacke[0].second) *
                    (tacke[1].second - tacke[0].second));
  }
  double DajUgao(int indeks) const {
    if (indeks == 1)
      return (acos((DajStranicu(2) * DajStranicu(2) +
                    DajStranicu(3) * DajStranicu(3) -
                    DajStranicu(1) * DajStranicu(1)) /
                   (2 * DajStranicu(2) * DajStranicu(3))));
    else if (indeks == 2)
      return (acos((DajStranicu(1) * DajStranicu(1) +
                    DajStranicu(3) * DajStranicu(3) -
                    DajStranicu(2) * DajStranicu(2)) /
                   (2 * DajStranicu(1) * DajStranicu(3))));
    return (acos((DajStranicu(2) * DajStranicu(2) +
                  DajStranicu(1) * DajStranicu(1) -
                  DajStranicu(3) * DajStranicu(3)) /
                 (2 * DajStranicu(2) * DajStranicu(1))));
  }
  Tacka DajCentar() const {
    Tacka tjeme;
    tjeme.first = (tacke[0].first + tacke[1].first + tacke[2].first) / 3;
    tjeme.second = (tacke[0].second + tacke[1].second + tacke[2].second) / 3;
    return tjeme;
  }
  double DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
  }
  double DajPovrsinu() const {
    return std::abs(tacke[0].first * (tacke[1].second - tacke[2].second) -
                    tacke[1].first * (tacke[0].second - tacke[2].second) +
                    tacke[2].first * (tacke[0].second - tacke[1].second)) /
           2.;
  }
  bool DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(tacke[0], tacke[1], tacke[2]) == 1)
      return true;
    return false;
  }
  bool DaLiJeUnutra(const Tacka &t) const {
    if (Orijentacija(tacke[0], tacke[1], tacke[2]) == 1 &&
        Orijentacija(tacke[0], tacke[1], t) == 1 &&
        Orijentacija(tacke[0], t, tacke[2]) == 1 &&
        Orijentacija(tacke[1], tacke[2], t) == 1)
      return true;
    else if (Orijentacija(tacke[0], tacke[1], tacke[2]) == -1 &&
             Orijentacija(tacke[0], tacke[1], t) == -1 &&
             Orijentacija(tacke[0], t, tacke[2]) == -1 &&
             Orijentacija(tacke[1], tacke[2], t) == -1)
      return true;
    return false;
  }
  void Ispisi() const {
    std::cout << "((" << tacke[0].first << "," << tacke[0].second << "),("
              << tacke[1].first << "," << tacke[1].second << "),("
              << tacke[2].first << "," << tacke[2].second << "))";
  }
  void Transliraj(double delta_x, double delta_y) {
    tacke[0].first += delta_x;
    tacke[0].second += delta_y;
    tacke[1].first += delta_x;
    tacke[1].second += delta_y;
    tacke[2].first += delta_x;
    tacke[2].second += delta_y;
  }
  void Centriraj(const Tacka &t) {
    double delta_x =
        t.first - (tacke[0].first + tacke[1].first + tacke[2].first) / 3;
    double delta_y =
        t.second - (tacke[0].second + tacke[1].second + tacke[2].second) / 3;
    tacke[0].first += delta_x;
    tacke[0].second += delta_y;
    tacke[1].first += delta_x;
    tacke[1].second += delta_y;
    tacke[2].first += delta_x;
    tacke[2].second += delta_y;
  }
  void Rotiraj(const Tacka &t, double ugao) {
    tacke[0] = {t.first + (tacke[0].first - t.first) * cos(ugao) -
                    (tacke[0].second - t.second) * sin(ugao),
                (t.second + (tacke[0].first - t.first) * sin(ugao) +
                 (tacke[0].second - t.second) * cos(ugao))};

    tacke[1] = {(t.first + (tacke[1].first - t.first) * cos(ugao) -
                 (tacke[1].second - t.second) * sin(ugao)),
                t.second + (tacke[1].first - t.first) * sin(ugao) +
                    (tacke[1].second - t.second) * cos(ugao)};

    tacke[2] = {(t.first + (tacke[2].first - t.first) * cos(ugao) -
                 (tacke[2].second - t.second) * sin(ugao)),
                (t.second + (tacke[2].first - t.first) * sin(ugao) +
                 (tacke[2].second - t.second) * cos(ugao))};
  }
  void Skaliraj(const Tacka &t, double faktor) {
    if (faktor == 0)
      throw std::domain_error("Nekorektan faktor skaliranja");

    tacke[0].first = t.first + faktor * (tacke[0].first - t.first);
    tacke[0].second = t.second + faktor * (tacke[0].second - t.second);
    tacke[1].first = t.first + faktor * (tacke[1].first - t.first);
    tacke[1].second = t.second + faktor * (tacke[1].second - t.second);
    tacke[2].first = t.first + faktor * (tacke[2].first - t.first);
    tacke[2].second = t.second + faktor * (tacke[2].second - t.second);
  }

  void Rotiraj(double ugao) {
    Tacka t = DajCentar();
    tacke[0].first = (t.first + (tacke[0].first - t.first) * cos(ugao) -
                      (tacke[0].second - t.second) * sin(ugao));
    tacke[0].second = (t.second + (tacke[0].first - t.first) * sin(ugao) +
                       (tacke[0].second - t.second) * cos(ugao));
    tacke[1].first = (t.first + (tacke[1].first - t.first) * cos(ugao) -
                      (tacke[1].second - t.second) * sin(ugao));
    tacke[1].second = (t.second + (tacke[1].first - t.first) * sin(ugao) +
                       (tacke[1].second - t.second) * cos(ugao));
    tacke[2].first = (t.first + (tacke[2].first - t.first) * cos(ugao) -
                      (tacke[2].second - t.second) * sin(ugao));
    tacke[2].second = (t.second + (tacke[2].first - t.first) * sin(ugao) +
                       (tacke[2].second - t.second) * cos(ugao));
  }
  void Skaliraj(double faktor) {
    Tacka t = DajCentar();
    if (faktor == 0)
      throw std::domain_error("Nekorektan faktor skaliranja");
    tacke[0].first = t.first + faktor * (tacke[0].first - t.first);
    tacke[0].second = t.second + faktor * (tacke[0].second - t.second);
    tacke[1].first = t.first + faktor * (tacke[1].first - t.first);
    tacke[1].second = t.second + faktor * (tacke[1].second - t.second);
    tacke[2].first = t.first + faktor * (tacke[2].first - t.first);
    tacke[2].second = t.second + faktor * (tacke[2].second - t.second);
  }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
  Trougao t(t1);
  if (Trougao::Orijentacija(t.tacke[0], t.tacke[1], t.tacke[2]) !=
      Trougao::Orijentacija(t2.tacke[0], t2.tacke[1], t2.tacke[2]))
    std::swap(t.tacke[0], t.tacke[1]);
  if (t.tacke[0] == t2.tacke[0] && t.tacke[1] == t2.tacke[1] &&
      t.tacke[2] == t2.tacke[2])
    return true;
  if (t.tacke[0] == t2.tacke[1] && t.tacke[1] == t2.tacke[2] &&
      t.tacke[2] == t2.tacke[0])
    return true;
  if (t.tacke[0] == t2.tacke[2] && t.tacke[1] == t2.tacke[0] &&
      t.tacke[2] == t2.tacke[1])
    return true;
  return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
  Trougao t(t1);
  if (Trougao::Orijentacija(t.tacke[0], t.tacke[1], t.tacke[2]) !=
      Trougao::Orijentacija(t2.tacke[0], t2.tacke[1], t2.tacke[2]))
    std::swap(t.tacke[0], t.tacke[1]);
  if (t.DajStranicu(1) == t2.DajStranicu(1) &&
      t.DajStranicu(2) == t2.DajStranicu(2) &&
      t.DajStranicu(3) == t2.DajStranicu(3))
    return true;
  else if (t.DajStranicu(1) == t2.DajStranicu(2) &&
           t.DajStranicu(2) == t2.DajStranicu(3) &&
           t.DajStranicu(3) == t2.DajStranicu(1))
    return true;
  if (t.DajStranicu(1) == t2.DajStranicu(3) &&
      t.DajStranicu(2) == t2.DajStranicu(1) &&
      t.DajStranicu(3) == t2.DajStranicu(2))
    return true;
  return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
  Trougao t(t1);
  if (Trougao::Orijentacija(t.tacke[0], t.tacke[1], t.tacke[2]) !=
      Trougao::Orijentacija(t2.tacke[0], t2.tacke[1], t2.tacke[2]))
    std::swap(t.tacke[0], t.tacke[1]);
  if (t.DajUgao(1) == t2.DajUgao(1) && t.DajUgao(2) == t2.DajUgao(2) &&
      t.DajUgao(3) == t2.DajUgao(3))
    return true;
  else if (t.DajUgao(1) == t2.DajUgao(2) && t.DajUgao(2) == t2.DajUgao(3) &&
           t.DajUgao(3) == t2.DajUgao(1))
    return true;
  if (t.DajUgao(1) == t2.DajUgao(3) && t.DajUgao(2) == t2.DajUgao(1) &&
      t.DajUgao(3) == t2.DajUgao(2))
    return true;
  return false;
}
int main() {
  std::cout << "Unesite broj trouglova: ";
  int n;
  std::cin >> n;
  std::vector<std::shared_ptr<Trougao>> v(n);
  for (int i = 0; i < v.size(); i++) {
    std::cout << "Unesite vrhove " << i + 1
              << ". trougla [x1 y1 x2 y2 x3 y3]: ";
    double x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Tacka t1, t2, t3;
    t1.first = x1;
    t1.second = y1;
    t2.first = x2;
    t2.second = y2;
    t3.first = x3;
    t3.second = y3;
    std::shared_ptr<Trougao> t;
    try {

      v.at(i) = std::make_shared<Trougao>(t1, t2, t3);
      // v.push_back(t);

    } catch (std::bad_alloc) {
    }

    catch (std::domain_error e) {
      std::cout << e.what() << ", ponovite unos!" << std::endl;
      i--;
    }
  }
  std::cout << "Trouglovi prije transformacija:" << std::endl;
  std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> tr) {
    (*tr).Ispisi();
    std::cout << std::endl;
  });
  std::cout << "Unesite vektor translacije [dx dy]:  " << std::endl;
  double dx, dy;
  std::cin >> dx >> dy;
  std::cout << "Unesite ugao rotacije: ";
  double ugao;
  std::cin >> ugao;
  std::cout << "Unesite faktor skaliranja: \n";
  double faktor;
  std::cin >> faktor;
  std::cout << "Trouglovi nakon transformacija i sortiranja:" << std::endl;
  std::transform(v.begin(), v.end(), v.begin(),
                 [dx, dy, ugao, faktor](std::shared_ptr<Trougao> tr) {
                   tr->Transliraj(dx, dy);
                   tr->Rotiraj(ugao);
                   tr->Skaliraj(tr->DajTjeme(1), faktor);
                   return tr;
                 });
  std::sort(v.begin(), v.end(),
            [](std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2) {
              return (*tr1).DajPovrsinu() < (*tr2).DajPovrsinu();
            });
  std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> tr) {
    (*tr).Ispisi();
    std::cout << std::endl;
  });
  auto min = std::min_element(
      v.begin(), v.end(),
      [](std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2) {
        return (*tr1).DajObim() < (*tr2).DajObim();
      });
  std::cout << "Vrhovi trougla sa najmanjim obimom: " << std::endl;
  (**min).Ispisi();
  std::cout << std::endl;
  int identicnih = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (DaLiSuIdenticni(*(v.at(i)), *(v.at(j)))) {
        identicnih++;
        if (identicnih == 1)
          std::cout << "Parovi identicnih trouglova:" << std::endl;
        (*v.at(i)).Ispisi();
        std::cout << " i ";
        (*v.at(j)).Ispisi();
        std::cout << std::endl;
      }
    }
  }
  if (identicnih == 0)
    std::cout << "Nema identicnih trouglova!" << std::endl;

  int podudarnih = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (DaLiSuPodudarni(*(v.at(i)), *(v.at(j)))) {
        podudarnih++;
        if (podudarnih == 1)
          std::cout << "Parovi podudarnih trouglova:" << std::endl;
        (*v.at(i)).Ispisi();
        std::cout << " i ";
        (*v.at(j)).Ispisi();
        std::cout << std::endl;
      }
    }
  }
  if (podudarnih == 0)
    std::cout << "Nema podudarnih trouglova!" << std::endl;

  int slicnih = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (DaLiSuSlicni(*(v.at(i)), *(v.at(j)))) {
        slicnih++;
        if (slicnih == 1)
          std::cout << "Parovi slicnih trouglova:" << std::endl;
        (*v.at(i)).Ispisi();
        std::cout << " i ";
        (*v.at(j)).Ispisi();
        std::cout << std::endl;
      }
    }
  }
  if (slicnih == 0)
    std::cout << "Nema slicnih trouglova!" << std::endl;
  return 0;
}