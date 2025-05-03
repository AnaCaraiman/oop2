#include "BuchetPremium.h"
#include <sstream>


BuchetPremium::BuchetPremium() = default;

void BuchetPremium::adaugaAccesoriu(const std::string& nume, int cantitate) {
    accesorii[nume] += cantitate;
}

const std::map<std::string, int>& BuchetPremium::getAccesorii() const {
    return accesorii;
}

double BuchetPremium::pretTotal() const {
    double total = BuchetSimplu::pretTotal();
    for (const auto& acc : accesorii) {
        total += acc.second * 5.0; // presupunem 5 lei / accesoriu
    }
    return total;
}

std::shared_ptr<Floare> BuchetPremium::clone() const {
    return std::make_shared<BuchetPremium>(*this);
}

std::string BuchetPremium::descriere() const {
    std::ostringstream os;
    os << "Buchet premium: ";
    for (const auto& f : getFlori()) {
        os << f.second << "x " << f.first.first << " " << f.first.second << ", ";
    }
    os << "hartie: " << getHartie() << ", accesorii: ";
    for (const auto& a : accesorii) {
        os << a.second << "x " << a.first << ", ";
    }
    return os.str();
}

