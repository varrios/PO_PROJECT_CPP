#pragma once
#include <vector>
#include <memory>
#include "Organizm.h"
#include "Zwierze.h"
using namespace std;

class Zwierze;

class Swiat {
private:
    int szerokosc;
    int wysokosc;
    int tura;
    int iloscOrganizmow;
    Organizm*** plansza;
    vector <Organizm*> listaOrganizmow;
public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();
    void wypiszSwiat();
    void wykonajTure();
    int getSzerokosc();
    int getWysokosc();
    void stworzPopulacje();
    void dodajOrganizm(Organizm* organizm);
    void odswiezMape();
    vector <Organizm*>* getlistaOrganizmow();
    Organizm*** getPlansza();

};

