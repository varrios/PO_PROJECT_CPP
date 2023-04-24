#include "Lis.h"
#include "conio2.h"

Lis::Lis(int x, int y, Swiat* swiat) {
	this->zasieg = 1;
	this->swiat = swiat;
	this->sila = 3;
	this->inicjatywa = 7;
	this->polozenie = Punkt(x, y);
	this->znak = 'L';
}

Organizm* Lis::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Lis(x, y, this->swiat);
	return dziecko;
}

bool Lis::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Lis*>(org)) {
		return 1;
	}
	return 0;
}

void Lis::rysowanie() {
	putch('L');
}

bool Lis::czyMaDobryWech() const {
	return true;
}
