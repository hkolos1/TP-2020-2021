// TP 2018/2019: Zadaća 1, Zadatak 2
#include <array>
#include <iostream>
#include <vector>
#include <stdexcept>


std::array<int, 4> RasponMatrice(std::vector<std::vector<double>> matrica) {
  if (matrica.size() == 0)
    throw std::domain_error("Raspon nije definiran za nul-matricu ili praznu "
                            "matricu");
  for (int i{0}; i < matrica.size(); i++) {
    if (matrica.at(i).size() != matrica.at(0).size())
      throw std::domain_error("Nekorektna matrica");
  }

  double eps{0.0000000000000000000001};
  bool null_matrica{true};
  for (int i{0}; i < matrica.size(); i++) {
    for (int j{0}; j < matrica.at(i).size(); j++) {
      double temp = matrica.at(i).at(j);
      if (!(temp < eps && temp > -eps)) {
        // if (temp != 0) {
        null_matrica = false;
        i = matrica.size();
        break;
      }
    }
  }
  if (null_matrica == true)
    throw std::domain_error(
        "Raspon nije definiran za nul-matricu ili praznu matricu");
  bool da_li_je_red_nula{true};
  std::array<int, 4> raspon;
  int brojac{0};
  for (int i{0}; i < matrica.size(); i++) {
    da_li_je_red_nula = true;
    for (int j{0}; j < matrica.at(0).size(); j++) {
      double temp = matrica.at(i).at(j);
      if (!(temp < eps && temp > -eps)) {
        da_li_je_red_nula = false;
        brojac++;
        break;
      }
    }
    if (da_li_je_red_nula == false && brojac == 1) {
      raspon.at(0) = i + 1;
      raspon.at(2) = i + 1;
    } else if (da_li_je_red_nula == false && brojac != 0) {
      // std::cout << brojac << "gggggg"<<i;
      raspon.at(2) = i + 1;
    }
  }
  if (da_li_je_red_nula == false)
    raspon.at(2) = matrica.size();
  bool da_li_je_kolona_nula{true};
  brojac = 0;
  for (int i{0}; i < matrica.at(0).size(); i++) {
    da_li_je_kolona_nula = true;
    for (int j{0}; j < matrica.size(); j++) {
      double temp = matrica.at(j).at(i);
      if (!(temp < eps && temp > -eps)) {
        da_li_je_kolona_nula = false;
        brojac++;
        break;
      }
    }
    if (da_li_je_kolona_nula == false && brojac == 1) {
      raspon.at(1) = i + 1;
      raspon.at(3) = i + 1;
    } else if (da_li_je_kolona_nula == false && brojac != 1) {
      raspon.at(3) = i + 1;
    }
  }
  if (da_li_je_kolona_nula == false)
    raspon.at(3) = matrica.at(0).size();
  return raspon;
}


int main() {
 try {
    std::cout << "Unesite dimenziju matrice u formatu m x n: ";
    int m, n;
    char a;
    std::cin >> m >> a >> n;
    std::vector<std::vector<double>> mat(m, std::vector<double>(n));
    std::cout << " Unesite elemente matrice: " << std::endl;
    for (int i{0}; i < m; i++) {
      std::cout << "Elementi " << i + 1 << ". reda: ";
      for (int j{0}; j < n; j++) {
        std::cin >> mat.at(i).at(j);
      }
    }
    std::array<int, 4> rez = RasponMatrice(mat);
    std::cout << std::endl
              << "Raspon matrice je od (" << rez.at(0) << "," << rez.at(1)
              << ")"
              << " do (" << rez.at(2) << "," << rez.at(3) << ").";
  } catch (std::domain_error e) {
    std::cout << "IZUZETAK: " << e.what() << "!"; 
  }

  return 0;
}