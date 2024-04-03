
#ifndef OOP2_COMANDA_H
#define OOP2_COMANDA_H

#pragma once
#include "Depozit.h"
#include "Client.h"
#include "Buchete.h"

class Comanda {
private:
    Client client;
    std::vector<Buchete> buchete;
    Depozit& depozit;  // Referință la depozit pentru a verifica și actualiza stocul

public:
    Comanda(const Client& client, Depozit& depozit);
    void adaugaBuchet(const Buchete& buchet);
    void proceseazaComanda();
    std::string getNumeClient() const;
    std::string getPrenumeClient() const;
    void print() const;
};


#endif //OOP2_COMANDA_H
