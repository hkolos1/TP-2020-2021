// TP 2018/2019: Tutorijal 8, Zadatak 5
#include <iostream>
#include <tuple>

typedef std::tuple<double, double, double> Vektor3d;

void UnesiVektor(Vektor3d &v) {
  double x, y, z;
  std::cout << "X = ";
  std::cin >> x;
  std::cout << "Y = ";
  std::cin >> y;
  std::cout << "Z = ";
  std::cin >> z;
  v = std::make_tuple(x, y, z);
}
void IspisiVektor(const Vektor3d &v) {
  std::cout << "{" << std::get<0>(v) << "," << std::get<1>(v) << ","
            << std::get<2>(v) << "}";
}
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
  double x1, y1, z1, x2, y2, z2;
  std::tie(x1, y1, z1) = v1;
  std::tie(x2, y2, z2) = v2;
  return std::make_tuple(x1 + x2, y1 + y2, z1 + z2);
}
Vektor3d VektorskiProizvod(const Vektor3d &v1, const Vektor3d &v2) {
  double x1, y1, z1, x2, y2, z2;
  std::tie(x1, y1, z1) = v1;
  std::tie(x2, y2, z2) = v2;
  return std::make_tuple(y1 * z2 - z1 * y2, z1 * x2 - x1 * z2,
                         x1 * y2 - x2 * y1);
}
int main() {
  Vektor3d a, b;
  std::cout << "Unesi prvi vektor:" << std::endl;
  UnesiVektor(a);
  std::cout << "Unesi drugi vektor:" << std::endl;
  UnesiVektor(b);
  std::cout << "Suma ova dva vektora je: ";
  IspisiVektor(ZbirVektora(a, b));
  std::cout << std::endl << "Njihov vektorski prozivod je: ";
  IspisiVektor(VektorskiProizvod(a, b));
  return 0;
}