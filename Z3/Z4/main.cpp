// TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>

std::vector<int> Razbrajanje(int N, int M) {
  std::vector<int> iskljuceni;
  std::list<int> lista;
  for (int i{1}; i <= N; i++) {
    lista.push_back(i);
  }
  for (std::list<int>::iterator it{lista.begin()}; it != lista.end();) {
    // std::cout << *it << " ";

    iskljuceni.push_back(*it);
    it = lista.erase(it);
    if (it == lista.end())
      it = lista.begin();
    if (lista.size() == 1) {
      iskljuceni.push_back(*it);
      it = lista.erase(it);
      break;
    }
    int i{0};
    while (i < M - 1) {
      it++;
      if (it == lista.end())
        it = lista.begin();
      i++;
    }
  }
  // for (int i = 0; i < iskljuceni.size(); i++)
  // std::cout << iskljuceni.at(i) << " ";
  // std::cout << std::endl;
  return iskljuceni;
}

int OdabirKoraka(int N, int K) {
  if (N <= 0 || K <= 0 || K > N)
    throw std::domain_error(
        "Broj blokova i redni broj bloka su pozitivni cijeli brojevi i redni "
        "broj bloka ne moze biti veci od broja blokova");
  for (int i{0}; i < N; i++) {
    std::vector<int> v{Razbrajanje(N, i)};
    if (v.at(v.size() - 1) == K)
      return i;
  }
  return 0;
}

int main() {
  try {
    int n;
    std::cout << "Unesite broj blokova u gradu: ";
    std::cin >> n;
    int m;
    std::cout
        << "Unesite redni broj bloka u kojem se nalazi sjediste stranke: ";
    std::cin >> m;
    std::cout << "Trazeni korak: " << OdabirKoraka(n, m);
  } catch (std::domain_error e) {
    std::cout << e.what();
  }
  // std::vector<int> a = Razbrajanje(10, 4);
  return 0;
}