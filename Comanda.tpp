#include <iostream>
#include <memory>
#include <vector>
#include "Depozit.h"
#include "Client.h"
#include "Buchete.h"
#include "Comanda.h"

// Constructor pentru FlowerOrder
template <typename T>
FlowerOrder<T>::FlowerOrder(const std::string& clientName, std::shared_ptr<Client> client, const Buchete<T>& buchet)
        : clientName(clientName), client(std::move(client)), buchet(buchet) {}

// Metoda processOrder
template <typename T>
void FlowerOrder<T>::processOrder() {
    std::cout << "Client: " << clientName << ", " << buchet << std::endl;
}

// Metoda createOrder
template <typename T>
std::unique_ptr<Comanda<T>> OrderFactory<T>::createOrder(const std::string& clientName, std::shared_ptr<Client> client, const Buchete<T>& buchet) {
    return std::make_unique<FlowerOrder<T>>(clientName, std::move(client), buchet);
}



