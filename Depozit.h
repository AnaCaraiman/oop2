#ifndef OOP2_DEPOZIT_H
#define OOP2_DEPOZIT_H

#include <map>
#include <string>
#include <memory>
#include <iostream>

// Clasa template pentru gestionarea stocului de flori
template <typename T>
class Depozit {
private:
    std::map<T, int> stoc;
    static std::unique_ptr<Depozit<T>> instance;

    // Constructor privat
    Depozit();

    // Permitem getInstance sa acceseze constructorul privat
    template <typename U>
    friend class Depozit;

public:
    // Singura instanta a clasei Depozit
    static Depozit<T>& getInstance();

    void addFlori(const T& name, int quantity);
    void removeFlori(const T& name, int quantity);
    int getQuantity(const T& name) const;

    // Operator <<
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Depozit<U>& depozit);
};

#include "Depozit.tpp"

#endif
