#ifndef OOP2_CLIENT_H
#define OOP2_CLIENT_H
#pragma once
#include <string>

class Client {
private:
    std::string nume;
    std::string prenume;

public:
    Client(const std::string& nume, const std::string& prenume);
    std::string getNume() const;
    std::string getPrenume() const;
};
#endif // CLIENT_H
