// TP 2018/2019: Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>

bool isti(std::string s1, std::string s2) {
  if (s1 == s2)
    return true;
  return false;
}

std::string ZamjenaRijeci(std::string s, std::vector<std::string> v_b,
                          std::vector<std::string> v_e) {

  if (v_b.size() != v_e.size())
    throw std::domain_error("Nekorektni parametri");
  std::string temp{};
  for (int i{0}; i < s.length(); i++) {
    temp = "";
    while (i < s.length() && ((s.at(i) >= 'a' && s.at(i) <= 'z') ||
                              (s.at(i) >= 'A' && s.at(i) <= 'Z'))) {
      temp.push_back(s.at(i));
      i++;
    }
    // std::cout<<temp<<std::endl;
    for (int j{0}; j < v_b.size(); j++) {
      if (isti(temp, v_b.at(j))) {
        int vel1 = v_b.at(j).length();
        int vel2 = v_e.at(j).length();
        if (vel1 == vel2) {

          for (int k{0}; k < vel1; k++) {
            s.at(i - vel1 + k) = v_e.at(j).at(k);
          }
        } else if (vel2 > vel1) {
          s.resize(s.length() + vel2 - vel1);
          for (int k = s.length() - 1; k > i; k--) {
            s.at(k) = s.at(k - 1);
          }
          for (int k{0}; k < vel2; k++) {
            s.at(i - vel1 + k) = v_e.at(j).at(k);
          }
        } else if (vel2 < vel1) {
          for (int k{i - vel1 + vel2}; k < s.size() - vel1 + vel2; k++) {
            s.at(k) = s.at(k + vel1 - vel2);
          }
          s.resize(s.length() - vel1 + vel2);
          for (int k{0}; k < vel2; k++) {
            s.at(i - vel1 + k) = v_e.at(j).at(k);
          }
        }
        i -= 2;
      }
    }
  }
  return s;
}

int main() {
  std::cout << "Unesite koliko riječi sadrži rječnik."<<std::endl;
  int n;
  std::cin >> n;
  std::vector<std::string> original;
  std::vector<std::string> zamjena;
  std::cin.clear();
  std::cin.ignore(100000,'\n');
  for (int i{0}; i < n; i++) {
    std::cout << "Unesite " << i + 1 << ". original rječnika."<<std::endl;
    std::string s;
    std::getline(std::cin, s);
    original.push_back(s);
    std::cout << "Unesite " << i + 1 << ". zamjenu rječnika."<<std::endl;
    std::getline(std::cin, s);
    zamjena.push_back(s);
  }
  
  for (;;) {
    std::cout << "Unesite rečenicu koju želite transformisati:" << std::endl;
    std::string s;
    std::getline(std::cin, s);
    if (s == "")
      break;
    std::string t = ZamjenaRijeci(s, original, zamjena);
    std::cout << "Transformisana rečenica glasi:" << std::endl << t << std::endl;
  }
  return 0;
}
