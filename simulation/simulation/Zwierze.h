#pragma once
#include "Swiat.h"
using namespace std;

class Zwierze : public Organizm {
protected:
	int zasieg;
public:
	Zwierze();
	Zwierze(int x, int y, Swiat* swiat);

	void akcja() override;
	void kolizja(Organizm* organizmAtakujacy) override;
	void wykonajRuch(int x, int y);
	auto losujKierunek();

	virtual bool czyMaDobryWech() const;
	

	virtual bool sprawdzGatunki(Organizm* org) = 0;
};