#include "FloareSimpla.h"
#include <sstream>

FloareSimpla::FloareSimpla(const std::string& nume, const std::string& culoare, double pret)
        : Floare(nume, culoare, pret) {}

double FloareSimpla::pretTotal() const {
    return pretPeFir;
}

std::shared_ptr<Floare> FloareSimpla::clone() const {
    return std::make_shared<FloareSimpla>(*this);
}

std::string FloareSimpla::descriere() const {
    std::ostringstream os;
    os << "Floare simpla: " << nume << " " << culoare << ", pret: " << pretPeFir << " lei";
    return os.str();
}

