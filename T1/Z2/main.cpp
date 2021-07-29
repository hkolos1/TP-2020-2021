// TP 2016/2017: Tutorijal 1, Zadatak 2
#include <cmath>
#include <iostream>
const double pi{4 * atan(1)};

int main() {
  double a, b, c;
  std::cout << "Unesite tri broja: ";
  std::cin >> a >> b >> c;
  if (a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b) {
    double s;
    s = a + b + c;
    s /= 2;
    double p;
    p = std::sqrt(s * (s - a) * (s - b) * (s - c));
    double alfa;
    alfa = std::acos((c * c + b * b - a * a) / (2 * c * b));
    double beta;
    beta = std::acos((a * a + c * c - b * b) / (2 * a * c));
    double gama;
    gama = std::acos((a * a + b * b - c * c) / (2 * a * b));
    double ugao;
    if (alfa <= beta && alfa <= gama)
      ugao = alfa;
    else if (beta <= alfa && beta <= gama)
      ugao = beta;
    else if (gama <= alfa && gama <= beta)
      ugao = gama;
    int stepeni, minute, sekunde;
    ugao *= 180 / pi;
    stepeni = ugao;
    minute = (ugao - stepeni) * 60;
    sekunde = (((ugao - stepeni) * 60) - minute) * 60;
    std::cout << "Obim trougla sa duzinama stranica " << b << " i " << c
              << " iznosi " << s * 2 << "." << std::endl;
    std::cout << "Njegova povrsina iznosi " << p << "." << std ::endl;
    std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, "
              << minute << " minuta i " << sekunde << " sekundi.";
  } else {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!";
  }
  return 0;
}