#include "Antylopa.h"
#include "conio2.h"
#include <random>

Antylopa::Antylopa(int x, int y, Swiat* swiat) {
	this->zasieg = 2;
	this->swiat = swiat;
	this->sila = 4;
	this->inicjatywa = 4;
	this->polozenie = Punkt(x, y);
}

Organizm* Antylopa::stworzDziecko(int x, int y) {
	Organizm* dziecko = new Antylopa(x, y, this->swiat);
	return dziecko;
}

bool Antylopa::sprawdzGatunki(Organizm* org) {
	if (dynamic_cast<Antylopa*>(org)) {
		return 1;
	}
	return 0;
}

void Antylopa::rysowanie() {
	putch('A');
}

bool Antylopa::czyUcieczka(Organizm* organizmAtakujacy) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(0, 1);
	if (distribution(gen) == 0) {
		Punkt nowe_polozenie = organizmAtakujacy->losujKierunekNiezajety();
		if (nowe_polozenie.x == -1) {
			nowe_polozenie.x = this->getX();
			nowe_polozenie.y = this->getY();
		}
		this->wykonajRuch(nowe_polozenie.x, nowe_polozenie.y);
		return true;
	}
	return false;
}