#pragma once
#include <vector>
#include <string>
#include <unordered_map>

class Depozit {
private:
    std::unordered_map<std::string, int> stocFloare;

public:
    void adaugaFloare(const std::string& numeFloare, int cantitate);
    bool verificaStoc(const std::string& numeFloare, int cantitate);
    void actualizeazaStoc(const std::string& numeFloare, int cantitate);
    void print() const;
};

