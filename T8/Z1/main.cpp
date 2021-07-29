// TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <stdexcept>

struct Vrijeme {
  int sati, minute, sekunde;
};

void TestirajVrijeme(Vrijeme v) {
  if (v.sati > 23 || v.sati < 0 || v.minute > 59 || v.minute < 0 ||
      v.sekunde > 59 || v.sekunde < 0)
    throw std::domain_error("Neispravno vrijeme");
}
void IspisiVrijeme(Vrijeme v) {
  TestirajVrijeme(v);
  if (v.sati < 10 && v.minute > 10 && v.sekunde > 10)
    std::cout << "0" << v.sati << ":" << v.minute << ":" << v.sekunde
              << std::endl;
  else if (v.sati < 10 && v.minute > 10 && v.sekunde > 10)
    std::cout << "0" << v.sati << ":0" << v.minute << ":" << v.sekunde
              << std::endl;
  else if (v.sati < 10 && v.minute > 10 && v.sekunde > 10)
    std::cout << "0" << v.sati << ":0" << v.minute << ":0" << v.sekunde
              << std::endl;
  else if (v.sati > 10 && v.minute < 10 && v.sekunde > 10)
    std::cout << v.sati << ":0" << v.minute << ":" << v.sekunde << std::endl;
  else if (v.sati > 10 && v.minute < 10 && v.sekunde < 10)
    std::cout << v.sati << ":0" << v.minute << ":0" << v.sekunde << std::endl;
  else if (v.sati < 10 && v.minute < 10 && v.sekunde < 10)
    std::cout << "0" << v.sati << ":0" << v.minute << ":" << v.sekunde
              << std::endl;
  else
    std::cout << v.sati << ":" << v.minute << ":" << v.sekunde << std::endl;
}
Vrijeme SaberiVrijeme(Vrijeme v1, Vrijeme v2) {
  TestirajVrijeme(v1);
  TestirajVrijeme(v2);
  Vrijeme v3{};
  int ukupne_sekunde{v1.sati * 3600 + v2.sati * 3600 + v1.minute * 60 +
                     v2.minute * 60 + v1.sekunde + v2.sekunde};
  v3.sati = ukupne_sekunde / 3600;
  if (v3.sati > 24)
    v3.sati /= 2;
  v3.minute = (ukupne_sekunde % 3600) / 60;
  v3.minute = ukupne_sekunde % 60;
  if (v3.sekunde == 60) {
    v3.sekunde = 0;
    v3.minute++;
  }
  if (v3.minute == 60) {
    v3.minute = 0;
    v3.sati++;
  }
  return v3;
}
void UnesiVrijeme (Vrijeme &v){
    std::cin>>v.sati>>v.minute>>v.sekunde;
}
int main() { 
    try{
        Vrijeme v1, v2;
        std::cout<<"Unesite prvo vrijeme (h m s): ";
        UnesiVrijeme(v1);
        TestirajVrijeme(v1);
        std::cout<<"Unesite drugo vrijeme (h m s): ";
        UnesiVrijeme(v2);
        TestirajVrijeme(v2);
        std::cout<<"Prvo vrijeme: ";
        IspisiVrijeme(v1);
        std::cout<<"Drugo vrijeme: ";
        IspisiVrijeme(v2);
        std::cout<<"Zbir vremena: ";
        IspisiVrijeme(SaberiVrijeme(v1, v2));
            } catch(std::domain_error e){
                std::cout<<e.what();
            }
    return 0;
     }