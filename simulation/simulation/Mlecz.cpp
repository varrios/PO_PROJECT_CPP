#include "Mlecz.h"
#include "conio2.h"
using namespace std;

Mlecz::Mlecz(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 0;
	this->inicjatywa = 0;
	this->polozenie = Punkt(x, y);
}

void Mlecz::rysowanie() {
	putch('M');
}

Organizm* Mlecz::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Mlecz(x, y, this->swiat);
	return dziecko;
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}
