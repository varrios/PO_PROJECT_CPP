#pragma once
#include <vector>
#include <memory>
#include "Organizm.h"
#include "Zwierze.h"
#include "Czlowiek.h"
#include "Roslina.h"
using namespace std;

class Zwierze;
class Czlowiek;

class Swiat {
private:
    int szerokosc;
    int wysokosc;
    int tura;
    int iloscOrganizmow;
    Czlowiek* gracz;
    Organizm*** plansza;
    vector <Organizm*> listaOrganizmow;
public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();
    void ustawGracza(Czlowiek* gracz);
    Czlowiek* getGracz();
    void wypiszSwiat();
    void wykonajTure();
    int getSzerokosc();
    int getWysokosc();
    void stworzPopulacje();
    void dodajOrganizm(Organizm* organizm);
    void UsunOrganizmy();
    vector <Organizm*>* getlistaOrganizmow();
    Organizm*** getPlansza();
    void wczytajGre();
    void zapiszGre();
    Organizm* odczytajOrganizm(int znak, int x, int y);
};
