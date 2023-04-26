#pragma once
#include "Swiat.h"
using namespace std;

class Swiat;
class Czlowiek : public Zwierze {
private:
	int wybor;
	int cooldown;
	int czas_trwania_umiejetnosci;
	bool niesmiertelnosc;
public:
	Czlowiek(int x, int y, Swiat* swiat);
	void rysowanie() override;
	void akcja() override;
	Organizm* stworzDziecko(int x, int y);
	int getWybor();
	void setWybor(int znak);
	bool sprawdzGatunki(Organizm* org);
	bool JestNiesmiertelny() override;
	void uzyjUmiejetnosci();
	int getCooldown();
	int getCzasUmiejetnosci();
	int getZycie();
	void setUmiejetnosc(int czas_trwania, int cooldown, bool niesmiertelnosc);
};