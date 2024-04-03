#include "Comanda.h"
#include "iostream"
#include "Comanda.h"
#include "insfstoc.h"
#include <iostream>

Comanda::Comanda(const Client& client, Depozit& depozit) : client(client), depozit(depozit) {}

void Comanda::adaugaBuchet(const Buchete& buchet) {
    buchete.push_back(buchet);
}

void Comanda::proceseazaComanda() {
    try {
        for (auto& buchet : buchete) {
            depozit.verificaStoc(buchet.getname(), buchet.getCantitate());
        depozit.actualizeazaStoc(buchet.getname(), buchet.getCantitate());
        std::cout << "Comanda pentru " << buchet.getname() << " a fost procesata." << std::endl;
    }
}  catch (const insfstoc& e) {
        std::cerr << "Eroare la procesarea comenzii: " << e.what() << std::endl;
    }
}
void Comanda::print() const {
    std::cout << "Comanda pentru clientul " << client.getNume() << " " << client.getPrenume()
              << " include urmatoarele buchete:" << std::endl;
    for (const auto &buchet: buchete) {
        std::cout << "- Buchet de " << buchet.getname() << ", culoare hartie: " << buchet.getCuloareHartie()
                  << ", cantitate: " << buchet.getCantitate() << std::endl;
    }


}