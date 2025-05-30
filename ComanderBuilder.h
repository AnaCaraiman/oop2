#ifndef COMANDABUILDER_H
#define COMANDABUILDER_H

#include "Client.h"
#include "Floare.h"
#include "Comanda.h"
#include "Depozit.h"
#include <memory>
#include <ctime>

//  Clasa Builder pentru crearea comenzilor
class ComandaBuilder {
private:
    Client client{"", ""};
    std::shared_ptr<Floare> produs;
    std::tm dataOra{};

public:
    ComandaBuilder& setClient(const Client& c) {
        client = c;
        return *this;
    }

    ComandaBuilder& setProdus(const std::shared_ptr<Floare>& p) {
        produs = p;
        return *this;
    }

    ComandaBuilder& setDataOra(const std::tm& dt) {
        dataOra = dt;
        return *this;
    }

    Comanda build() {
        if (!produs) {
            throw std::runtime_error("Produsul nu a fost setat!");
        }

        // construim folosind depozitul global (Singleton)
        auto& depozit = Depozit<std::pair<std::string, std::string>>::getInstance();
        return Comanda::creeazaComanda(client, dataOra, produs,
                                       Depozit<std::pair<std::string, std::string>>::getInstance(),
                                       Depozit<std::string>::getInstance(),
                                       Depozit<std::string>::getInstance());

    }
};

#endif

