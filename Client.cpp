#include "Client.h"

Client::Client(const std::string& nume, const std::string& prenume)
        : nume(nume), prenume(prenume) {}

Client::Client(const Client& other)
        : nume(other.nume), prenume(other.prenume) {}

Client& Client::operator=(const Client& other) {
    if (this != &other) {
        nume = other.nume;
        prenume = other.prenume;
    }
    return *this;
}

const std::string& Client::getNume() const {
    return nume;
}

const std::string& Client::getPrenume() const {
    return prenume;
}

std::ostream& operator<<(std::ostream& os, const Client& c) {
    os << "Client: " << c.nume << " " << c.prenume;
    return os;
}