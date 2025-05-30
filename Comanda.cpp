#include "Comanda.h"
#include "BuchetSimplu.h"
#include "BuchetPremium.h"
#include "AranjamentFloral.h"
#include "EroareStocInsuficient.h"

Comanda Comanda::creeazaComanda(const Client& client, const std::tm& dataOra,
                                const std::shared_ptr<Floare>& produs,
                                Depozit<std::pair<std::string, std::string>>& depozitFlori,
                                Depozit<std::string>& depozitAccesorii,
                                Depozit<std::string>& depozitCutii) {

    if (auto buchet = std::dynamic_pointer_cast<BuchetSimplu>(produs)) {

        for (const auto& f : buchet->getFlori()) {
            if (!depozitFlori.verificaProdus(f.first, f.second))
                throw EroareStocInsuficient();
        }
        // scade flori
        for (const auto& f : buchet->getFlori()) {
            depozitFlori.scadeProdus(f.first, f.second);
        }
    }

    else if (auto premium = std::dynamic_pointer_cast<BuchetPremium>(produs)) {

        for (const auto& f : premium->getFlori()) {
            if (!depozitFlori.verificaProdus(f.first, f.second))
                throw EroareStocInsuficient();
        }
        // scade flori
        for (const auto& f : premium->getFlori()) {
            depozitFlori.scadeProdus(f.first, f.second);
        }

        for (const auto& acc : premium->getAccesorii()) {
            if (!depozitAccesorii.verificaProdus(acc.first, acc.second))
                throw EroareStocInsuficient();
        }
        // scade accesorii
        for (const auto& acc : premium->getAccesorii()) {
            depozitAccesorii.scadeProdus(acc.first, acc.second);
        }
    }

    else if (auto aranjament = std::dynamic_pointer_cast<AranjamentFloral>(produs)) {

        for (const auto& f : aranjament->getFlori()) {
            if (!depozitFlori.verificaProdus(f.first, f.second))
                throw EroareStocInsuficient();
        }
        // scade flori
        for (const auto& f : aranjament->getFlori()) {
            depozitFlori.scadeProdus(f.first, f.second);
        }

        for (const auto& acc : aranjament->getAccesorii()) {
            if (!depozitAccesorii.verificaProdus(acc.first, acc.second))
                throw EroareStocInsuficient();
        }
        // scade accesorii
        for (const auto& acc : aranjament->getAccesorii()) {
            depozitAccesorii.scadeProdus(acc.first, acc.second);
        }

        if (!depozitCutii.verificaProdus(aranjament->getCutie(), 1))
            throw EroareStocInsuficient();
        // scade cutie
        depozitCutii.scadeProdus(aranjament->getCutie(), 1);
    }


    return Comanda(client, dataOra, produs);
}








