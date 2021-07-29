/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <algorithm>
#include <iostream>
#include <set>

template <class T>
std::set<T> Unija(const std::set<T>& S1, const std::set<T>& S2){
    std::set<T> izlaz;
    std::copy(S1.begin(), S1.end(), std::inserter(izlaz, izlaz.begin()));
    std::copy(S2.begin(), S2.end(), std::inserter(izlaz, izlaz.begin()));
    return izlaz;
}
template <class T>
std::set<T> Presjek(const std::set<T>& S1, const std::set<T>& S2){
std::set<T> izlaz;
for(auto it=S1.begin(); it!=S1.end(); ++it )
if(S2.find(*it)!=S2.end())
izlaz.insert(*it);
return izlaz;
}
int main ()
{
	return 0;
}