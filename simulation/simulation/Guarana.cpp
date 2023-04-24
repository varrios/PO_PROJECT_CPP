#include "Guarana.h"
#include "conio2.h"
using namespace std;

Guarana::Guarana(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 0;
	this->inicjatywa = 0;
	this->polozenie = Punkt(x, y);
	this->znak = 'G';
}

void Guarana::rysowanie() {
	putch('G');
}

Organizm* Guarana::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Guarana(x, y, this->swiat);
	return dziecko;
}

bool Guarana::dodajeSile(Organizm* organizmAtakujacy) {
	organizmAtakujacy->setSila(organizmAtakujacy->getSila() + 3);
	return true;
}

