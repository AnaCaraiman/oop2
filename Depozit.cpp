
#include "Depozit.h"
#include <iostream>
#include <string>

using namespace std;


Depozit::Depozit(const std::string &name, const std::string &colour, int nrstock): Flori(name,colour),nrstock(nrstock) {}
Depozit::Depozit() {}
Depozit::Depozit(const Depozit &d) : Flori(d.name, d.colour), nrstock(d.nrstock) {}

Depozit &Depozit::operator=(const Depozit &d) {
    Flori::operator=(d);
    nrstock=d.nrstock;
    return *this;
}
int Depozit::getnrstock() const {
    return nrstock;
}
void Depozit::setnrstock(int nrstock) {
    nrstock = nrstock;
}
void Depozit::Read(){
    Flori::Read();
    cout<<"Numar stoc fire floare:"; cin>>nrstock;
}

void Depozit::Print(ostream &os) const {
    Flori::Print(os);
    os << " Nr flori in stoc: " << nrstock;

}

Depozit::~Depozit()=default;


