

#ifndef POOTEMA2_FLOARESIMPLA_H
#define POOTEMA2_FLOARESIMPLA_H



#include "Floare.h"
#include <memory>
#include <string>

class FloareSimpla : public Floare {
public:
    FloareSimpla(const std::string& nume, const std::string& culoare, double pret);

    double pretTotal() const override;
    std::shared_ptr<Floare> clone() const override;
    std::string descriere() const override;
};



#endif //POOTEMA2_FLOARESIMPLA_H
