#ifndef OOP2_FLORI_H
#define OOP2_FLORI_H

#include <iostream>
#include <memory>
#include <string>

template <typename T>
class Flori {
protected:
    T name;
    T colour;

public:
    Flori(const T& name, const T& colour) : name(name), colour(colour) {}
    Flori() = default;

    void setname(const T& name) { this->name = name; }
    const T& getname() const { return name; }

    void setcolour(const T& colour) { this->colour = colour; }
    const T& getcolour() const { return colour; }

    std::unique_ptr<Flori<T>> clone() const {
        return std::make_unique<Flori<T>>(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Flori& flori) {
        os << "Nume: " << flori.name << ", Culoare: " << flori.colour;
        return os;
    }

    Flori& operator=(const Flori& f) {
        if (this != &f) {
            name = f.name;
            colour = f.colour;
        }
        return *this;
    }

    bool operator==(const Flori& rhs) const {
        return name == rhs.name && colour == rhs.colour;
    }
};

#endif

