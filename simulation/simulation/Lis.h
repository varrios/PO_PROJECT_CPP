#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Lis : public Zwierze {
public:
	Lis(int x, int y, Swiat* swiat);
	Organizm* stworzDziecko(int x, int y) override;
	bool sprawdzGatunki(Organizm* org) override;
	void rysowanie() override;
	bool czyMaDobryWech() const override;
};