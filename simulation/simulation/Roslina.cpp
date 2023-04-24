#pragma once
#include "Swiat.h"
#include <random>
using namespace std;

Roslina::Roslina() {
}

Roslina::Roslina(int x, int y, Swiat* swiat) {
    this->inicjatywa = 0;
    this->wiek = 0;
    this->swiat = swiat;
    this->polozenie = Punkt(x, y);
}

void Roslina::akcja() {
    this->wiek++;
    this->setStanOrg(false);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 40);
    if (distribution(gen) == 1) {
        this->rozmnoz();
    }
}

void Roslina::kolizja(Organizm* organizmAtakujacy) {
    if (organizmAtakujacy->getSila() > this->getSila())
        this->umrzyj();
    else {
        organizmAtakujacy->umrzyj();
    }
}



