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
#include "Mlecz.h"
#include "BarszczSosnowskiego.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <string>

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
        if (this->listaOrganizmow[i]->getStanOrg()) {
            this->listaOrganizmow[i]->setStanOrg(false);
            continue;
        }
            this->listaOrganizmow[i]->akcja();
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
    Roslina* roslina = dynamic_cast<Roslina*>(organizm);
    if (roslina) {
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
    this->dodajOrganizm(new Trawa(8, 2, this));
    this->dodajOrganizm(new Mlecz(8, 3, this));
    this->dodajOrganizm(new WilczeJagody(9, 3, this));
    this->dodajOrganizm(new BarszczSosnowskiego(6, 9, this));
    this->dodajOrganizm(new Guarana(1, 9, this));
}

Organizm*** Swiat::getPlansza() {
    return this->plansza;
}


vector <Organizm*>* Swiat::getlistaOrganizmow() {
    return &(this->listaOrganizmow);
}

void Swiat::wczytajGre() {
    ifstream file("save_file.txt");
    if (file.is_open()) {
        for (int i = 0; i < szerokosc; i++) {
            for (int j = 0; j < wysokosc; j++) {
                delete this->plansza[i][j];
            }
            delete[] this->plansza[i];
        }
        delete[] this->plansza;
        for (auto& org : listaOrganizmow)
            delete org;

        int s, w, t, ilo;
        file >> s >> w >> t >> ilo;
        this->szerokosc = s;
        this->wysokosc = w;
        this->tura = t;
        this->iloscOrganizmow = ilo;

        this->listaOrganizmow.clear();
        for (int i = 0; i < ilo; i++) {
            Organizm* org;
            file >> org;
            this->listaOrganizmow.push_back(org);
        }
        

        Organizm*** plansza = new Organizm **[szerokosc];
        for (int x = 0; x < szerokosc; x++) {
            plansza[x] = new Organizm * [wysokosc];
        }
        for (int y = 0; y < wysokosc; y++) {
            for (int x = 0; x < szerokosc; x++) {
                Organizm* org;
                file >> org;
                plansza[x][y] = org;
            }
        }
        this->plansza = plansza;

        file.close();
    }
}

void Swiat::zapiszGre() {
    clrscr();
    gotoxy(0, 0);
    puts("Podaj nazwe pliku zapisu:");
    string nazwa_pliku;
    string nazwa_folderu = "zapisy/";
    string rozszerzenie = ".txt";
    
    char c;
    while ((c = getch()) != '\r') {
        if (c == '\b') {
            if (!nazwa_pliku.empty()) {
                nazwa_pliku.erase(nazwa_pliku.size() - 1);
                cout << "\b \b";
            }
        }
        else {
            nazwa_pliku += c;
            putch(c);
        }
    }
    ofstream plik(nazwa_folderu+nazwa_pliku+rozszerzenie);
    cout << "\nZapisuje gre jako " << nazwa_pliku << "...\n";
    if (plik.is_open()) {
        plik << szerokosc << endl;
        plik << wysokosc << endl;
        plik << tura << endl;
        plik << iloscOrganizmow << endl;

        for (Organizm* org : listaOrganizmow) {
            plik << &org << endl;
        }

        for (int y = 0; y < wysokosc; y++) {
            for (int x = 0; x < szerokosc; x++) {
                plik << plansza[x][y] << endl;
            }
        }
        plik.close();
    }
    cout << "\nKliknij przycisk na klawiaturze zeby kontynuowac gre...";
    getch();
    clrscr();
    
}