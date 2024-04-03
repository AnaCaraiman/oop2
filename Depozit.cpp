#include "Depozit.h"
#include <iostream>
#include "insfstoc.h"
void Depozit::adaugaFloare(const std::string& numeFloare, int cantitate) {
    stocFloare[numeFloare] += cantitate;
}

bool Depozit::verificaStoc(const std::string& numeFloare, int cantitate) {
    auto it = stocFloare.find(numeFloare);
    if (it == stocFloare.end() || it->second < cantitate) {
        return false;
    }
    return true;
}

void Depozit::actualizeazaStoc(const std::string& numeFloare, int cantitate) {
    if (verificaStoc(numeFloare, cantitate)) {
        stocFloare[numeFloare] -= cantitate;
    }
}



void Depozit::print() const {
    for (const auto& pereche : stocFloare) {
        std::cout << "Floare: " << pereche.first << ", Stoc: " << pereche.second << std::endl;
    }
}




