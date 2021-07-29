/* 
    TP 2018/2019: Tutorijal 5, Zadatak 7
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <deque>
#include <stdexcept>

template <typename PokIliIter>
void Suma(PokIliIter pocetak, PokIliIter kraj, decltype(*pocetak) suma){
    if(pocetak == kraj)
    return;
    suma +=*pocetak;
    Suma(++pocetak, kraj, suma);
}
template <typename PokIliIter>
auto SumaBloka(PokIliIter pocetak, PokIliIter kraj) -> decltype(*pocetak + *pocetak){
    if(pocetak == kraj)
    throw std::range_error("Blok je prazan");
    if( kraj - pocetak == 1)
    return *pocetak;
    decltype(*pocetak + *pocetak) suma= *pocetak + * (pocetak + 1);
    pocetak += 2;
    Suma(pocetak, kraj, suma);
    return suma;
}


int main ()
{
    int vel;
    std::cout<<"Unesite velicinu niza: ";
    std::cin>>vel;
    std::deque<double> dek(vel);
    std::cout<<"Unesite elemente niza: ";
    for( int i =0; i < vel; i++)
    std::cin>>dek.at(i);
    try{
        auto suma = SumaBloka(dek.begin(), dek.end());
        std::cout<<"Suma elemenata u nizu iznosi " << suma;

    } catch (std::range_error exc){
        std::cout<< exc.what() << std::endl;
    }
	return 0;
}