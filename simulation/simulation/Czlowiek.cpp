#include "Czlowiek.h"
#include "conio2.h"
#include <random>
using namespace std;
#define ARROW_UP 0x50
#define ARROW_DOWN 0x48
#define ARROW_LEFT 0x4b
#define ARROW_RIGHT 0x4d

Czlowiek::Czlowiek(int x, int y, Swiat* swiat) {
	this->cooldown = 5;
	this->niesmiertelnosc = false;
	this->wybor = 0;
	this->swiat = swiat;
	this->sila = 5;
	this->inicjatywa = 4;
	this->polozenie = Punkt(x, y);
	this->zasieg = 1;
	this->znak = 'C';
}

void Czlowiek::rysowanie() {
	putch('C');
}

Organizm* Czlowiek::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Czlowiek(x, y, this->swiat);
	return dziecko;
}

void Czlowiek::akcja() {
	if (cooldown > 0 && niesmiertelnosc == false) {
		cooldown--;
	}
	else if (niesmiertelnosc == true) {
		if (--czas_trwania_umiejetnosci == 0) {
			cooldown = 5;
			czas_trwania_umiejetnosci = 5;
			niesmiertelnosc = false;
		}
	}
	int znak = this->wybor;
	this->polozenie_wczesniejsze = Punkt(this->getX(), this->getY());
	Punkt nowe_polozenie(this->getX(), this->getY());
	int n = this->zasieg;
	switch(znak){
	 case ARROW_UP:
		 nowe_polozenie.y+= n;
         break;
     case ARROW_DOWN:
		 nowe_polozenie.y-= n;
         break;
     case ARROW_RIGHT:
		 nowe_polozenie.x+= n;
         break;
     case ARROW_LEFT:
		 nowe_polozenie.x-= n;
         break;
	}
	if (nowe_polozenie.x >= this->swiat->getSzerokosc() || nowe_polozenie.x < 0 || nowe_polozenie.y < 0 || nowe_polozenie.y >= this->swiat->getWysokosc())
		return;
	Organizm* drugi_organizm = this->swiat->getPlansza()[nowe_polozenie.y][nowe_polozenie.x];
	char str[80];
	if (drugi_organizm != nullptr) {
		sprintf_s(str, "Proba ruchu - %s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, nowe_polozenie.x, nowe_polozenie.y);
		puts(str);
		Zwierze::kolizja(drugi_organizm);
	}
	else {
		this->wykonajRuch(nowe_polozenie.x, nowe_polozenie.y);
		sprintf_s(str, "Ruch - % s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, nowe_polozenie.x, nowe_polozenie.y);
		puts(str);
	}
}

int Czlowiek::getWybor() {
	return this->wybor;
}

void Czlowiek::setWybor(int znak) {
	this->wybor = znak;
}

bool Czlowiek::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Czlowiek*>(org)) {
		return 1;
	}
	return 0;
}

bool Czlowiek::JestNiesmiertelny() {
	return this->niesmiertelnosc;
}

void Czlowiek::uzyjUmiejetnosci() {
	if (cooldown == 0 && niesmiertelnosc == false) {
		this->niesmiertelnosc = true;
		this->cooldown = 5;
		this->czas_trwania_umiejetnosci = 5;
	}
}

int Czlowiek::getCooldown() {
	return this->cooldown;
}

int Czlowiek::getCzasUmiejetnosci() {
	return this->czas_trwania_umiejetnosci;
}


void Czlowiek::setUmiejetnosc(int czas_trwania, int cooldown, bool niesmiertelnosc) {
	this->czas_trwania_umiejetnosci = czas_trwania;
	this->cooldown = cooldown;
	this->niesmiertelnosc = niesmiertelnosc;
}