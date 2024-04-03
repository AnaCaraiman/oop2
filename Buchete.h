#ifndef OOP2_BUCHETE_H
#define OOP2_BUCHETE_H


#pragma once
#include "Flori.h"
#include "iostream"

class Buchete : public Flori {
private:
    std::string culoareHartie;
    int cantitate;

public:
    Buchete(const std::string& nume, const std::string& culoare, const std::string& culoareHartie, int cantitate);
    std::string getCuloareHartie() const;
    int getCantitate() const;
};

#endif //OOP2_BUCHETE_H