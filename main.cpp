#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <map>

#include "Depozit.h"
#include "Client.h"
#include "Comanda.h"
#include "Floare.h"
#include "BuchetSimplu.h"
#include "BuchetPremium.h"
#include "FloareSimpla.h"
#include "AranjamentFloral.h"
#include "EroareInputInvalid.h"
#include "EroareStocInsuficient.h"

std::tm parseazaDataOra(const std::string& data, const std::string& ora) {
    std::tm tm{};
    std::istringstream ss(data + " " + ora);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
    if (ss.fail()) throw EroareInputInvalid();
    return tm;
}

std::tm dataOraCurenta() {
    std::time_t t = std::time(nullptr);
    return *std::localtime(&t);
}

int main() {
    Depozit depozit;
    std::vector<Comanda> istoric;

    try {
        std::ifstream fin("input.txt");
        if (!fin) {
            throw std::ios_base::failure("Fisierul input.txt nu a putut fi deschis");
        }

        std::string linie;
        int nrStoc = 0;
        fin >> nrStoc;
        fin.ignore();
        for (int i = 0; i < nrStoc; ++i) {
            std::getline(fin, linie);
            std::istringstream ss(linie);
            std::string tip;
            ss >> tip;
            if (tip == "floare") {
                std::string nume, culoare;
                int cant;
                double pret;
                ss >> nume >> culoare >> cant >> pret;
                depozit.adaugaFloare(nume, culoare, cant, pret);
            } else if (tip == "accesoriu") {
                std::string nume;
                int cant;
                ss >> nume >> cant;
                depozit.adaugaAccesoriu(nume, cant);
            } else if (tip == "cutie") {
                std::string tipCutie;
                int cant;
                ss >> tipCutie >> cant;
                depozit.adaugaCutie(tipCutie, cant);
            }
        }

        int nrComenzi;
        fin >> nrComenzi;
        fin.ignore();

        for (int i = 0; i < nrComenzi; ++i) {
            std::getline(fin, linie);
            try {
                std::istringstream ss(linie);
                std::string nume, prenume, tipProdus;
                ss >> nume >> prenume >> tipProdus;

                std::map<std::pair<std::string, std::string>, int> flori;
                std::map<std::string, int> accesorii;
                std::string hartie, cutie;
                std::string token;
                std::vector<std::string> restTokens;

                while (ss >> token) restTokens.push_back(token);

                if (restTokens.size() < 2)
                    throw EroareInputInvalid();
                std::string data = restTokens[restTokens.size() - 2];
                std::string ora = restTokens[restTokens.size() - 1];
                std::tm dataOra = parseazaDataOra(data, ora);
                restTokens.resize(restTokens.size() - 2);

                size_t i = 0;
                while (i + 2 <= restTokens.size() && restTokens[i] != "hartie" && restTokens[i] != "cutie" && restTokens[i] != "accesorii:") {
                    std::string numeFloare = restTokens[i];
                    std::string culoare = restTokens[i + 1];
                    int cant = std::stoi(restTokens[i + 2]);
                    flori[{numeFloare, culoare}] += cant;
                    i += 3;
                }

                while (i < restTokens.size()) {
                    if (restTokens[i] == "hartie" && i + 1 < restTokens.size()) {
                        hartie = restTokens[i + 1];
                        i += 2;
                    } else if (restTokens[i] == "cutie" && i + 1 < restTokens.size()) {
                        cutie = restTokens[i + 1];
                        i += 2;
                    } else if (restTokens[i] == "accesorii:") {
                        ++i;
                        while (i + 1 < restTokens.size()) {
                            std::string numeAcc = restTokens[i];
                            std::string cantStr = restTokens[i + 1];
                            try {
                                int cantAcc = std::stoi(cantStr);
                                accesorii[numeAcc] += cantAcc;
                                i += 2;
                            } catch (...) {
                                break;
                            }
                        }
                    } else break;
                }

                Client client(nume, prenume);
                std::shared_ptr<Floare> produs;

                if (tipProdus == "buchet") {
                    auto b = std::make_shared<BuchetSimplu>();
                    for (const auto& f : flori)
                        b->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                    b->setHartie(hartie);
                    produs = b;
                } else if (tipProdus == "premium") {
                    auto p = std::make_shared<BuchetPremium>();
                    for (const auto& f : flori)
                        p->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                    for (const auto& a : accesorii)
                        p->adaugaAccesoriu(a.first, a.second);
                    p->setHartie(hartie);
                    produs = p;
                } else if (tipProdus == "aranjamentfloral") {
                    auto a = std::make_shared<AranjamentFloral>();
                    for (const auto& f : flori)
                        a->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                    for (const auto& acc : accesorii)
                        a->adaugaAccesoriu(acc.first, acc.second);
                    a->setCutie(cutie);
                    produs = a;
                } else {
                    throw EroareInputInvalid();
                }

                istoric.push_back(Comanda::creeazaComanda(client, dataOra, produs, depozit));

            } catch (const EroareInputInvalid& e) {
                std::cerr << "[Input Invalid] " << e.what() << "\n";
            } catch (const EroareStocInsuficient& e) {
                std::cerr << "[Stoc Insuficient] " << e.what() << "\n";
            } catch (const std::exception& e) {
                std::cerr << "[Alta Eroare] " << e.what() << "\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Eroare la initializare: " << e.what() << "\n";
        return 1;
    }


    int opt;
    do {
        std::cout << "\n=== Meniu ===\n";
        std::cout << "1. Afiseaza stocuri\n2. Afiseaza comenzi\n3. Adauga comanda manual\n0. Iesire\nAlege optiunea: ";
        std::cin >> opt;
        switch (opt) {
            case 1:
                depozit.afiseazaStoc(std::cout);
                break;
            case 2:
                for (const auto& c : istoric)
                    std::cout << c << "\n";
                break;
            case 3: {
                std::string nume, prenume, tipProdus, hartie, cutie;
                std::map<std::pair<std::string, std::string>, int> flori;
                std::map<std::string, int> accesorii;
                std::cout << "Nume client: "; std::cin >> nume;
                std::cout << "Prenume client: "; std::cin >> prenume;
                std::cout << "Tip produs (buchet/premium/aranjamentfloral): "; std::cin >> tipProdus;
                int n;
                std::cout << "Numar tipuri de flori: "; std::cin >> n;
                for (int i = 0; i < n; ++i) {
                    std::string numeF, culoareF; int cant;
                    std::cout << "Floare (nume culoare cant): "; std::cin >> numeF >> culoareF >> cant;
                    flori[{numeF, culoareF}] += cant;
                }
                if (tipProdus == "buchet" || tipProdus == "premium") {
                    std::cout << "Hartie: "; std::cin >> hartie;
                }
                if (tipProdus == "aranjamentfloral") {
                    std::cout << "Cutie: "; std::cin >> cutie;
                }
                if (tipProdus == "premium" || tipProdus == "aranjamentfloral") {
                    int m;
                    std::cout << "Numar accesorii: "; std::cin >> m;
                    for (int i = 0; i < m; ++i) {
                        std::string numeAcc; int cantAcc;
                        std::cout << "Accesoriu (nume cant): "; std::cin >> numeAcc >> cantAcc;
                        accesorii[numeAcc] += cantAcc;
                    }
                }
                try {
                    std::tm dataOra = dataOraCurenta();
                    Client client(nume, prenume);
                    std::shared_ptr<Floare> produs;
                    if (tipProdus == "buchet") {
                        auto b = std::make_shared<BuchetSimplu>();
                        for (const auto& f : flori)
                            b->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                        b->setHartie(hartie);
                        produs = b;
                    } else if (tipProdus == "premium") {
                        auto p = std::make_shared<BuchetPremium>();
                        for (const auto& f : flori)
                            p->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                        for (const auto& a : accesorii)
                            p->adaugaAccesoriu(a.first, a.second);
                        p->setHartie(hartie);
                        produs = p;
                    } else if (tipProdus == "aranjamentfloral") {
                        auto a = std::make_shared<AranjamentFloral>();
                        for (const auto& f : flori)
                            a->adaugaFloare(FloareSimpla(f.first.first, f.first.second, depozit.getPretFloare(f.first.first, f.first.second)), f.second);
                        for (const auto& acc : accesorii)
                            a->adaugaAccesoriu(acc.first, acc.second);
                        a->setCutie(cutie);
                        produs = a;
                    } else {
                        throw EroareInputInvalid();
                    }
                    istoric.push_back(Comanda::creeazaComanda(client, dataOra, produs, depozit));
                    std::cout << "Comanda a fost adaugata cu succes.\n";
                } catch (const std::exception& e) {
                    std::cerr << "Eroare la adaugarea comenzii: " << e.what() << "\n";
                }
                break;
            }
            case 0:
                std::cout << "La revedere!\n";
                break;
            default:
                std::cout << "Optiune invalida.\n";
        }
    } while (opt != 0);

    return 0;
}
