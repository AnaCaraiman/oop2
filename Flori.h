

#ifndef _FLORI_H
#define _FLORI_H

#include <cstring>
#include <ostream>
#include <string>

class Flori {
protected:
    std::string name;
    std::string colour;

public:
    Flori(const std::string &name, const std::string &colour);
    Flori();
    //set,get
    void setname(const std::string &name);
    const std::string &getname() const;

    void setcolour(const std::string &colour);
    const std::string &getcolour() const;

    //OPERATORUL <<
    friend std::ostream &operator<<(std::ostream &os, const Flori &flori);

    //operatorul =
    Flori& operator=(const Flori& f);

    bool operator==(const Flori &rhs) const;

    //functii virtuale
    virtual void Read() = 0;
    virtual void Print(std::ostream &os) const;
    virtual ~Flori();
};

#endif //OOP2_FLORI_H
