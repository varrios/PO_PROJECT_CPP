#include <iostream>
#include "Swiat.h"
#include <ncurses.h>

using namespace std;

int main() {
   initscr();
   refresh();
   cbreak();
   noecho();
   curs_set(0);
   int counter = 0;

   Swiat swiat(10,10);
   while(int ch = getch() != 'q'){
         swiat.wypiszSwiat();
         counter++;
         cbreak();
         noecho();
         refresh();
   }
   endwin();
}
