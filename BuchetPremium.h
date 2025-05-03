#ifndef BuchetPremium_H
#define BuchetPremium_H


#include "BuchetSimplu.h"
#include <map>
#include <string>
#include <memory>

class BuchetPremium : public BuchetSimplu {
private:
    std::map<std::string, int> accesorii;

public:
    BuchetPremium();

    void adaugaAccesoriu(const std::string& nume, int cantitate);

    const std::map<std::string, int>& getAccesorii() const;
    std::string descriere() const override;


    double pretTotal() const override;
    std::shared_ptr<Floare> clone() const override;
};

#endif