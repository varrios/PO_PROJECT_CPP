//
// Created by lucja on 05.04.2023.
//

#ifndef PO_PROJECT_CPP_ZWIERZE_H
#define PO_PROJECT_CPP_ZWIERZE_H
#include "Organizm.h"


class Zwierze : Organizm {
public:
    void akcja() override = 0;
    virtual void kolizja() = 0;
    virtual void rysowanie() = 0;
};


#endif //PO_PROJECT_CPP_ZWIERZE_H
