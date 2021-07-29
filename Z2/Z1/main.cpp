// TP 2018/2019: Zadaća 2, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

enum class Polje {
  Prazno,
  Posjeceno,
  Mina,
  BlokiranoPrazno,
  BlokiranoPosjeceno,
  BlokiranoMina
};
enum class Smjerovi {
  GoreLijevo,
  Gore,
  GoreDesno,
  Desno,
  DoljeDesno,
  Dolje,
  DoljeLijevo,
  Lijevo
};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };

enum class KodoviGresaka {
  PogresnaKomanda,
  NedostajeParmetar,
  SuvisanParametar,
  NeispravanParametar
};
enum class Komande {
  PomjeriJednoMjesto,
  PomjeriDalje,
  Blokiraj,
  Deblokiraj,
  PrikaziOkolinu,
  ZavrsiIgru,
  KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
  for (int i{0}; i < mine.size(); i++) {
    if (mine.at(i).size() != 2) {
      throw std::domain_error("Ilegalan format zadavanja mina");
    }
    if (mine.at(i).at(0) >= n || mine.at(i).at(0) >= n ||
        mine.at(i).at(0) < 0 || mine.at(i).at(0) < 0) {
      throw std::domain_error("Ilegalne pozicije mina");
    }
  }

  if (n <= 0)
    throw std::domain_error("Ilegalna veličina");

  Tabla tabla(n, std::vector<Polje>(n, Polje::Prazno));
  for (int i{0}; i < mine.size(); i++) {
    tabla.at(mine.at(i).at(0)).at(mine.at(i).at(1)) = Polje::Mina;
  }
  return tabla;
}

/*std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{ if (x >= polja.size() || y >= polja.size() || x < 0 || y < 0) throw
std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ")ne
postoji");

  int brojac{0};
  std::vector<std::vector<int>> okolina(3, std::vector<int>(3));
  for (int i{x - 1}; i < x + 1; i++) {
    for (int j{y - 1}; j < y + 1; j++) {
      if (polje.at(i).at(j))
    }
  }
}*/

void BlokirajPolje(Tabla &polja, int x, int y) {
  if (x >= polja.size() || y >= polja.size() || x < 0 || y < 0)
    throw std::domain_error("Polje (" + std::to_string(x) + "," +
                            std::to_string(y) + ")ne postoji");
  if (polja.at(x).at(y) == Polje::Mina)
    polja.at(x).at(y) = Polje::BlokiranoMina;
  if (polja.at(x).at(y) == Polje::Prazno)
    polja.at(x).at(y) = Polje::BlokiranoPrazno;
  if (polja.at(x).at(y) == Polje::Posjeceno)
    polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
  if (x >= polja.size() || y >= polja.size() || x < 0 || y < 0)
    throw std::domain_error("Polje (" + std::to_string(x) + "," +
                            std::to_string(y) + ")ne postoji");
  if (polja.at(x).at(y) == Polje::BlokiranoMina)
    polja.at(x).at(y) = Polje::Mina;
  if (polja.at(x).at(y) == Polje::BlokiranoPrazno)
    polja.at(x).at(y) = Polje::Prazno;
  if (polja.at(x).at(y) == Polje::BlokiranoPosjeceno)
    polja.at(x).at(y) = Polje::Posjeceno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
  if (smjer == Smjerovi::Desno) {
    y++;
  } else if (smjer == Smjerovi::Dolje) {
    x++;
  } else if (smjer == Smjerovi::DoljeDesno) {
    x++;
    y++;
  } else if (smjer == Smjerovi::DoljeLijevo) {
    x++;
    y--;
  } else if (smjer == Smjerovi::Gore)
    x--;
  else if (smjer == Smjerovi::GoreDesno) {
    x--;
    y++;
  } else if (smjer == Smjerovi::GoreLijevo) {
    x--;
    y--;
  } else if (smjer == Smjerovi::Lijevo) {
    y--;
  }
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
  if (novi_x >= polja.size() || novi_x < 0 || novi_y >= polja.at(0).size() ||
      novi_y < 0)
    throw std::range_error("Izlazak van igrace table");
  if (polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina ||
      polja.at(novi_x).at(novi_y) == Polje::BlokiranoPosjeceno ||
      polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno)
    throw std::logic_error("Blokirano polje");
  if (polja.at(novi_x).at(novi_y) == Polje::Mina) {
    polja =
        Tabla(polja.size(), std::vector<Polje>(polja.size(), Polje::Prazno));
    return Status::KrajPoraz;
  }
  polja.at(x).at(y) = Polje::Posjeceno;
  for (int i{0}; i < polja.size(); i++) {
    for (int j{0}; j < polja.size(); j++) {
      if (polja.at(i).at(j) == Polje::Prazno && i != novi_x && j != novi_y) {
        x = novi_x;
        y = novi_y;
        return Status::NijeKraj;
      }
    }
  }
  return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka k) {
  if (k == KodoviGresaka::PogresnaKomanda)
    std::cout << "Nerazumljiva komanda!";
  else if (k == KodoviGresaka::NedostajeParmetar)
    std::cout << "Komanda trazi parametar koji nije naveden!";
  else if (k == KodoviGresaka::NeispravanParametar)
    std::cout << "Parametar komande nije ispravan!";
  else if (k == KodoviGresaka::SuvisanParametar)
    std::cout << "Zadan je suvisan parametar nakon komande!";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,
                 KodoviGresaka &greska) {
  std::string s;
  std::getline(std::cin, s);
  std::string k;
  for (int i{0}; i < s.length(); i++) {
    if (s.at(i) != ' ')
      k += s.at(i);
  }
  if (k.at(0) == 'P' && k.at(1) == '1') {

    if (k == "P1GL") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::GoreLijevo;
      return true;
    } else if (k == "P1G") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::Gore;
      return true;
    } else if (k == "P1GD") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::GoreDesno;
      return true;
    } else if (k == "P1D") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::Desno;
      return true;
    } else if (k == "P1DoD") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::DoljeDesno;
      return true;
    } else if (k == "P1Do") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::Dolje;
      return true;
    } else if (k == "P1DoL") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::DoljeLijevo;
      return true;
    } else if (k == "P1L") {
      komanda = Komande::PomjeriJednoMjesto;
      smjer = Smjerovi::Lijevo;
      return true;
    }
    if (k.size()< 2){
        
    }
  }
  if (k.at(0)=='P' && k.at(1)=='>'){
      
  }
}

int main() {
 
  return 0;
}