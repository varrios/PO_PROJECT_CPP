#include "Organizm.h"
#include "Swiat.h"
#include <vector>
#include <random>
using namespace std;

Organizm::Organizm() {
    nowy_organizm = false;
}

bool Organizm::getStanOrg() const {
    return this->nowy_organizm;
}

void Organizm::setStanOrg(bool stan) {
    this->nowy_organizm = stan;
}

int Organizm::getX() const {
	return this->polozenie.x;
}

int Organizm::getY() const {
	return this->polozenie.y;
}

int Organizm::getInicjatywa() const {
	return this->inicjatywa;
}

int Organizm::getSila() const {
	return this->sila;
}

int Organizm::getWiek() const {
	return this->wiek;
}

void Organizm::umrzyj() {
	vector <Organizm*>* wektorOrg = (this->swiat->getlistaOrganizmow());
	this->swiat->getPlansza()[this->getY()][this->getX()] = nullptr;
	wektorOrg->erase(remove(wektorOrg->begin(), wektorOrg->end(), this), wektorOrg->end());
}

Punkt Organizm::losujKierunekNiezajety() {
    vector <int> kierunki;
    Organizm*** plansza = this->swiat->getPlansza();
    if (this->polozenie.x + 1 <= swiat->getSzerokosc() - 1 && plansza[this->polozenie.y][this->polozenie.x + 1] == nullptr)
        kierunki.push_back(0);
    if (this->polozenie.x - 1 >= 0 && plansza[this->polozenie.y][this->polozenie.x - 1] == nullptr)
        kierunki.push_back(1);
    if (this->polozenie.y + 1 <= swiat->getWysokosc() - 1 && plansza[this->polozenie.y + 1][this->polozenie.x] == nullptr)
        kierunki.push_back(2);
    if (this->polozenie.y - 1 >= 0 && plansza[this->polozenie.y - 1][this->polozenie.x] == nullptr)
        kierunki.push_back(3);
    if (kierunki.size() == 0) {
        return Punkt(-1, -1);
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, kierunki.size() - 1);
    int los_kierunek = kierunki[distribution(gen)];
    int x_dziecka = this->getX();
    int y_dziecka = this->getY();
    switch (los_kierunek) {
    case 0:
        x_dziecka++;
        break;
    case 1:
        x_dziecka--;
        break;
    case 2:
        y_dziecka++;
        break;
    case 3:
        y_dziecka--;
        break;
    }
    return Punkt(x_dziecka, y_dziecka);
}

void Organizm::rozmnoz() {
    Punkt miejsce_dziecka = this->losujKierunekNiezajety();
    if (miejsce_dziecka.x == -1)
        return;
    Organizm* dziecko = this->stworzDziecko(miejsce_dziecka.x, miejsce_dziecka.y);
    dziecko->setStanOrg(true);
    this->swiat->dodajOrganizm(dziecko);
    char str[80];
    sprintf_s(str, "Rezultat w.w. ruchu - rozmnazanie %s (x: %d y: %d)", typeid(*this).name(), miejsce_dziecka.x, miejsce_dziecka.y);
    puts(str);
}

bool Organizm::czyOdpartoAtak(Organizm* organizmAtakujacy) {
    return false;
}

bool Organizm::czyUcieczka(Organizm* organizmAtakujacy) {
    return false;
}

bool Organizm::czyTrujacy() {
    return false;
}

bool Organizm::dodajeSile(Organizm* organizmAtakujacy) {
    return false;
}

void Organizm::setSila(int sila) {
    this->sila = sila;
}
