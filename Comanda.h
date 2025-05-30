#ifndef COMANDA_H
#define COMANDA_H

#include "Client.h"
#include "Floare.h"
#include "Depozit.h"
#include <memory>
#include <ctime>
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

class Comanda {
private:
    Client client;
    std::tm dataOra;
    std::shared_ptr<Floare> produs;

public:
    Comanda(const Client& c, const std::tm& dt, const std::shared_ptr<Floare>& p)
            : client(c), dataOra(dt), produs(p) {}

    static Comanda creeazaComanda(const Client& client, const std::tm& dataOra,
                                  const std::shared_ptr<Floare>& produs,
                                  Depozit<std::pair<std::string, std::string>>& depozitFlori,
                                  Depozit<std::string>& depozitAccesorii,
                                  Depozit<std::string>& depozitCutii);

    double getPretTotal() const {
        return produs->pretTotal();
    }

    friend std::ostream& operator<<(std::ostream& os, const Comanda& c) {
        os << "Client: " << c.client << "\n";
        os << "Data: " << std::put_time(&c.dataOra, "%Y-%m-%d %H:%M") << "\n";
        os << "Produs:\n" << c.produs->descriere() << "\n";
        os << "Pret total: " << c.getPretTotal() << " lei\n";
        return os;
    }
};

#endif

