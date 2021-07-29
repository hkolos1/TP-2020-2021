// TP 2018/2019: Zadaća 1, Zadatak 3
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>

int Sirina(std::deque<std::deque<double>> m) {
  int sirina{0}, k{0}, temp;
  for (int i{0}; i < m.size(); i++) {
    for (int j{0}; j < m.at(0).size(); j++) {
      k = 0;
      temp = m.at(i).at(j);
      while (temp != 0) {
        k++;
        temp /= 10;
      }
      if (k > sirina)
        sirina = k;
    }
  }
  return sirina;
}

std::deque<std::deque<double>>
EkspanzijaMatrice(std::deque<std::deque<double>> matrica, int p, int q) {
  if (p <= 0 || q <= 0)
    throw std::domain_error("Nelegalni parametri");
  for (int i{0}; i < matrica.size(); i++) {
    if (matrica.at(0).size() != matrica.at(i).size())
      throw std::domain_error("Nekorektna matrica");
  }
  if (matrica.size() == 0)
    throw std::domain_error("Nekorektna matrica");
  std::deque<std::deque<double>> konacna;
  konacna.resize(matrica.size() * p);
  std::deque<double> temp;
  for (int i{0}; i < matrica.size(); i++) {
    temp.resize(0);
    for (int j{0}; j < matrica.at(0).size(); j++) {
      for (int k{0}; k < q; k++) {
        temp.push_back(matrica.at(i).at(j));
      }
    }
    int l{0};
    while (l < p) {
      konacna.at(i * p + l) = temp;
      l++;
    }
  }
  return konacna;
}

int main() {
  try {
    int m;
    std::cout << "Unesite broj redova matrice A (m): ";
    std::cin >> m;
    int n;
    std::cout << "Unesite broj kolona matrice A (n): ";
    std::cin >> n;
    std::deque<std::deque<double>> mat(m, std::deque<double>(n));
    for (int i{0}; i < m; i++) {
      std::cout << "Unesite " << i + 1 << ". red matrice: ";
      for (int j{0}; j < n; j++) {
        std::cin >> mat.at(i).at(j);
      }
    }
    int p, q;
    std::cout << "Unesite dimenziju ekspanzije p: ";
    std::cin >> p;
    std::cout << "Unesite dimenziju ekspanzije q: ";
    std::cin >> q;
    std::cout << "Ekspanzija matrice A glasi:\n";
    int s = Sirina(mat);

    mat = EkspanzijaMatrice(mat, p, q);
    for (int i{0}; i < mat.size(); i++) {
      for (int j{0}; j < mat.at(0).size(); j++) {
        std::cout << std::setw(s + 4) << std::fixed << std::setprecision(2)
                  << mat.at(i).at(j) << " ";
      }
      std::cout << std::endl;
    }
  } catch (std::domain_error e) {
    std::cout << e.what();
  }
  return 0;
}