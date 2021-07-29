// TP 2020/2021: Tutorijal 2, Zadatak 1
#include <cmath>
#include <iostream>
#include <vector>

/* Provjera proste funkcije */
bool DaLiJeProst(int n) {
  if (n <= 1)
    return false;
  for (int i(2); i <= int(std::sqrt(std::abs(n))); i++)
    if (n % i == 0)
      return false;
  return true;
}
/* Vektorska funkcija */
std::vector<int> ProstiBrojeviUOpsegu(int a, int b) {
  std::vector<int> lista;
  for (long i = static_cast<long>(a); i <= static_cast<long>(b); i++)
    if (DaLiJeProst(int(i)))
      lista.push_back(int(i));
  return lista;
}

int main() {
  int a, b;
  std::cout << "Unesite pocetnu i krajnju  vrijednost: ";
  std::cin >> a >> b;

  /* Kreiranje prostog vektora */
  std::vector<int> primes = ProstiBrojeviUOpsegu(a, b);
  if (primes.empty())
    std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b
              << "!\n";
  else {
    std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
    for (int i(0); i < int(primes.size()) - 1;
         (std::cout << primes.at(i++) << ", "))
      ;
    std::cout << primes.at(int(primes.size()) - 1) << '\n';
  }

  return 0;
}
