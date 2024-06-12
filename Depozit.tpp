#include "Depozit.h"
#include <iostream>
#include <memory>
#include <unordered_map>




// Iinitializare instantei singleton
template <typename T>
std::unique_ptr<Depozit<T>> Depozit<T>::instance = nullptr;

// Constructorul privat
template <typename T>
Depozit<T>::Depozit() = default;

// Implementarea metodei getInstance pentru a returna singura instanta
template <typename T>
Depozit<T>& Depozit<T>::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<Depozit<T>>(new Depozit<T>());
    }
    return *instance;
}

// Metoda adauga flori in stoc
template <typename T>
void Depozit<T>::addFlori(const T& name, int quantity) {
    stoc[name] += quantity;
}

// Sterge flori din stoc
template <typename T>
void Depozit<T>::removeFlori(const T& name, int quantity) {
    if (stoc[name] >= quantity) {
        stoc[name] -= quantity;
    }
}

// get cantitate
template <typename T>
int Depozit<T>::getQuantity(const T& name) const {
    return stoc.at(name);
}

// operatorul <<
template <typename T>
std::ostream& operator<<(std::ostream& os, const Depozit<T>& depozit) {
    for (const auto& pair : depozit.stoc) {
        os << "Floare: " << pair.first << ", Cantitate: " << pair.second << std::endl;
    }
    return os;
}

