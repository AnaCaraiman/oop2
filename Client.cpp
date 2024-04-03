
#include "Client.h"

Client::Client(const std::string& nume, const std::string& prenume) : nume(nume), prenume(prenume) {}

std::string Client::getNume() const {
    return nume;
}

std::string Client::getPrenume() const {
    return prenume;
}
