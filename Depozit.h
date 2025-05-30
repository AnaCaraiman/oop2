#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <map>
#include <memory>
#include <iostream>

// tag
struct AccesoriuTag {};
struct CutieTag {};

// supraincarcare << pentru flori
inline std::ostream& operator<<(std::ostream& os, const std::pair<std::string, std::string>& p) {
    os << p.first << " " << p.second;
    return os;
}

// supraincarcare << pentru accesorii
inline std::ostream& operator<<(std::ostream& os, const std::pair<std::string, AccesoriuTag>& p) {
    os << p.first;
    return os;
}

// supraincarcare << pentru cutii
inline std::ostream& operator<<(std::ostream& os, const std::pair<std::string, CutieTag>& p) {
    os << p.first;
    return os;
}

// clasa template
template <typename T>
class Depozit {
private:
    std::map<T, int> stocProduse;
    std::map<T, double> preturiProduse;

    Depozit() = default;

public:
    Depozit(const Depozit&) = delete;
    Depozit& operator=(const Depozit&) = delete;

    static Depozit& getInstance() {
        static Depozit instance;
        return instance;
    }

    void adaugaProdus(const T& produs, int cantitate, double pret) {
        stocProduse[produs] += cantitate;
        preturiProduse[produs] = pret;
    }

    bool verificaProdus(const T& produs, int cantitate) const {
        auto it = stocProduse.find(produs);
        return it != stocProduse.end() && it->second >= cantitate;
    }

    void scadeProdus(const T& produs, int cantitate) {
        auto it = stocProduse.find(produs);
        if (it != stocProduse.end() && it->second >= cantitate) {
            it->second -= cantitate;
            if (it->second == 0) {
                stocProduse.erase(it);
                preturiProduse.erase(produs);
            }
        } else {
            throw std::runtime_error("Stoc insuficient!");
        }
    }

    double getPretProdus(const T& produs) const {
        auto it = preturiProduse.find(produs);
        return it != preturiProduse.end() ? it->second : 0.0;
    }

    void afiseazaStoc(std::ostream& os) const {
        os << "=== Stoc depozit ===\n";
        for (const auto& [produs, cant] : stocProduse) {
            os << "- " << produs << ": " << cant << " buc";
            double pret = preturiProduse.at(produs);
            if (pret > 0.0)
                os << " la pret " << pret << " lei";
            os << "\n";
        }
    }
};



inline bool operator<(const std::pair<std::string, AccesoriuTag>& a,
                      const std::pair<std::string, AccesoriuTag>& b) {
    return a.first < b.first;
}

inline bool operator<(const std::pair<std::string, CutieTag>& a,
                      const std::pair<std::string, CutieTag>& b) {
    return a.first < b.first;
}


#endif



