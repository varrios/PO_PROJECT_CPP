#pragma once
#include "Punkt.h"
class Swiat;

class Organizm {
protected:
    Punkt polozenie;
    Punkt polozenie_wczesniejsze;
    int sila;
    int inicjatywa;
    int wiek;
    Swiat* swiat;
    char komunikat[128];
public:
    virtual void akcja() = 0;
    virtual void umrzyj() = 0;
    virtual void rysowanie() = 0;
    virtual void kolizja(Organizm* organizmAtakujacy) = 0;
    virtual Organizm* stworzDziecko(int x, int y) = 0;
    virtual bool czyOdpartoAtak(Organizm* organizmAtakujacy) = 0;
    virtual bool czyUcieczka(Organizm* organizmAtakujacy) = 0;
    virtual void wykonajRuch(int x, int y) = 0;
    virtual Punkt losujKierunekNiezajety() = 0;
    int getX();
    int getY();
    int getInicjatywa();
    int getSila();
    int getWiek();

};

