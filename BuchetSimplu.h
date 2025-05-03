#ifndef BuchetSimplu_H
#define BuchetSimplu_H


#include "Floare.h"
#include <map>
#include <memory>

class BuchetSimplu : public Floare {
private:
    std::map<std::pair<std::string, std::string>, int> flori;
    std::map<std::pair<std::string, std::string>, double> preturi;
    std::string culoareHartie;

public:
    BuchetSimplu();
    void setHartie(const std::string& hartie);
    const std::string& getHartie() const;
    void adaugaFloare(const Floare& floare, int cantitate);
    double pretTotal() const override;
    std::string descriere() const override;
    std::shared_ptr<Floare> clone() const override;
    const std::map<std::pair<std::string, std::string>, int>& getFlori() const;
};



#endif


