# Cel projektu

Celem projektu jest implementacja programu o charakterze symulatora wirtualnego świata,
który ma mieć strukturę dwuwymiarowej kraty. W świecie tym będą
istniały proste formy życia o odmiennym zachowaniu. Każdy z organizmów zajmuje dokładnie
jedno pole w tablicy, na każdym polu może znajdować się co najwyżej jeden organizm (w
przypadku kolizji jeden z nich powinien zostać usunięty lub przesunięty).
Symulator ma mieć charakter turowy. W każdej turze wszystkie organizmy istniejące na
świecie mają wykonać akcję stosowną do ich rodzaju. Część z nich będzie się poruszała (organizmy
zwierzęce), część będzie nieruchoma (organizmy roślinne). W przypadku kolizji (jeden z
organizmów znajdzie się na tym samym polu, co inny) jeden z organizmów zwycięża, zabijając (np.
wilk) lub odganiając (np. żółw) konkurenta. Kolejność ruchów organizmów w turze zależy od ich
inicjatywy. Pierwsze ruszają się zwierzęta posiadające najwyższą inicjatywę. W przypadku zwierząt
o takiej samej inicjatywie o kolejności decyduje zasada starszeństwa (pierwszy rusza się dłużej
żyjący). Zwycięstwo przy spotkaniu zależy od siły organizmu, choć będą od tej zasady wyjątki.
Przy równej sile zwycięża organizm, który zaatakował. Specyficznym rodzajem
zwierzęcia ma być Człowiek. W przeciwieństwie do zwierząt, człowiek nie porusza się w sposób
losowy. Kierunek jego ruchu jest determinowany przed rozpoczęciem tury za pomocą klawiszy
strzałek na klawiaturze. Człowiek posiada też specjalną umiejętność którą
można aktywować osobnym przyciskiem. Aktywowana umiejętność pozostaje czynna przez 5
kolejnych tur, po czym następuje jej dezaktywacja. Po dezaktywacji umiejętność nie może być
aktywowana przed upływem 5 kolejnych tur. Przy uruchomieniu programu na planszy powinno się
pojawić po kilka sztuk wszystkich rodzajów zwierząt oraz roślin. Okno programu powinno
zawierać pole, w którym wypisywane będą informacje o rezultatach walk, spożyciu roślin i innych
zdarzeniach zachodzących w świecie.

# Sterowanie

<ul>
  <li>q - wyjście z gry</li>
  <li>s - zapis stanu gry (pierwsze kliknięcie to włączenie możliwości wpisania nazwy, drugie to zapis)</li>
  <li>l - wczytanie stanu gry (pierwsze kliknięcie to włączenie możliwości wpisania nazwy, drugie to wczytanie)</li>
  <li>w, a, s, d - sterowanie postacią</li>
</ul>
