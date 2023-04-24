#include <iostream>
#include<windows.h>  
#include "Organizm.h"
#include "conio2.h"
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"

#define ARROW_UP 0x50
#define ARROW_DOWN 0x48
#define ARROW_LEFT 0x4b
#define ARROW_RIGHT 0x4d
#define ESCAPE 27
#define ENTER '\r'
#define BACKSPACE '\b'

using namespace std;
int main()
{
    Swiat swiat(10, 10);
    swiat.stworzPopulacje();
    Czlowiek* czlowiek = new Czlowiek(0, 0, &swiat);
    swiat.ustawGracza(czlowiek);
    swiat.dodajOrganizm(czlowiek);
    int ch;
    swiat.wypiszSwiat();
    while (true) {
        ch = getch();
        clrscr();
        switch (ch) {
        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:
            swiat.getGracz()->setWybor(ch);
            swiat.wykonajTure();
            swiat.wypiszSwiat();
            break;
        case 'Q':
        case 'q':
            exit(0);
            break;
        case 'S':
        case 's':
            swiat.zapiszGre();
            break;
        case 'L':
        case 'l':
            swiat.wczytajGre();
            break;
        }
        swiat.wypiszSwiat();
    }
}
