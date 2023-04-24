#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Czlowiek : public Zwierze {
private:
	int wybor;
public:
	Czlowiek(int x, int y, Swiat* swiat);
	void rysowanie() override;
	void akcja() override;
	Organizm* stworzDziecko(int x, int y);
	int getWybor();
	void setWybor(int znak);
	bool sprawdzGatunki(Organizm* org);
};