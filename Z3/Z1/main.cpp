// TP 2018/2019: Zadaća 3, Zadatak 1
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

bool Kriterij(std::pair<double, double> p1, std::pair<double, double> p2) {
  return p1.first < p2.first;
}

std::function<double(double)>
LinearnaInterpolacija(std::vector<std::pair<double, double>> v) {
  std::sort(v.begin(), v.end(), Kriterij);
  // double eps{0.00000000000000000000001};
  // for (int i = 0; i < v.size(); i++) std::cout<<v.at(i).first<<" ";
  for (int i{0}; i < v.size() - 1; i++) {
    if (v.at(i).first == v.at(i + 1).first) {
      throw std::domain_error("Neispravni cvorovi.");
    }
  }
  return [v](double x) {
    double rezultat{0};

    if (x < v.at(0).first || x > v.at(v.size() - 1).first) {
      throw std::range_error("Argument izvan opsega.");
    }
    auto p = std::lower_bound(
        v.begin(), v.end(), x,
        [](std::pair<double, double> p, double x) { return p.first <= x; });
    auto k = std::upper_bound(
        v.begin(), v.end(), x,
        [](double x, std::pair<double, double> p) { return p.first > x; });
    // std::cout<<a->first<<" "<<a->second<<std::endl;
    p--;
    if (p != v.end() && k != v.end()) {
      rezultat = p->second + ((k->second - p->second) / (k->first - p->first)) *
                                 (x - p->first);
    } else {
      rezultat = v.at(v.size() - 1).second;
    }
    return rezultat;
  };
}

std::function<double(double)> LinearnaInterpolacija(double f(double),
                                                    double x_min, double x_max,
                                                    double delta_x) {
  if (x_min > x_max || delta_x <= 0)
    throw std::domain_error("Nekorektni parametri.");
  if (delta_x > x_max) {
    throw std::range_error("Argument izvan opsega.");
  }
  std::vector<std::pair<double, double>> v;
  while (x_min < x_max) {
    x_min += delta_x;
    v.push_back(std::make_pair(x_min, f(x_min)));
  }
  return LinearnaInterpolacija(v);
}

int main() {

  int opcija{0};
  std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "
            << std::endl;
  std::cin >> opcija;

  if (opcija == 1) {
    int broj{0};
    std::cout << "Unesite broj cvorova: " << std::endl;
    std::cin >> broj;
    std::cout << "Unesite cvorove kao parove x i y: " << std::endl;
    double x{0}, y{0};
    std::vector<std::pair<double, double>> v;
    for (int i{0}; i < broj; i++) {
      std::cin >> x >> y;
      v.push_back(std::make_pair(x, y));
    }
    double argument{0};
    try {
      auto f = LinearnaInterpolacija(v);
      std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;

      std::cin >> argument;
      while (std::cin) {
        try {
          std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        } catch (std::domain_error e) {
          std::cout << e.what() << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        } catch (std::range_error e) {
          std::cout << e.what() << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        }
      }
      return 0;
    } catch (std::domain_error e) {
      std::cout << e.what() << std::endl;
    } catch (std::range_error e) {
      std::cout << e.what() << std::endl;
    }
  } else if (opcija == 2) {
    std::cout << "Unesite krajeve intervala i korak: " << std::endl;
    double pocetak, kraj, korak;
    std::cin >> pocetak >> kraj >> korak;
    try {
      auto f = LinearnaInterpolacija(
          [](double x) { return x * x + std::sin(x); }, pocetak, kraj, korak);
      std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
      double argument{0};
      std::cin >> argument;
      while (std::cin) {
        try {
          std::cout << "f(" << argument << ") = " <<
              [](double x) { return x * x + std::sin(x); }(argument) << " "
                    << "f_approx(" << argument << ") = " << f(argument)
                    << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        }

        catch (std::domain_error e) {
          std::cout << e.what() << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        } catch (std::range_error e) {
          std::cout << e.what() << std::endl;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): " << std::endl;
          std::cin >> argument;
        }
      }
    } catch (std::domain_error e) {
      std::cout << e.what();
    } catch (std::range_error e) {
      std::cout << e.what();
    }
    return 0;
  }

  return 0;
}