#ifndef OOP2_BUCHETE_H
#define OOP2_BUCHETE_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Flori.h"

// Clasa template pentru gestionarea unui buchet de flori de tip generic T
template <typename T>
class Buchete {
private:
    T flowerType;
    int quantity;
    std::string paperColor;

public:
    // Constructor
    Buchete(const T& flowerType, int quantity, const std::string& paperColor)
            : flowerType(flowerType), quantity(quantity), paperColor(paperColor) {}

    // Metode get
    const T& getFlowerType() const { return flowerType; }
    int getQuantity() const { return quantity; }
    const std::string& getPaperColor() const { return paperColor; }

    // Operator << pentru afișarea buchetului de flori
    friend std::ostream& operator<<(std::ostream& os, const Buchete<T>& buchet) {
        os << "Flower: " << buchet.flowerType
           << ", Quantity: " << buchet.quantity
           << ", Paper Color: " << buchet.paperColor;
        return os;
    }

    // Operator de egalitate
    bool operator==(const Buchete<T>& rhs) const {
        return flowerType == rhs.flowerType &&
               quantity == rhs.quantity &&
               paperColor == rhs.paperColor;
    }

    // Operator de atribuire
    Buchete<T>& operator=(const Buchete<T>& d) {
        if (this != &d) {
            flowerType = d.flowerType;
            quantity = d.quantity;
            paperColor = d.paperColor;
        }
        return *this;
    }
};

#endif





