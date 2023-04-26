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
#include "Czlowiek.h"
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

void Swiat::ustawGracza(Czlowiek* gracz) {
    this->gracz = gracz;
}

Czlowiek* Swiat::getGracz() {
    return this->gracz;
}

void Swiat::wypiszSwiat(){
    _setcursortype(_NOCURSOR);
    int i, j;
    int x = 1;
    int y = 1;
    char str[80];
    int offset_guide = szerokosc + 15;
    int offset = offset_guide + 50;
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
    int b_y = 0;
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "OBSLUGA GRY:");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "Strzalki - kontrolowanie gracza, nastepna tura");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "S - zapisz gre");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "L - wczytaj gre");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "Q - zakoncz gre");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "U - umiejetnosc czlowieka");
    puts(str);
    gotoxy(offset_guide, ++b_y);
    sprintf_s(str, "Czlowiek - cooldown umiejetnosci: %d", this->getGracz()->getCooldown());
    puts(str);
    if (this->getGracz()->JestNiesmiertelny()) {
        gotoxy(offset_guide, ++b_y);
        sprintf_s(str, "Czlowiek - pozostaly czas trwania umiejetnosci: %d", this->getGracz()->getCzasUmiejetnosci());
        puts(str);
    }

    b_y = 1;
    gotoxy(offset, ++b_y);
    sprintf_s(str, "LEGENDA:");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(C) - Czlowiek");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(O) - Owca");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(W) - Wilk");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(A) - Antylopa");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(L) - Lis");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(Z) - Zolw");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(T) - Trawa");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(J) - Wilcze Jagody");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(B) - Barszcz Sosnowskiego");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(M) - Mlecz");
    puts(str);
    gotoxy(offset, ++b_y);
    sprintf_s(str, "(G) - Guarana");
    puts(str);
    y +=2;
    gotoxy(x, ++y);
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
    clrscr();
    gotoxy(0, 0);
    puts("Podaj nazwe pliku do wczytania:");
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
    ifstream plik(nazwa_folderu + nazwa_pliku + rozszerzenie);
    if (plik.is_open()) {
        this->UsunOrganizmy();

        for (int i = 0; i < wysokosc; i++) {
            delete[] this->plansza[i];
        }
        delete[] this->plansza;

        int s, w, t, ilo;
        int czas_um, cooldown_um;
        bool um;
        plik >> cooldown_um >> czas_um >> um;
        plik >> s >> w >> t >> ilo;
        this->szerokosc = s;
        this->wysokosc = w;
        this->tura = t;
        this->iloscOrganizmow = ilo;
       

        this->plansza = new Organizm **[wysokosc];
        for (int i = 0; i < wysokosc; i++) {
            plansza[i] = new Organizm * [szerokosc];
            for (int j = 0; j < szerokosc; j++) {
                plansza[i][j] = nullptr;
            }
        }

        for (int i = 0; i < ilo; i++) {
            char znak;
            int x, y, wiek, sila;
            bool stan;
            plik >> znak;
            plik >> x;
            plik >> y;
            plik >> wiek;
            plik >> stan;
            plik >> sila;
            Organizm* nowy_organizm = this->odczytajOrganizm(znak, x, y);
            if (nowy_organizm == nullptr)
                continue;
            Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(nowy_organizm);
            if (czlowiek != nullptr) {
                czlowiek->setUmiejetnosc(czas_um, cooldown_um, um);
            }
            nowy_organizm->setStanOrg(stan);
            nowy_organizm->setWiek(wiek);
            nowy_organizm->setSila(sila);
            this->dodajOrganizm(nowy_organizm);
        }
        cout << "\nWczytano poprawnie gre " << nazwa_pliku << "\n";
        cout << "\nKliknij przycisk na klawiaturze zeby kontynuowac gre...";
        getch();
        clrscr();
        plik.close();
        return;
    }
    else {
        cout << "\nNie mozna wczytac gry o nazwie: " << nazwa_pliku << "\n";
        cout << "\nKliknij przycisk na klawiaturze zeby kontynuowac gre...";
        getch();
        clrscr();
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
        plik << this->getGracz()->getCooldown() << endl;
        plik << this->getGracz()->getCzasUmiejetnosci() << endl;
        plik << this->getGracz()->JestNiesmiertelny() << endl;
        plik << szerokosc << endl;
        plik << wysokosc << endl;
        plik << tura << endl;
        plik << iloscOrganizmow << endl;

        for (Organizm* org : listaOrganizmow) {
            plik << org->getZnak() << endl;
            plik << org->getX() << endl;
            plik << org->getY() << endl;
            plik << org->getWiek() << endl;
            plik << org->getStanOrg() << endl;
            plik << org->getSila() << endl;
                
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


Organizm* Swiat::odczytajOrganizm(int znak, int x, int y) {
    switch (znak) {
    case 'A':
        return new Antylopa(x, y, this);
    case 'B':
        return new BarszczSosnowskiego(x, y, this);
    case 'C':
    {
        Czlowiek* nowy_czlowiek = new Czlowiek(x, y, this);
        this->ustawGracza(nowy_czlowiek);
        return nowy_czlowiek;
        break;
    }
    case 'G':
        return new Guarana(x, y, this);
    case 'L':
        return new Lis(x, y, this);
    case 'M':
        return new Mlecz(x, y, this);
    case 'O':
        return new Owca(x, y, this);
    case 'T':
        return new Trawa(x, y, this);
    case 'J':
        return new WilczeJagody(x, y, this);
    case 'W':
        return new Wilk(x, y, this);
    case 'Z':
        return new Zolw(x, y, this);
    default:
        return nullptr;
    }
}


void Swiat::UsunOrganizmy() {
    for (auto& org : listaOrganizmow) {
        if (org != nullptr)
            delete org;
    }
    this->listaOrganizmow.clear();
}