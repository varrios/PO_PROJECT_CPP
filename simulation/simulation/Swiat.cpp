#include <iostream>
#include<stdio.h>
#include <algorithm>
#include<stdlib.h>
#include "conio2.h"
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Punkt.h"
#include <string>
#include <windows.h>
using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {
    settitle("Lucjan Gackowski 193150");
    _setcursortype(_NOCURSOR);
    textbackground(BLACK);
    textcolor(7);
    tura = 0;
    iloscOrganizmow = 0;
    this->plansza = new Organizm** [wysokosc];
    for (int i = 0; i < wysokosc; i++) {
        plansza[i] = new Organizm*[szerokosc];
        for (int j = 0; j < szerokosc; j++) {
            plansza[i][j] = nullptr;
        }
    }
}

void Swiat::wypiszSwiat(){
    int i, j;
    int x = 1;
    int y = 1;
    char str[80];
    gotoxy(1, 1);
    for (i = 0; i < wysokosc; i++) {
        for (j = 0; j < szerokosc; j++) {
            if (plansza[i][j] == nullptr) {
                putch('.');
                putch(' ');
                continue;
            }
            plansza[i][j]->rysowanie();
            putch(' ');
        }
        cputs("\n");
        gotoxy(x, wherey());
        y = wherey();
    }
    gotoxy(x, y);
    sprintf_s(str, "Tura numer: %d", this->tura);
    puts(str);
    gotoxy(x, ++y);
    sprintf_s(str, "Ilosc organizmow na planszy: %d", this->iloscOrganizmow);
    puts(str);
    gotoxy(x, ++y);
    sprintf_s(str, "Dziennik zdarzen:");
    puts(str);
}

void Swiat::wykonajTure() {
    this->iloscOrganizmow = listaOrganizmow.size();
    sort(listaOrganizmow.begin(), listaOrganizmow.end(), [](Organizm* p1, Organizm* p2) {
        if (p1->getInicjatywa() == p2->getInicjatywa())
            return(p1->getWiek() > p2->getWiek());
        return (p1->getInicjatywa() > p2->getInicjatywa());
        });
    for (int i = 0; i < this->listaOrganizmow.size(); i++) {
        this->listaOrganizmow[i]->akcja();
        /*char str[200];
        sprintf_s(str, "%s (ini: %d) (wiek: %d) (x: %d) (y: %d)", typeid(*(this->listaOrganizmow[i])).name(),this->listaOrganizmow[i]->getInicjatywa(), this->listaOrganizmow[i]->getWiek(), this->listaOrganizmow[i]->getX(), this->listaOrganizmow[i]->getY());
        puts(str);*/
    } 
    this->tura++;
    
}

int Swiat::getWysokosc() {
    return this->wysokosc; 
}

int Swiat::getSzerokosc() {
    return this->szerokosc;
}

Swiat::~Swiat() {
    for (int i = 0; i < szerokosc; i++) {
        for (int j = 0; j < wysokosc; j++) {
            delete this->plansza[i][j];
        }
        delete[] this->plansza[i];
    }
    delete[] this->plansza;
    for (auto& org : listaOrganizmow) 
        delete org;
    
}


void Swiat::dodajOrganizm(Organizm* organizm) {
    Zwierze* zwierze = dynamic_cast<Zwierze*>(organizm);
    if (zwierze) {
        this->listaOrganizmow.push_back(organizm);
        this->plansza[organizm->getY()][organizm->getX()] = organizm;
    }
    this->iloscOrganizmow = listaOrganizmow.size();
}

void Swiat::stworzPopulacje() {
    this->dodajOrganizm(new Owca(2,2,this));
    this->dodajOrganizm(new Owca(2, 3, this));
    this->dodajOrganizm(new Wilk(4, 5, this));
    this->dodajOrganizm(new Wilk(4, 4, this));
    this->dodajOrganizm(new Antylopa(8, 8, this));
    this->dodajOrganizm(new Lis(5, 4, this));
    this->dodajOrganizm(new Zolw(7, 4, this));
}

Organizm*** Swiat::getPlansza() {
    return this->plansza;
}


vector <Organizm*>* Swiat::getlistaOrganizmow() {
    return &(this->listaOrganizmow);
}