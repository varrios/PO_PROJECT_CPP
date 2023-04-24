#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Owca : public Zwierze {
public:
	Owca(int x, int y, Swiat* swiat);
	Organizm* stworzDziecko(int x, int y) override;
	bool sprawdzGatunki(Organizm* org) override;
	void rysowanie() override;
};