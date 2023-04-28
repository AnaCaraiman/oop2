
#ifndef OOP2_INSFSTOC_H
#define OOP2_INSFSTOC_H
#include <exception>
class insfstoc : public std::exception{
public:
    const char* what() const throw();
};

#endif //OOP2_INSFSTOC_H
