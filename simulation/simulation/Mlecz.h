#pragma once
#include "Swiat.h"
using namespace std;

class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, Swiat* swiat);
	void rysowanie() override;
	void akcja() override;
	Organizm* stworzDziecko(int x, int y) override;
	
};