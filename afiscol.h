#ifndef afiscol_H
#define afiscol_H

#include <iostream>
#include <type_traits>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Comanda.h"

// operator pentru perechi (ex: std::pair)
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// funct template afisarea colectiilor
template <typename Container>
std::enable_if_t<!std::is_convertible_v<Container, std::string>, std::ostream&>
afiseazaColectie(std::ostream& os, const Container& c) {
    os << "[";
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << *it;
        if (std::next(it) != c.end()) os << ", ";
    }
    os << "]";
    return os;
}
void afiseazaCeleMaiScumpeComenzi(const std::vector<Comanda>& istoric, int topN) {
    std::vector<Comanda> copii = istoric;
    std::sort(copii.begin(), copii.end(), [](const Comanda& a, const Comanda& b) {
        return a.getPretTotal() > b.getPretTotal();
    });

    for (int i = 0; i < std::min(topN, (int)copii.size()); ++i) {
        std::cout << copii[i] << "\n";
    }
}

#endif

