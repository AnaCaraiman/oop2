#include "Floare.h"

Floare::Floare(const std::string& nume, const std::string& culoare, double pret)
        : nume(nume), culoare(culoare), pretPeFir(pret) {}

const std::string& Floare::getNume() const {
    return nume;
}

const std::string& Floare::getCuloare() const {
    return culoare;
}

double Floare::getPret() const {
    return pretPeFir;
}


