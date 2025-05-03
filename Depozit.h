#ifndef Depozit_H
#define Depozit_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

class Depozit {
private:
    std::map<std::pair<std::string, std::string>, int> stocFlori;
    std::map<std::pair<std::string, std::string>, double> preturiFlori;
    std::map<std::string, int> stocAccesorii;
    std::map<std::string, int> stocCutii;

public:
    void adaugaFloare(const std::string& nume, const std::string& culoare, int cantitate, double pret);
    void adaugaAccesoriu(const std::string& nume, int cantitate);
    void adaugaCutie(const std::string& tip, int cantitate);

    bool verificaFloare(const std::string& nume, const std::string& culoare, int cantitate) const;
    bool verificaAccesoriu(const std::string& nume, int cantitate) const;
    bool verificaCutie(const std::string& tip, int cantitate) const;

    bool verificaFlori(const std::map<std::pair<std::string, std::string>, int>& flori) const;
    bool verificaAccesorii(const std::map<std::string, int>& accesorii) const;

    void scadeFloare(const std::string& nume, const std::string& culoare, int cantitate);
    void scadeAccesoriu(const std::string& nume, int cantitate);
    void scadeCutie(const std::string& tip, int cantitate);

    void scadeFlori(const std::map<std::pair<std::string, std::string>, int>& flori);
    void scadeAccesorii(const std::map<std::string, int>& accesorii);

    void afiseazaStoc(std::ostream& os) const;
    double getPretFloare(const std::string& nume, const std::string& culoare) const;
};




#endif