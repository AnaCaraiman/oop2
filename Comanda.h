#ifndef COMANDA_H
#define COMANDA_H

#include "Floare.h"
#include <memory>
#include <ctime>
#include <iostream>
#include "Client.h"
#include "Depozit.h"
class Comanda {
private:
    Client client;
    std::tm dataOra{};
    std::shared_ptr<Floare> produs;

public:
    Comanda() = default;
    Comanda(const Client& client, const std::tm& dataOra, std::shared_ptr<Floare> produs);

    void afiseaza(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Comanda& comanda);
    static Comanda creeazaComanda(const Client& client, const std::tm& dataOra,
                                  const std::shared_ptr<Floare>& produs, Depozit& depozit);


};

#endif