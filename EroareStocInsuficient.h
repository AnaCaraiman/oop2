
#ifndef EROARE_STOC_INSUFICIENT_H
#define EROARE_STOC_INSUFICIENT_H

#include "EroareAplicatie.h"

class EroareStocInsuficient : public EroareAplicatie {
public:
    EroareStocInsuficient() : EroareAplicatie("Eroare: stoc insuficient pentru produsul cerut.") {}
};

#endif
