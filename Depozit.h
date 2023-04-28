
#ifndef OOP2_DEPOZIT_H
#define OOP2_DEPOZIT_H

#include <string>
#include "Flori.h"
#include <ostream>
#include<iostream>
#include <memory>
#include <vector>
class Depozit: public Flori {
protected:
    int nrstock;

public:
    Depozit(const std::string &name, const std::string &colour, int nrstock);
    Depozit();
    Depozit(const Depozit& dep);

    int getnrstock() const;
    void setnrstock(int nrstock);
    Depozit& operator=(const Depozit& d);

    void Read();
    void Print(std::ostream &os) const override;
    virtual ~Depozit();
};
#endif //OOP2_DEPOZIT_H
