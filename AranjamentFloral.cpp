#include "AranjamentFloral.h"
#include <sstream>

AranjamentFloral::AranjamentFloral()
        : Floare("", "", 0.0), tipCutie("fara"), cantitateCutie(1) {}

void AranjamentFloral::setCutie(const std::string& tip) {
    tipCutie = tip;
}

void AranjamentFloral::setCantitateCutie(int cant) {
    cantitateCutie = cant;
}

void AranjamentFloral::adaugaFloare(const Floare& floare, int cantitate) {
    flori[{floare.getNume(), floare.getCuloare()}] += cantitate;
    preturi[{floare.getNume(), floare.getCuloare()}] = floare.getPret();
}

void AranjamentFloral::adaugaAccesoriu(const std::string& acc, int cantitate) {
    accesorii[acc] += cantitate;
}

double AranjamentFloral::pretTotal() const {
    double total = 0.0;
    for (const auto& f : flori) {
        auto it = preturi.find(f.first);
        if (it != preturi.end()) {
            total += f.second * it->second;
        }
    }
    total += cantitateCutie * 5.0;  // preț fix de 5 lei per cutie
    total += accesorii.size() * 1.5; // opțional: preț generic pentru accesorii
    return total;
}

const std::map<std::pair<std::string, std::string>, int>& AranjamentFloral::getFlori() const {
    return flori;
}

const std::map<std::string, int>& AranjamentFloral::getAccesorii() const {
    return accesorii;
}

const std::string& AranjamentFloral::getCutie() const {
    return tipCutie;
}

int AranjamentFloral::getCantitateCutie() const {
    return cantitateCutie;
}

std::string AranjamentFloral::descriere() const {
    std::ostringstream os;
    os << "Aranjament floral: ";
    for (const auto& f : flori) {
        os << f.second << "x " << f.first.first << " " << f.first.second << ", ";
    }
    os << "cutie: " << tipCutie << ", accesorii: ";
    for (const auto& acc : accesorii) {
        os << acc.second << "x " << acc.first << " ";
    }
    return os.str();
}

std::shared_ptr<Floare> AranjamentFloral::clone() const {
    return std::make_shared<AranjamentFloral>(*this);
}




