// TP 2018/2019: Zadaća 3, Zadatak 3
#include <iomanip>
#include <iostream>
#include <new>
#include <stdexcept>

template <typename TipElemenata> struct Matrica {
  char ime_matrice; // Koristi se samo u funkciji "UnesiMatricu"
  int br_redova, br_kolona;
  TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!!!
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat) {
  if (!mat.elementi)
    return;
  for (int i = 0; i < mat.br_redova; i++)
    delete[] mat.elementi[i];
  delete[] mat.elementi;
  mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona,
                                    char ime = 0) {
  Matrica<TipElemenata> mat;
  mat.br_redova = br_redova;
  mat.br_kolona = br_kolona;
  mat.ime_matrice = ime;
  mat.elementi = new TipElemenata *[br_redova] {};
  try {
    for (int i = 0; i < br_redova; i++)
      mat.elementi[i] = new TipElemenata[br_kolona];
  } catch (...) {
    UnistiMatricu(mat);
    throw;
  }
  return mat;
}
template <typename TipElemenata> void UnesiMatricu(Matrica<TipElemenata> &mat) {
  for (int i = 0; i < mat.br_redova; i++)
    for (int j = 0; j < mat.br_kolona; j++) {
      std::cout << mat.ime_matrice << "(" << i << "," << j << ") = ";
      std::cin >> mat.elementi[i][j];
      std::cout << std::endl;
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,
                   int preciznost = 6, bool treba_brisati = false) {
  for (int i = 0; i < mat.br_redova; i++) {
    for (int j = 0; j < mat.br_kolona; j++)
      std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)
                << mat.elementi[i][j];
    std::cout << std::endl;
  }
  if (treba_brisati) {
    Matrica<TipElemenata> m = mat;
    UnistiMatricu(m);
  }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2) {
  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
  auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
  return m3;
}
template <typename TipElemenata>
void Saberi(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");

  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2) {
  if (m1.br_kolona != m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
  auto proizvod = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
  TipElemenata suma{0};
  for (int i{0}; i < m1.br_redova; i++) {
    for (int j{0}; j < m2.br_kolona; j++) {
      suma = 0;
      for (int k{0}; k < m2.br_redova; k++) {
        suma += m1.elementi[i][k] * m2.elementi[k][j];
      }
      proizvod.elementi[i][j] = suma;
    }
  }
  return proizvod;
}

template <typename TipElemenata>
void Pomnozi(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
  if (m1.br_kolona != m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
  auto proizvod = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
  for (int i{0}; i < m1.br_redova; i++) {
    for (int j{0}; j < m1.br_kolona; j++) {
      proizvod.elementi[i][j] = m1.elementi[i][j];
    }
  }
  TipElemenata suma{0};
  for (int i{0}; i < m1.br_redova; i++) {
    for (int j{0}; j < m2.br_kolona; j++) {
      suma = 0;
      for (int k{0}; k < m2.br_redova; k++) {
        suma += proizvod.elementi[i][k] * m2.elementi[k][j];
      }
      m1.elementi[i][j] = suma;
    }
  }
  UnistiMatricu(proizvod);
}

long double Faktorijel(long long int n) {
  long double faktorijel{1};
  for (int i{1}; i <= n; i++) {
    faktorijel *= i;
  }
  return faktorijel;
}
template <typename TipElemenata>
Matrica<TipElemenata>
MatricniEksponencijalniPolinom(const Matrica<TipElemenata> &m, int n) {
  if (m.br_redova != m.br_kolona)
    throw std::domain_error("Matrica nije kvadratna");
  if (n < 0)
    throw std::domain_error("Neispravan red");
  Matrica<TipElemenata> rezultat =
      StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  Matrica<TipElemenata> temp =
      StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  Matrica<TipElemenata> temp1 =
      StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  for (int i{0}; i < m.br_redova; i++) {
    for (int j{0}; j < m.br_kolona; j++) {
      temp.elementi[i][j] = m.elementi[i][j];
      rezultat.elementi[i][j] = m.elementi[i][j];
      temp1.elementi[i][j] = m.elementi[i][j];
      if (i == j)
        rezultat.elementi[i][j] += 1;
    }
  }

  for (int i{2}; i <= n; i++) {
    Matrica<TipElemenata> proizvod = ProduktMatrica(temp1, m);
    // IspisiMatricu(proizvod, 5);
    for (int j{0}; j < m.br_redova; j++) {
      for (int k{0}; k < m.br_kolona; k++) {
        temp.elementi[j][k] = proizvod.elementi[j][k];
        temp1.elementi[j][k] = proizvod.elementi[j][k];
        temp.elementi[j][k] = temp.elementi[j][k] * (1. / Faktorijel(i));
      }
    }
    // IspisiMatricu(rezultat, 5);
    // std::cout << std::endl;
    Saberi(rezultat, temp);
    UnistiMatricu(proizvod);
  }
  UnistiMatricu(temp);
  UnistiMatricu(temp1);
  return rezultat;
}
int main() {

  int a, b;
  std::cout << "Unesi broj redova i kolona za matricu A: " << std::endl;
  std::cin >> a >> b;
  int c, d;
  std::cout << "Unesi broj redova i kolona za matricu B: " << std::endl;
  std::cin >> c >> d;
  int n;
  std::cout << "Unesite broj n: " << std::endl;
  std::cin >> n;
  Matrica<double> A, B, produkt, polinom;
  try {
    A = StvoriMatricu<double>(a, b, 'A');
    B = StvoriMatricu<double>(c, d, 'B');
    std::cout << "Unesi matricu A: " << std::endl;
    UnesiMatricu(A);
    std::cout << "Unesi matricu B: " << std::endl;
    UnesiMatricu(B);
    produkt = StvoriMatricu<double>(a, d);
    produkt = ProduktMatrica(A, B);
    std::cout << "Produkt ove dvije matrice je: " << std::endl;
    IspisiMatricu(produkt, 10, 6, false);
    std::cout << "Eksponencijalni polinom matrice A je: " << std::endl;
    polinom = StvoriMatricu<double>(a, b);
    polinom = MatricniEksponencijalniPolinom<double>(A, n);
    IspisiMatricu(polinom, 10, 6, false);
  } catch (std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!" << std::endl;
  }
  UnistiMatricu(A);
  UnistiMatricu(B);
  UnistiMatricu(produkt);
  UnistiMatricu(polinom);

  return 0;
}