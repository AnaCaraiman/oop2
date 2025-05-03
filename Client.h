#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>

class Client {
private:
    std::string nume;
    std::string prenume;

public:
    Client(const std::string& nume, const std::string& prenume);
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client() = default;

    const std::string& getNume() const;
    const std::string& getPrenume() const;

    friend std::ostream& operator<<(std::ostream& os, const Client& c);
};
#endif