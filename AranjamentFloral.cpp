#include "AranjamentFloral.h"
#include "Depozit.h"
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
    auto& depozitFlori = Depozit<std::pair<std::string, std::string>>::getInstance();
    auto& depozitAccesorii = Depozit<std::pair<std::string, AccesoriuTag>>::getInstance();
    auto& depozitCutii = Depozit<std::pair<std::string, CutieTag>>::getInstance();

    for (const auto& f : flori) {
        double pretFloare = depozitFlori.getPretProdus(f.first);
        total += f.second * pretFloare;
    }

    if (!tipCutie.empty()) {
        double pretCutie = depozitCutii.getPretProdus({tipCutie, CutieTag{}});
        total += cantitateCutie * pretCutie;
    }

    for (const auto& acc : accesorii) {
        double pretAcc = depozitAccesorii.getPretProdus({acc.first, AccesoriuTag{}});
        total += acc.second * pretAcc;
    }

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




