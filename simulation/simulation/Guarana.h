#pragma once
#pragma once
#include "Swiat.h"
using namespace std;

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat* swiat);
	void rysowanie() override;
	Organizm* stworzDziecko(int x, int y) override;
	bool dodajeSile(Organizm* organizmAtakujacy) override;
};