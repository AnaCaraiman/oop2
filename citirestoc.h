
#ifndef OOP2_CITIRESTOC_H
#define OOP2_CITIRESTOC_H
#include "Depozit.h"
#include <vector>
#include <memory>
class citirestoc {

    static std::vector<std::shared_ptr<Depozit>> stoc;
public:
    static void AdaugaAuto(std::shared_ptr<Depozit>);


    virtual ~citirestoc();};


#endif //OOP2_CITIRESTOC_H
