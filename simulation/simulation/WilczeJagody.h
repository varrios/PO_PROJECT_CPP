#pragma once
#include "Swiat.h"
using namespace std;

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int x, int y, Swiat* swiat);
	void rysowanie() override;
	Organizm* stworzDziecko(int x, int y) override;
	bool czyTrujacy() override;
};
