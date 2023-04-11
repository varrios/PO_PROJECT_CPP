//
// Created by lucja on 05.04.2023.
//

#ifndef PO_PROJECT_CPP_SWIAT_H
#define PO_PROJECT_CPP_SWIAT_H


class Swiat {
private:
    int szerokosc;
    int wysokosc;
    int tura;
    int iloscOrganizmow;
    char **plansza;
public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();
    void wypiszSwiat() const;
    void wykonajTure();


};


#endif //PO_PROJECT_CPP_SWIAT_H
