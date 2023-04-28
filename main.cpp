#include <iostream>
#include <vector>
#include "Flori.h"
#include "Depozit.h"
#include "Buchete.h"
#include "insfstoc.h"
#include "Nustoc.h"
#include "citirestoc.h"
#include <vector>
#include <memory>
using namespace std;

int main() {
    int n, i;
    vector<Depozit *> v;
    cout << "Numarul de flori pe care doriti sa il depozitati?";
    cin >> n;
    for (i = 0; i < n; i++) {
        v.push_back(new Depozit());
        Depozit *aux = dynamic_cast<Depozit *>(v.back());
        (v.back())->Read();

        int stock=(v.back())->getnrstock();
        if(stock<0)
            throw Nustoc();
        citirestoc::AdaugaAuto(shared_ptr<Depozit>(aux));



    }
try {
    start:

    std::cout << "1 - Afisare stoc" << "\n";
    std::cout << "0 - Iesire Meniu" << "\n";
    int nn, l;
    cin >> nn;
    switch (nn) {
        case 1: {
            int i = 1;
            for (auto c: v)
                cout << i++ << ". " << *c << endl;
            cout << endl;
            std::cout << "Inapoi la meniu?(1 pt DA sau 0 pt NU)" << "\n";
            std::cin >> l;
            if (l == 1)
                goto start;
            else
                break;
        }
    }

     }
catch (insfstoc & e)
{
    cout << "Error: " << e.what() << endl;



}


    return 0;
}
