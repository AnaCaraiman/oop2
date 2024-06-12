
#include "Client.h"

Client::Client(const std::string& name, const std::string& address) : name(name), address(address) {}

std::shared_ptr<Client> Client::getInstance(const std::string& name, const std::string& address) {
    static std::shared_ptr<Client> instance(new Client(name, address));
    return instance;
}

void Client::setName(const std::string& name) { this->name = name; }
const std::string& Client::getName() const { return name; }

void Client::setAddress(const std::string& address) { this->address = address; }
const std::string& Client::getAddress() const { return address; }

std::shared_ptr<Client> Client::clone() const {
    return std::make_shared<Client>(*this);
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "Client Name: " << client.name << ", Address: " << client.address;
    return os;
}

