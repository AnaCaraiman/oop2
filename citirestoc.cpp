#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <memory>
#include <vector>
#include"citirestoc.h"
#include "Depozit.h"
using namespace std;
vector<shared_ptr<Depozit>> citirestoc::stoc;

    void citirestoc::AdaugaAuto(std::shared_ptr<Depozit> flori) {
        stoc.push_back(flori);
    }
citirestoc::~citirestoc()=default;