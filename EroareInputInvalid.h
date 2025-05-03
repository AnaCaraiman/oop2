#ifndef EROARE_INPUT_INVALID_H
#define EROARE_INPUT_INVALID_H

#include "EroareAplicatie.h"

class EroareInputInvalid : public EroareAplicatie {
public:
    EroareInputInvalid() : EroareAplicatie("Eroare: input invalid sau corupt.") {}
};

#endif
