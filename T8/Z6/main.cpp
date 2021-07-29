// TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>
#include <memory>

template <typename T> struct Cvor {
  T element;
  Cvor *veza;
};

template <typename T> Cvor<T> *KreirajPovezanuListu(T zavrsni) {
  Cvor<T> *pocetak = nullptr, *prethodni;
  for (;;) {
    T podatak;
    std::cin >> podatak;
    if (podatak == zavrsni)
      break;
    Cvor<T> *novi = new Cvor<T>{podatak, nullptr};
    if (!pocetak)
      pocetak = novi;
    else
      prethodni->veza = novi;
    prethodni = novi;
  }
  return pocetak;
}
template <typename T> int BrojElemenata(Cvor<T> *pocetak) {
  int brojac = 0;
  for (Cvor<T> *p = pocetak; p != nullptr; p = p->veza)
    brojac++;
  return brojac;
}
template <typename T> T SumaElemenata(Cvor<T> *pocetak) {
  T suma = 0;
  for (Cvor<T> *p = pocetak; p != nullptr; p = p->veza)
    suma += p->element;
  return suma;
}
template <typename T> int BrojVecihOd(Cvor<T> *pocetak, T prag) {
  int brojac = 0;
  for (Cvor<T> *p = pocetak; p != nullptr; p = p->veza)
    if (p->element > prag)
      brojac++;
  return brojac;
}
template <typename T> void UnistiListu(Cvor<T> *pocetak) {
  if (!pocetak)
    return;
  UnistiListu(pocetak->veza);
  delete pocetak;
}

int main() {
  std::cout << "Unesite slijed brojeva (0 za kraj): ";
  Cvor<double> *lista = KreirajPovezanuListu(0.);
  double suma = SumaElemenata(lista);
  double prosjek = SumaElemenata(lista) / BrojElemenata(lista);
  std::cout << "U slijedu ima " << BrojVecihOd(lista, prosjek)
            << " brojeva vecih od njihove aritmeticke sredine";
  UnistiListu(lista);
  return 0;
}