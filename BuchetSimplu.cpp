#include "BuchetSimplu.h"
#include <sstream>

BuchetSimplu::BuchetSimplu()
        : Floare("", "", 0.0), culoareHartie("fara") {}

void BuchetSimplu::setHartie(const std::string& hartie) {
    culoareHartie = hartie;
}

void BuchetSimplu::adaugaFloare(const Floare& floare, int cantitate) {
    flori[{floare.getNume(), floare.getCuloare()}] += cantitate;
    preturi[{floare.getNume(), floare.getCuloare()}] = floare.getPret();
}

double BuchetSimplu::pretTotal() const {
    double total = 0.0;
    for (const auto& f : flori) {
        auto it = preturi.find(f.first);
        if (it != preturi.end()) {
            total += f.second * it->second;
        }
    }
    return total;
}

const std::map<std::pair<std::string, std::string>, int>& BuchetSimplu::getFlori() const {
    return flori;
}

std::shared_ptr<Floare> BuchetSimplu::clone() const {
    return std::make_shared<BuchetSimplu>(*this);
}
const std::string& BuchetSimplu::getHartie() const {
    return culoareHartie;
}

std::string BuchetSimplu::descriere() const {
    std::ostringstream os;
    os << "Buchet simplu: ";
    for (const auto& f : getFlori()) {
        os << f.second << "x " << f.first.first << " " << f.first.second << ", ";
    }
    os << "hartie: " << getHartie();
    return os.str();
}






