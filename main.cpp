#include <iostream>
#include <fstream>
#include <sstream>
#include "Depozit.h"
#include "Comanda.h"
#include "Client.h"
#include "Buchete.h"
#include "insfstoc.h"
#include <algorithm>
#include <cctype>

int main() {
    Depozit depozit;
    std::vector<Comanda> istoricComenzi;

    std::ifstream file("input.txt");
    std::string line;
    bool citesteStoc = false;
    bool citesteComenzi = false;

    while (getline(file, line)) {
        std::istringstream iss(line);
        if (line == "# Stoc initial") {
            citesteStoc = true;
            citesteComenzi = false;
            continue;
        } else if (line == "# Comenzi") {
            citesteStoc = false;
            citesteComenzi = true;
            continue;
        } else if (line == "# Sfarsit") {
            break;
        }

        if (citesteStoc) {
            std::string numeFloare;
            int cantitate;
            iss >> numeFloare >> cantitate;
            depozit.adaugaFloare(numeFloare, cantitate);
        }

        if (citesteComenzi) {
            std::string nume, prenume, numeFloare, culoareHartie;
            int cantitate;
            iss >> nume >> prenume >> numeFloare >> culoareHartie >> cantitate;

                Client client(nume, prenume);
                Buchete buchet(numeFloare, "Nu conteaza culoarea în acest context", culoareHartie, cantitate);
                Comanda comanda(client, depozit);
                comanda.adaugaBuchet(buchet);
                comanda.proceseazaComanda();
                istoricComenzi.push_back(comanda);
            }
        }
        file.close();


        int optiune;
        do {
            std::cout << "\n1. Verifica stoc\n2. Adauga comanda\n3. Istoric comenzi\n0. Iesire\nAlege o optiune: ";
            std::cin >> optiune;

            switch (optiune) {
                case 1:
                    depozit.print();
                    break;
                case 2: {
                    std::string nume, prenume, numeFloare, culoareHartie;
                    int cantitate;
                    std::cout << "Introduceti numele clientului: ";
                    std::cin >> nume >> prenume;
                    std::cout << "Introduceti numele florii: ";
                    std::cin >> numeFloare;
                    std::cout << "Introduceti culoarea hartiei: ";
                    std::cin >> culoareHartie;
                    std::cout << "Introduceti cantitatea: ";
                    std::cin >> cantitate;

                    Client client(nume, prenume);
                    Buchete buchet(numeFloare, "", culoareHartie, cantitate);
                    Comanda comanda(client, depozit);
                    comanda.adaugaBuchet(buchet);

                    try {
                        comanda.proceseazaComanda();
                        istoricComenzi.push_back(comanda);
                        std::cout << "Comanda adaugata cu succes.\n";
                    } catch (const insfstoc &e) {
                        std::cerr << "Eroare la procesarea comenzii: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3:
                    for (const auto &comanda: istoricComenzi) {
                        comanda.print();
                    }
                    break;
                case 0:
                    std::cout << "Iesire din program.\n";
                    break;
                default:
                    std::cout << "Optiune invalida. Reincercati.\n";
                    break;
            }
        } while (optiune != 0);

        return 0;
    }
