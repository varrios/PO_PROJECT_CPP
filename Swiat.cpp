//
// Created by lucja on 05.04.2023.
//

#include <iostream>
#include "Swiat.h"
#include <ncurses.h>
using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {
    tura = 0;
    iloscOrganizmow = 0;
    this->plansza = new char *[wysokosc];
    for (int i = 0; i < wysokosc; i++){
        plansza[i] = new char[szerokosc];
        for(int j=0;j<szerokosc;j++)
            plansza[i][j] = '0';
    }
}

void Swiat::wypiszSwiat() const {
    int i,j;
    for(i=1;i<wysokosc+1;i++){
        for(j=0;j<szerokosc;j++)
            mvaddch(i, 2*j, plansza[i-1][j]);
    }
    move(0,j);
}

Swiat::~Swiat() {
    for(int i = 0; i < wysokosc; i++)
        delete[] plansza[i];
    delete[] plansza;
}

