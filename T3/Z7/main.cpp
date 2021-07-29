// TP 2018/2019: Tutorijal 3, Zadatak 7
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>


std::vector<std::vector<int>> PascalovTrougao(int n) {
  if (n < 0)
    throw std::domain_error("Broj redova ne smije biti negativan");
  std::vector<std::vector<int>> m(n);
  for (int i{0}; i < n; i++)
    m.at(i).resize(i + 1);

  for (int i{0}; i < n; i++) {
    for (int j{0}; j < m.at(i).size(); j++) {
      if (i == j)
        m.at(i).at(j) = 1;
      else if (j == 0)
        m.at(i).at(j) = 1;
      else
        m.at(i).at(j) = m.at(i - 1).at(j) + m.at(i - 1).at(j - 1);
    }
  }
  return m;
}

int NajvecaSirina(std::vector<std::vector<int>> m) {
  int sirina{0}, naj_sirina{0};
  for (std::vector<int> red : m) {
    for (int element : red) {
      while (element != 0) {
        sirina++;
        element /= 10;
      }
      if (sirina > naj_sirina) {
        naj_sirina = sirina;
      }
      sirina = 0;
    }
  }
  return naj_sirina;
}

int main() {
  try {
    int br_redova{0};
    std::cout << "Unesite broj redova: " << std::endl;
    std::cin >> br_redova;
    std::vector<std::vector<int>> m{PascalovTrougao(br_redova)};

    int sirina{NajvecaSirina(m)};
    for (std::vector<int> red : m) {
      for (int element : red) {
        std::cout << std::right << std::setw(sirina + 1) << element;
      }
      std::cout << std::endl;
    }
  } catch (std::domain_error izuzetak) {
    std::cout << izuzetak.what();
  }
  return 0;
}