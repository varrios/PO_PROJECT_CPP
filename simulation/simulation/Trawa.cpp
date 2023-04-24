#include "Trawa.h"
#include "conio2.h"
using namespace std;

Trawa::Trawa(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 0;
	this->inicjatywa = 0;
	this->polozenie = Punkt(x, y);
	this->znak = 'T';
}

void Trawa::rysowanie() {
	putch('T');
}

Organizm* Trawa::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Trawa(x, y, this->swiat);
	return dziecko;
}
