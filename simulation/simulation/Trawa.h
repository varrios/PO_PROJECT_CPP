#pragma once
#include "Swiat.h"
using namespace std;

class Trawa : public Roslina {
public:
	Trawa(int x, int y, Swiat* swiat);
	void rysowanie() override;
	Organizm* stworzDziecko(int x, int y) override;
};