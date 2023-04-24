#include "Zwierze.h"
#include "Zolw.h"
#include "Swiat.h"
#include <typeinfo>
#include <vector>
#include <random>
#include<windows.h>  
using namespace std;

Zwierze::Zwierze() {
}

Zwierze::Zwierze(int x, int y, Swiat *swiat) {
    this->zasieg = 1;
    this->wiek = 0;
    this->swiat = swiat;
    this->polozenie = Punkt(x, y);
}

auto Zwierze::losujKierunek() {
    int x_docelowy = this->getX();
    int y_docelowy = this->getY();
    int n = this->zasieg;
    vector <int> kierunki;
    if (this->polozenie.x + n <= swiat->getSzerokosc() - n)
        kierunki.push_back(0);
    if (this->polozenie.x - n >= 0)
        kierunki.push_back(1);
    if (this->polozenie.y + n <= swiat->getWysokosc() - n)
        kierunki.push_back(2);
    if (this->polozenie.y - n >= 0)
        kierunki.push_back(3);
    if (kierunki.size() == 0)
        x_docelowy = -1;
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distribution(0, kierunki.size()-1);
    int los_kierunek = kierunki[distribution(gen)];
    switch (los_kierunek) {
    case 0:
        x_docelowy += n;
        break;
    case 1:
        x_docelowy -= n;
        break;
    case 2:
        y_docelowy += n;
        break;
    case 3:
        y_docelowy -= n;
        break;
    }
    struct wynik { int x_docelowy;  int y_docelowy; Organizm* organizm; };
    return wynik{ x_docelowy, y_docelowy, this->swiat->getPlansza()[y_docelowy][x_docelowy] };
}

Punkt Zwierze::losujKierunekNiezajety() {
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
        return Punkt(-1,-1);
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
    return Punkt(x_dziecka,y_dziecka);
}

void Zwierze::akcja() {
    this->wiek++;
    this->polozenie_wczesniejsze = Punkt(this->getX(), this->getY());
    auto wynik = this->losujKierunek();
    if (this->czyMaDobryWech()) {
        while(wynik.organizm != nullptr && wynik.organizm->getSila()>this->getSila())
            wynik = this->losujKierunek();
    }
    else if (wynik.x_docelowy == -1)
        return;
    int x_docelowy = wynik.x_docelowy;
    int y_docelowy = wynik.y_docelowy;
    Organizm* drugi_organizm = wynik.organizm;
    char str[80];
    if (drugi_organizm != nullptr) {
        sprintf_s(str, "Proba ruchu - %s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, x_docelowy, y_docelowy);
        puts(str);
        this->kolizja(drugi_organizm); 
    }
    else {
        this->wykonajRuch(x_docelowy, y_docelowy);
        sprintf_s(str, "Ruch - % s: (%d, %d) -> (%d, %d)", typeid(*this).name(), polozenie_wczesniejsze.x, polozenie_wczesniejsze.y, x_docelowy, y_docelowy);
        puts(str);
    }

}

void Zwierze::kolizja(Organizm *organizmAtakowany) {
    char str[80];
    //ROZMNAZANIE
   if (sprawdzGatunki(organizmAtakowany)) {
       
       if (this->wiek >= 5 && organizmAtakowany->getWiek() >= 5) {
           this->rozmnoz();
           return;
       }
       sprintf_s(str, "Rezultat w.w. ruchu %s - rozmnazanie nieudane - za maly wiek", typeid(*this).name());
       puts(str);
       return;

    }
   //WALKA
    else {
        if (organizmAtakowany->czyOdpartoAtak(this)) {
            sprintf_s(str, "Rezultat w.w. ruchu - %s odbija atak %s (x: %d y: %d)", typeid(*organizmAtakowany).name(), typeid(*this).name(), this->getX(), this->getY());
            puts(str);
            return;
        }
        else if (organizmAtakowany->czyUcieczka(this) == true|| this->czyUcieczka(organizmAtakowany) == true) {
            sprintf_s(str, "Rezultat w.w. ruchu - Antylopa ucieka od walki");
            puts(str);
            return;
        }
        else if (this->getSila() >= organizmAtakowany->getSila()) {
            sprintf_s(str, "Rezultat w.w. ruchu - %s zabija %s (x: %d y: %d)", typeid(*this).name(), typeid(*organizmAtakowany).name(), this->getX(), this->getY());
            puts(str);
            organizmAtakowany->umrzyj();
            this->wykonajRuch(organizmAtakowany->getX(), organizmAtakowany->getY());
            return;
        }
        else 
        {
            sprintf_s(str, "Rezultat w.w. ruchu - %s zabija %s (x: %d y: %d)",typeid(*organizmAtakowany).name(), typeid(*this).name(), this->getX(), this->getY());
            puts(str);
            this->umrzyj();
            this->swiat->getPlansza()[organizmAtakowany->getY()][organizmAtakowany->getX()] = organizmAtakowany;
            return;
        }
    }

}

void Zwierze::umrzyj() {
    vector <Organizm*> *wektorOrg = (this->swiat->getlistaOrganizmow());
    this->swiat->getPlansza()[this->getY()][this->getX()] = nullptr;
    wektorOrg->erase(remove(wektorOrg->begin(), wektorOrg->end(), this), wektorOrg->end());
}

void Zwierze::rozmnoz() {
    Punkt miejsce_dziecka = this->losujKierunekNiezajety();
    if (miejsce_dziecka.x == -1)
        return;
    Organizm* dziecko = this->stworzDziecko(miejsce_dziecka.x, miejsce_dziecka.y);
    this->swiat->dodajOrganizm(dziecko);
    char str[80];
    sprintf_s(str, "Rezultat w.w. ruchu - rozmnazanie %s (x: %d y: %d)", typeid(*this).name(), miejsce_dziecka.x, miejsce_dziecka.y);
    puts(str);
}

void Zwierze::wykonajRuch(int x, int y) {
    this->swiat->getPlansza()[this->getY()][this->getX()] = nullptr;
    this->polozenie.x = x;
    this->polozenie.y = y;
    this->swiat->getPlansza()[y][x] = this; 
}

bool Zwierze::czyMaDobryWech() const {
    return false;
}

bool Zwierze::czyOdpartoAtak(Organizm* organizmAtakujacy) {
    return false;
}

bool Zwierze::czyUcieczka(Organizm* organizmAtakujacy) {
    return false;
}
