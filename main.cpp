#include <iostream>
#include <string>
#include "Buchete.h"
#include "Client.h"
#include "Comanda.h"
#include "Depozit.h"

int main() {
    // Crearea unui client folosind Singleton
    auto client = Client::getInstance("Popescu Ion", "Str Mihai Eminescu nr 334");

    // Crearea unui buchet cu tipul de floare, cantitatea si ambalaj
    Buchete<std::string> bouquet("lalele", 5, "verde"); // Tip floare: lalele, Cantitate: 5, Culoare hartie: verde

    // Crearea unei comenzi
    auto order = OrderFactory<std::string>::createOrder("Popescu Ion", client, bouquet);
    order->processOrder();

    // Gestionarea stocului
    auto& stock = Depozit<std::string>::getInstance();
    stock.addFlori("lalele", 20);

    std::cout << "Stock curent: " << std::endl;
    std::cout << stock;

    return 0;
}

