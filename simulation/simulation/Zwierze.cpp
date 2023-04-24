#include "Swiat.h"
#include "Zwierze.h"
#include "Zolw.h"
#include <typeinfo>
#include <vector>
#include <random>
#include<windows.h>  
using namespace std;
Zwierze::Zwierze() {
}

Zwierze::Zwierze(int x, int y, Swiat *swiat) {
    this->zasieg = 1;
    this->wiek = 0;
    this->swiat = swiat;
    this->polozenie = Punkt(x, y);
}

auto Zwierze::losujKierunek() {
    int x_docelowy = this->getX();
    int y_docelowy = this->getY();
    int n = this->zasieg;
    vector <int> kierunki;
    if (this->polozenie.x + n <= swiat->getSzerokosc() - n)
        kierunki.push_back(0);
    if (this->polozenie.x - n >= 0)
        kierunki.push_back(1);
    if (this->polozenie.y + n <= swiat->getWysokosc() - n)
        kierunki.push_back(2);
    if (this->polozenie.y - n >= 0)
        kierunki.push_back(3);
    if (kierunki.size() == 0)
        x_docelowy = -1;
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distribution(0, kierunki.size()-1);
    int los_kierunek = kierunki[distribution(gen)];
    switch (los_kierunek) {
    case 0:
        x_docelowy += n;
        break;
    case 1:
        x_docelowy -= n;
        break;
    case 2:
        y_docelowy += n;
        break;
    case 3:
        y_docelowy -= n;
        break;
    }
    struct wynik { int x_docelowy;  int y_docelowy; Organizm* organizm; };
    return wynik{ x_docelowy, y_docelowy, this->swiat->getPlansza()[y_docelowy][x_docelowy] };
}

void Zwierze::akcja() {
    this->wiek++;
    this->setStanOrg(false);
    this->polozenie_wczesniejsze = Punkt(this->getX(), this->getY());
    auto wynik = this->losujKierunek();
    if (this->czyMaDobryWech()) {
        while(wynik.organizm != nullptr && wynik.organizm->getSila()>this->getSila())
            wynik = this->losujKierunek();
    }
    else if (wynik.x_docelowy == -1)
        return;
    int x_docelowy = wynik.x_docelowy;
    int y_docelowy = wynik.y_docelowy;
    Organizm* drugi_organizm = wynik.organizm;
    char str[80];
    if (drugi_organizm != nullptr) {
        sprintf_s(str, "Proba ruchu - %s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, x_docelowy, y_docelowy);
        puts(str);
        this->kolizja(drugi_organizm); 
    }
    else {
        this->wykonajRuch(x_docelowy, y_docelowy);
        sprintf_s(str, "Ruch - % s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, x_docelowy, y_docelowy);
        puts(str);
    }

}

void Zwierze::kolizja(Organizm *organizmAtakowany) {
    char str[128];
    //ROZMNAZANIE
   if (sprawdzGatunki(organizmAtakowany)) {
       if (this->wiek >= 5 && organizmAtakowany->getWiek() >= 5) {
           this->rozmnoz();
           return;
       }
       sprintf_s(str, "Rezultat w.w. ruchu %s - rozmnazanie nieudane - za maly wiek", typeid(*this).name());
       puts(str);
       return;
    }
   //WALKA
    else {
       if (organizmAtakowany->dodajeSile(this)) {
           sprintf_s(str, "Rezultat w.w. ruchu - %s zjada %s i dostaje wiecej sily. Aktualna sila: %d (%d, %d)", typeid(*this).name(), typeid(*organizmAtakowany).name(), this->getSila(),organizmAtakowany->getX() , organizmAtakowany->getY());
           organizmAtakowany->umrzyj();
           this->wykonajRuch(organizmAtakowany->getX(), organizmAtakowany->getY());
           puts(str);
           return;
        }
        if (organizmAtakowany->czyTrujacy()) {
           organizmAtakowany->umrzyj();
           this->umrzyj();
           sprintf_s(str, "Rezultat w.w. ruchu - %s zjada %s i umiera (%d, %d)", typeid(*this).name(), typeid(*organizmAtakowany).name(),organizmAtakowany->getX(), organizmAtakowany->getY());
           puts(str);
           return;
        }
        else if (organizmAtakowany->czyOdpartoAtak(this)) {
            sprintf_s(str, "Rezultat w.w. ruchu - %s odbija atak %s (%d, %d)", typeid(*organizmAtakowany).name(), typeid(*this).name(), organizmAtakowany->getX(), organizmAtakowany->getY());
            puts(str);
            return;
        }
        else if (organizmAtakowany->czyUcieczka(this) == true|| this->czyUcieczka(organizmAtakowany) == true) {
            sprintf_s(str, "Rezultat w.w. ruchu - Antylopa ucieka od walki");
            puts(str);
            return;
        }
        else if (this->getSila() >= organizmAtakowany->getSila()) {
            sprintf_s(str, "Rezultat w.w. ruchu - %s zabija %s (%d, %d)", typeid(*this).name(), typeid(*organizmAtakowany).name(), organizmAtakowany->getX(), organizmAtakowany->getY());
            puts(str);
            organizmAtakowany->umrzyj();
            this->wykonajRuch(organizmAtakowany->getX(), organizmAtakowany->getY());
            return;
        }
        else 
        {
            sprintf_s(str, "Rezultat w.w. ruchu - %s zabija %s (%d, %d)",typeid(*organizmAtakowany).name(), typeid(*this).name(), organizmAtakowany->getX(), organizmAtakowany->getY());
            puts(str);
            this->umrzyj();
            this->swiat->getPlansza()[organizmAtakowany->getY()][organizmAtakowany->getX()] = organizmAtakowany;
            return;
        }
    }

}

void Zwierze::wykonajRuch(int x, int y) {
    this->swiat->getPlansza()[this->getY()][this->getX()] = nullptr;
    this->polozenie.x = x;
    this->polozenie.y = y;
    this->swiat->getPlansza()[y][x] = this; 
}

bool Zwierze::czyMaDobryWech() const {
    return false;
}

