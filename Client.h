#ifndef OOP2_CLIENT_H
#define OOP2_CLIENT_H

#include <string>
#include <iostream>
#include <memory>

class Client {
private:
    std::string name;
    std::string address;
    Client(const std::string& name, const std::string& address);

public:
    static std::shared_ptr<Client> getInstance(const std::string& name, const std::string& address);

    void setName(const std::string& name);
    const std::string& getName() const;

    void setAddress(const std::string& address);
    const std::string& getAddress() const;

    std::shared_ptr<Client> clone() const;

    friend std::ostream& operator<<(std::ostream& os, const Client& client);
};

#endif
