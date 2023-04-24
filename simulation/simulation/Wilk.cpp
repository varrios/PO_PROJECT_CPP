#include "Wilk.h"
#include "conio2.h"
using namespace std;


Wilk::Wilk(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 9;
	this->inicjatywa = 5;
	this->polozenie = Punkt(x, y);
	this->zasieg = 1;
	this->znak = 'W';
}

Organizm* Wilk::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Wilk(x,y,this->swiat);
	return dziecko;
}

bool Wilk::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Wilk*>(org)) {
		return 1;
	}
	return 0;
}

void Wilk::rysowanie() {
	putch('W');
}