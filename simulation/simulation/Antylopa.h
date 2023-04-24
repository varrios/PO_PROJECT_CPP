#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Antylopa : public Zwierze {
public:
	Antylopa(int x, int y, Swiat* swiat);
	Organizm* stworzDziecko(int x, int y) override;
	bool sprawdzGatunki(Organizm* org) override;
	bool czyUcieczka(Organizm* organizmAtakujacy) override;
	void rysowanie() override;
};