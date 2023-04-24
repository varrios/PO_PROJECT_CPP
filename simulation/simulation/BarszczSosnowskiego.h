#pragma once
#include "Swiat.h"
using namespace std;

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int x, int y, Swiat* swiat);
	void rysowanie() override;
	Organizm* stworzDziecko(int x, int y) override;
	bool czyTrujacy() override;
	void akcja() override;
};
