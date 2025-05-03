#include "Comanda.h"
#include <sstream>
#include "BuchetSimplu.h"
#include "Depozit.h"
#include "BuchetPremium.h"
#include "AranjamentFloral.h"
#include "EroareStocInsuficient.h"

Comanda::Comanda(const Client& client, const std::tm& dataOra, std::shared_ptr<Floare> produs)
        : client(client), dataOra(dataOra), produs(std::move(produs)) {}

Comanda Comanda::creeazaComanda(const Client& client, const std::tm& dataOra,
                                const std::shared_ptr<Floare>& produs, Depozit& depozit) {
    // Buchet simplu
    if (auto buchet = std::dynamic_pointer_cast<BuchetSimplu>(produs)) {
        if (!depozit.verificaFlori(buchet->getFlori()))
            throw EroareStocInsuficient();
        depozit.scadeFlori(buchet->getFlori());
    }

        // Buchet premium
    else if (auto premium = std::dynamic_pointer_cast<BuchetPremium>(produs)) {
        if (!depozit.verificaFlori(premium->getFlori()))
            throw EroareStocInsuficient();
        if (!depozit.verificaAccesorii(premium->getAccesorii()))
            throw EroareStocInsuficient();
        depozit.scadeFlori(premium->getFlori());
        depozit.scadeAccesorii(premium->getAccesorii());
    }

        // Aranjament floral
    else if (auto aranjament = std::dynamic_pointer_cast<AranjamentFloral>(produs)) {
        if (!depozit.verificaFlori(aranjament->getFlori()))
            throw EroareStocInsuficient();
        if (!depozit.verificaAccesorii(aranjament->getAccesorii()))
            throw EroareStocInsuficient();
        if (!depozit.verificaCutie(aranjament->getCutie(), 1))
            throw EroareStocInsuficient();

        depozit.scadeFlori(aranjament->getFlori());
        depozit.scadeAccesorii(aranjament->getAccesorii());
        depozit.scadeCutie(aranjament->getCutie(), 1);  // se scade o singură cutie
    }

    return Comanda(client, dataOra, produs);
}


void Comanda::afiseaza(std::ostream& os) const {
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &dataOra);
    os << "Client: " << client << "\n";
    os << "Produs: " << produs->descriere() << "\n";
    os << "Pret total: " << produs->pretTotal() << " lei\n";
    os << "Data si ora: " << buffer << "\n";
}


std::ostream& operator<<(std::ostream& os, const Comanda& comanda) {
    comanda.afiseaza(os);
    return os;
}





