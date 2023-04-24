#pragma once
#include "Punkt.h"
class Swiat;

class Organizm {
protected:
    char znak;
    bool nowy_organizm;
    Punkt polozenie;
    Punkt polozenie_wczesniejsze;
    int sila;
    int inicjatywa;
    int wiek;
    Swiat* swiat;
public:
    Organizm();
    ~Organizm();
    virtual void akcja() = 0;
    virtual void rysowanie() = 0;
    virtual void kolizja(Organizm* organizmAtakujacy) = 0;
    virtual Organizm* stworzDziecko(int x, int y) = 0;
    virtual Punkt losujKierunekNiezajety();

    virtual bool czyOdpartoAtak(Organizm* organizmAtakowany);
    virtual bool czyUcieczka(Organizm* organizmAtakujacy);
    virtual bool dodajeSile(Organizm* organizmAtakujacy);
    virtual bool czyTrujacy();

    void rozmnoz();
    void umrzyj();

    void setWiek(int wiek);
    void setStanOrg(bool stan);
    void setSila(int sila);
    bool getStanOrg() const;
    int getX() const;
    int getY() const;
    int getInicjatywa() const;
    int getSila() const;
    int getWiek() const;
    char getZnak() const;
};

