#ifndef EROARE_FISIER_H
#define EROARE_FISIER_H

#include "EroareAplicatie.h"

class EroareFisier : public EroareAplicatie {
public:
    EroareFisier() : EroareAplicatie("Eroare: nu s-a putut deschide fisierul.") {}
};

#endif

