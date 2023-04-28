

#ifndef OOP2_NUSTOC_H
#define OOP2_NUSTOC_H
#include <exception>
class Nustoc : public std::exception{
public:
    const char* what() const throw();
};

#endif //OOP2_NUSTOC_H
