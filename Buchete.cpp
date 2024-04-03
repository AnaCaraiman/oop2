#include "Buchete.h"

Buchete::Buchete(const std::string& nume, const std::string& culoare, const std::string& culoareHartie, int cantitate)
        : Flori(nume, culoare), culoareHartie(culoareHartie), cantitate(cantitate) {}

std::string Buchete::getCuloareHartie() const {
    return culoareHartie;
}

int Buchete::getCantitate() const {
    return cantitate;
}





