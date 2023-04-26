#include "BarszczSosnowskiego.h"
#include "conio2.h"
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) {
	this->swiat = swiat;
	this->sila = 10;
	this->inicjatywa = 0;
	this->polozenie = Punkt(x, y);
	this->znak = 'B';
}

void BarszczSosnowskiego::rysowanie() {
	putch('B');
}

Organizm* BarszczSosnowskiego::stworzDziecko(int x, int y) {
	Organizm* dziecko = new BarszczSosnowskiego(x, y, this->swiat);
	return dziecko;
}

bool BarszczSosnowskiego::czyTrujacy() {
	return true;
}

void BarszczSosnowskiego::akcja() {
	Organizm*** plansza = this->swiat->getPlansza();
	int x = this->getX();
	int y = this->getY();
	char str[128];
	
	if (x + 1 <= swiat->getSzerokosc() - 1 && plansza[y][x + 1] != nullptr && dynamic_cast<Zwierze*>(plansza[y][x + 1]) != nullptr) {
		if (!plansza[y][x + 1]->JestNiesmiertelny()) {
			sprintf_s(str, "%s zostal zabity przez sasiedztwo z %s (x: %d y: %d)", typeid(*plansza[y][x + 1]).name(), typeid(*this).name(), plansza[y][x + 1]->getX(), plansza[y][x + 1]->getY());
			puts(str);
			plansza[y][x + 1]->umrzyj();
		}
	}
	if (x - 1 >= 0 && (plansza[y][x - 1] != nullptr) && dynamic_cast<Zwierze*>(plansza[y][x - 1]) != nullptr) {
		if (!plansza[y][x - 1]->JestNiesmiertelny()) {
			sprintf_s(str, "%s zostal zabity przez sasiedztwo z %s (x: %d y: %d)", typeid(*plansza[y][x - 1]).name(), typeid(*this).name(), plansza[y][x - 1]->getX(), plansza[y][x - 1]->getY());
			puts(str);
			plansza[y][x - 1]->umrzyj();
		}
	}
	if (y + 1 <= swiat->getWysokosc() - 1 && plansza[y + 1][x] != nullptr && dynamic_cast<Zwierze*>(plansza[y + 1][x]) != nullptr) {
		if (!plansza[y + 1][x]->JestNiesmiertelny()) {
			sprintf_s(str, "%s zostal zabity przez sasiedztwo z %s (x: %d y: %d)", typeid(*plansza[y + 1][x]).name(), typeid(*this).name(), plansza[y + 1][x]->getX(), plansza[y + 1][x]->getY());
			puts(str);
			plansza[y + 1][x]->umrzyj();
		}
	}
	if (y - 1 >= 0 && plansza[y - 1][x] != nullptr && dynamic_cast<Zwierze*>(plansza[y - 1][x]) != nullptr) {	
		if (!plansza[y - 1][x]->JestNiesmiertelny()) {
			sprintf_s(str, "%s zostal zabity przez sasiedztwo z %s (x: %d y: %d)", typeid(*plansza[y - 1][x]).name(), typeid(*this).name(), plansza[y - 1][x]->getX(), plansza[y - 1][x]->getY());
			puts(str);
			plansza[y - 1][x]->umrzyj();
		}
	}
	Roslina::akcja();
}