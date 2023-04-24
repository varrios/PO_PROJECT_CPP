#include "WilczeJagody.h"
#include "conio2.h"
using namespace std;

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 99;
	this->inicjatywa = 0;
	this->polozenie = Punkt(x, y);
}

void WilczeJagody::rysowanie() {
	putch('J');
}

Organizm* WilczeJagody::stworzDziecko(int x, int y) {
	Organizm* dziecko = new WilczeJagody(x, y, this->swiat);
	return dziecko;
}

bool WilczeJagody::czyTrujacy() {
	return true;
}