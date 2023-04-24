#pragma once
#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Zolw : public Zwierze {
public:
	Zolw(int x, int y, Swiat* swiat);
	Organizm* stworzDziecko(int x, int y) override;
	bool sprawdzGatunki(Organizm* org) override;
	void rysowanie() override;
	void akcja() override;
	bool czyOdpartoAtak(Organizm* organizmAtakujacy) override;
};