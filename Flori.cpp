#include "Flori.h"
#include<iostream>
#include<cstring>
using namespace std;

Flori::Flori(const std::string &name, const std::string &colour):name(name),colour(colour) {}
Flori::Flori()  {}
const std::string &Flori::getname() const {
    return name;
}
void Flori::setname(const std::string &name) {
    Flori::name = name;}

const std::string &Flori::getcolour() const {
    return colour;
}
void Flori::setcolour(const std::string &colour) {
    Flori::colour = colour;}

bool Flori::operator==(const Flori &rhs) const {
    return name == rhs.name &&
           colour == rhs.colour ;

}
Flori &Flori::operator=(const Flori &d) {
    name=d.name;
    colour=d.name;
    return *this;}





