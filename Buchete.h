
#ifndef OOP2_BUCHETE_H
#define OOP2_BUCHETE_H
#include "Flori.h"
#include <string>
#include <ostream>

class Buchete: public Flori{
private:
    int nrfire;
    std::string hcolour;
    static int nrbuchete;
public:
    Buchete(const std::string &name, const std::string &colour, int nrfire,const std::string &hcolour);
    Buchete();
    int getnrfire() const;
    void setnrfire(int nrfire);
    void sethcolour(const std::string &hcolour);
    const std::string &gethcolour() const;

    static int getnrbuchete();
    static void setnrbuchete(int nrbuchete);
    Buchete& operator=(const Buchete& d)=delete;
    Buchete(const Buchete &b);
    void Read();
    void Print(std::ostream &os) const override;





};

#endif //OOP2_BUCHETE_H
