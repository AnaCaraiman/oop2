
#ifndef OOP2_COMANDA_H
#define OOP2_COMANDA_H

#include <iostream>
#include <memory>
#include <string>
#include "Client.h"
#include "Buchete.h"

// Clasa abstracta template
template <typename T>
class Comanda {
public:
    virtual void processOrder() = 0;
    virtual ~Comanda() = default;
};

// Clasa concreta template pentru comanda de flori
template <typename T>
class FlowerOrder : public Comanda<T> {
private:
    std::string clientName;
    std::shared_ptr<Client> client;
    Buchete<T> buchet;

public:
    // Constructor
    FlowerOrder(const std::string& clientName, std::shared_ptr<Client> client, const Buchete<T>& buchet);

    void processOrder() override;
};

// Template pentru crearea comenzilor
template <typename T>
class OrderFactory {
public:
    // Metoda statica pentru crearea unei comenzi noi
    static std::unique_ptr<Comanda<T>> createOrder(const std::string& clientName, std::shared_ptr<Client> client, const Buchete<T>& buchet);
};


#include "Comanda.tpp"

#endif



