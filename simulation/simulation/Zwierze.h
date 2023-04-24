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
	void umrzyj() override;
	void kolizja(Organizm* organizmAtakujacy) override;
	void wykonajRuch(int x, int y);
	auto losujKierunek();
	Punkt losujKierunekNiezajety();
	void rozmnoz();
	virtual bool czyOdpartoAtak(Organizm* organizmAtakowany);
	virtual bool sprawdzGatunki(Organizm* org) = 0;
	virtual bool czyMaDobryWech() const;
	virtual bool czyUcieczka(Organizm* organizmAtakujacy);
};