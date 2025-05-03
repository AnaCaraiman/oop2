
#ifndef POOTEMA2_EROAREAPLICATIE_H
#define POOTEMA2_EROAREAPLICATIE_H

#include <exception>
#include <string>

class EroareAplicatie : public std::exception {
protected:
    std::string mesaj;
public:
    explicit EroareAplicatie(std::string m) : mesaj(std::move(m)) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};




#endif //POOTEMA2_EROAREAPLICATIE_H
