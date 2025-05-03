#ifndef POOTEMA2_FLOARE_H
#define POOTEMA2_FLOARE_H

#include <string>
#include <memory>

class Floare {
protected:
    std::string nume;
    std::string culoare;
    double pretPeFir;

public:
    Floare(const std::string& nume, const std::string& culoare, double pret);
    virtual ~Floare() = default;

    virtual double pretTotal() const = 0;
    virtual std::shared_ptr<Floare> clone() const = 0;
    virtual std::string descriere() const = 0;

    const std::string& getNume() const;
    const std::string& getCuloare() const;
    double getPret() const;
};

#endif //POOTEMA2_FLOARE_H

