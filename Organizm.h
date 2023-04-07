//
// Created by lucja on 05.04.2023.
//

#ifndef PO_PROJECT_CPP_ORGANIZM_H
#define PO_PROJECT_CPP_ORGANIZM_H
#include "Swiat.h"

class Organizm {
private:
    int x,y;
    int sila;
    int inicjatywa;
    int wiek;
    Swiat* swiat;

    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    virtual void rysowanie() = 0;


};


#endif //PO_PROJECT_CPP_ORGANIZM_H
