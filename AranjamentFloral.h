#ifndef ARANJAMENTFLORAL_H
#define ARANJAMENTFLORAL_H

#include "Floare.h"
#include <map>
#include <string>
#include <memory>

class AranjamentFloral : public Floare {
private:
    std::map<std::pair<std::string, std::string>, int> flori;
    std::map<std::pair<std::string, std::string>, double> preturi;
    std::map<std::string, int> accesorii;
    std::string tipCutie;
    int cantitateCutie;

public:
    AranjamentFloral();

    void setCutie(const std::string& tip);
    void setCantitateCutie(int cant);

    void adaugaFloare(const Floare& floare, int cantitate);
    void adaugaAccesoriu(const std::string& acc, int cantitate);

    double pretTotal() const override;
    std::string descriere() const override;
    std::shared_ptr<Floare> clone() const override;

    const std::map<std::pair<std::string, std::string>, int>& getFlori() const;
    const std::map<std::string, int>& getAccesorii() const;
    const std::string& getCutie() const;
    int getCantitateCutie() const;
};

#endif