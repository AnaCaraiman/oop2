#include "Depozit.h"
#include "EroareStocInsuficient.h"
#include <iostream>
#include <stdexcept>

void Depozit::adaugaFloare(const std::string& nume, const std::string& culoare, int cantitate, double pret) {
    auto key = std::make_pair(nume, culoare);
    stocFlori[key] += cantitate;
    preturiFlori[key] = pret;
}

void Depozit::adaugaAccesoriu(const std::string& nume, int cantitate) {
    stocAccesorii[nume] += cantitate;
}

void Depozit::adaugaCutie(const std::string& tip, int cantitate) {
    stocCutii[tip] += cantitate;
}

bool Depozit::verificaFlori(const std::map<std::pair<std::string, std::string>, int>& flori) const {
    for (const auto& [key, cantitate] : flori) {
        if (!verificaFloare(key.first, key.second, cantitate)) return false;
    }
    return true;
}

bool Depozit::verificaAccesorii(const std::map<std::string, int>& accesorii) const {
    for (const auto& [nume, cantitate] : accesorii) {
        if (!verificaAccesoriu(nume, cantitate)) return false;
    }
    return true;
}


bool Depozit::verificaCutie(const std::string& tip, int cantitate) const {
    auto it = stocCutii.find(tip);
    return it != stocCutii.end() && it->second >= cantitate;
}

void Depozit::scadeFloare(const std::string& nume, const std::string& culoare, int cantitate) {
    auto& stoc = stocFlori[{nume, culoare}];
    if (stoc < cantitate) throw EroareStocInsuficient();
    stoc -= cantitate;
}

void Depozit::scadeAccesoriu(const std::string& nume, int cantitate) {
    auto& stoc = stocAccesorii[nume];
    if (stoc < cantitate) throw EroareStocInsuficient();
    stoc -= cantitate;
}

void Depozit::scadeFlori(const std::map<std::pair<std::string, std::string>, int>& flori) {
    for (const auto& f : flori) {
        scadeFloare(f.first.first, f.first.second, f.second);
    }
}

void Depozit::scadeAccesorii(const std::map<std::string, int>& accesorii) {
    for (const auto& acc : accesorii) {
        scadeAccesoriu(acc.first, acc.second);
    }
}



void Depozit::scadeCutie(const std::string& tip, int cantitate) {
    auto& stoc = stocCutii[tip];
    if (stoc < cantitate) throw EroareStocInsuficient();
    stoc -= cantitate;
}

void Depozit::afiseazaStoc(std::ostream& os) const {
    os << "Stoc flori:\n";
    for (const auto& f : stocFlori) {
        os << "  - " << f.first.first << " " << f.first.second << ": " << f.second
           << " buc la pret " << preturiFlori.at(f.first) << " lei\n";
    }
    os << "Stoc accesorii:\n";
    for (const auto& a : stocAccesorii) {
        os << "  - " << a.first << ": " << a.second << " buc\n";
    }
    os << "Stoc cutii:\n";
    for (const auto& c : stocCutii) {
        os << "  - " << c.first << ": " << c.second << " buc\n";
    }
}

double Depozit::getPretFloare(const std::string& nume, const std::string& culoare) const {
    auto key = std::make_pair(nume, culoare);
    auto it = preturiFlori.find(key);
    if (it != preturiFlori.end()) return it->second;
    throw EroareStocInsuficient();
}

bool Depozit::verificaFloare(const std::string& nume, const std::string& culoare, int cantitate) const {
    auto it = stocFlori.find({nume, culoare});
    return it != stocFlori.end() && it->second >= cantitate;
}

bool Depozit::verificaAccesoriu(const std::string& nume, int cantitate) const {
    auto it = stocAccesorii.find(nume);
    return it != stocAccesorii.end() && it->second >= cantitate;
}



