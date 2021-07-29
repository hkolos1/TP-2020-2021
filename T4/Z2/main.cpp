// TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

void IzvrniString(std::string &s) {
  char slovo;
  for (int i{0}; i < s.length() / 2; i++) {
    slovo = s.at(i);
    s.at(i) = s.at(s.length() - i - 1);
    s.at(s.length() - i - 1) = slovo;
  }
}

int main() {
  std::string s;
  std::cout << "Unesi string: ";
  std::getline(std::cin, s);
  IzvrniString(s);
  std::cout << "Izvrnuti string je: " << s;
  return 0;
}