#include "Zolw.h"
#include "conio2.h"
#include <random>
using namespace std;


Zolw::Zolw(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 2;
	this->inicjatywa = 1;
	this->polozenie = Punkt(x, y);
	this->zasieg = 1;
	this->znak = 'Z';
}

Organizm* Zolw::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Zolw(x, y, this->swiat);
	return dziecko;
}

bool Zolw::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Zolw*>(org)) {
		return 1;
	}
	return 0;
}

void Zolw::rysowanie() {
	putch('Z');
}

void Zolw::akcja() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(0, 3);
	if (distribution(gen) != 3) {
		char str[80];
		sprintf_s(str, "Zolw (x: %d, y: %d) nie wykonal ruchu", this->getX(), this->getY());
		puts(str);
		return;
	}
	Zwierze::akcja();
}

bool Zolw::czyOdpartoAtak(Organizm* organizmAtakujacy) {
	if (organizmAtakujacy->getSila() < 5)
		return true;
	return false;
}