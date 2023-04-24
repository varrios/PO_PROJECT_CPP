#include "Owca.h"
#include "conio2.h"

Owca::Owca(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 4;
	this->inicjatywa = 4;
	this->polozenie = Punkt(x, y);
	this->zasieg = 1;
	this->znak = 'O';
}

Organizm* Owca::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Owca(x, y, this->swiat);
	return dziecko;
}

bool Owca::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Owca*>(org)) {
		return 1;
	}
	return 0;
}

void Owca::rysowanie() {
	putch('O');
}
