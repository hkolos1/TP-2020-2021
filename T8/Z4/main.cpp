//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <map>
#include <string>

std::string ZamijeniPremaRjecniku(const std::string &str, const std::map<std::string, std::string> &mapa){
    std::string manevar;
    int prviIndex=0;
    for(int i=0; i<str.size(); i++){
        if(str.at(i)==' '){
            std::string rijec = str.substr(prviIndex, i - prviIndex);
        if(mapa.count(rijec)==1){
            manevar+=mapa.find(rijec)-> second + ' ';
        }
        else {
            manevar+=rijec+' ';
        }
        prviIndex=i+1;
        }
    }
    std::string rijec = str.substr(prviIndex, str.size()-prviIndex);
    if(mapa.count(rijec)==1){
        manevar+=mapa.find(rijec)-> second;
    }
    else {
        manevar +=rijec;
    }
    return manevar;
}

int main ()
{
/*std::map<std::string, std::string> moj_rjecnik{
    {"jabuka", "apple"}, {"da", "yes"},
    {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}
    };
std::cout << ZamijeniPremaRjecniku("kako da ne", moj_rjecnik);
*/
	return 0;
}