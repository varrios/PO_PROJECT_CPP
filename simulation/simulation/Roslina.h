#pragma once
#include "Swiat.h"
using namespace std;

class Roslina : public Organizm {
public:
	Roslina();
	Roslina(int x, int y, Swiat* swiat);

	void akcja() override;
	void kolizja(Organizm* organizmAtakujacy) override;

};