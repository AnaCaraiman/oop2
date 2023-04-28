#include "Buchete.h"
#include <iostream>
using namespace std;
int Buchete::nrbuchete = 0;
Buchete::Buchete(const std::string &name, const std::string &colour, int nrfire,const std::string &hcolour):Flori(name,colour),nrfire(nrfire),hcolour(hcolour){++nrbuchete;}
Buchete::Buchete() {}
Buchete::Buchete(const Buchete &d) : Flori(d.name, d.colour), nrfire(d.nrfire),hcolour(d.hcolour) {}
int Buchete::getnrbuchete() {
    return nrbuchete;
}

void Buchete::setnrbuchete(int nrbuchete) {
    nrbuchete = nrbuchete;
}
void  Buchete::Read(){
     Flori::Read();
    cout<<"Introduceti culoarea pentru hartia buchetului: "; cin>>hcolour;
    cout<<"Introduceti numarul de fire dorite: "; cin>>nrfire;

}

void Buchete::Print(ostream &os) const {
    Flori::Print(os);
    os << " Culoare hartie selectata: " << hcolour;
    os<<"Nr fire selectate:"<< nrfire;
}



