#include <iostream>
#include <ctime>

using namespace std;

void losujPonownie(int& a, int& b, char** tab, int  rozmiar) {				// funkcja, ktora powtarza losowanie miejsca na bombe, jezeli bomba wylosuje sie 2 razy w tym samym miejscu
	int zmiana = 0;															// a, b - wspolrzedne bomby, tab - tablica rozmieszczenia bomb, rozmiar - rozmiar tablicy
	for (int i = 0; i < rozmiar; i++) {										// zmiana - informuje, czy zaszla zmiana wspolrzednych
		if (tab[a][b] == 'b') {
			a = rand() % rozmiar;											// ponowne losowanie
			b = rand() % rozmiar;
			zmiana = 1;
		}
	}
	if (zmiana == 1) {														// jezeli zaszla zmiana to rekurencyjnie wywolujemy funkcje
		zmiana = 0;
		losujPonownie(a, b, tab, rozmiar);
	}
}

void wypiszMacierz(char** tab, int n) {										// funkcja wyswietlajaca plansze
	cout << "   ";															// tab - tablica do wyswietlenia, n - rozmiar tablicy do wyswietlenia
	for (int i = 0; i < n; i++) {
		if (i < 10) cout << i << ' ';										// wyswietlenie numerow kolumn przed plansza
		else cout << i % 10 << ' ';
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		if (i < 10) cout << i << "  ";										// wyswietlenie numerow wierszy przed plansza
		else cout << i << " ";
		for (int j = 0; j < n; j++) {
			cout << tab[i][j] << ' ';										// wyswietlenie planszy
		}
		cout << ' ' << i << endl;											// wyswietlenie numerow wierszy za plansza
	}
	cout << endl;
	cout << "   ";
	for (int i = 0; i < n; i++) {
		if (i < 10) cout << i << ' ';										// wyswietlenie numerow wierszy za plansza
		else cout << i % 10 << ' ';
	}
	cout << endl;
}

void wypelnijMacierzZnakiem(char** tab, int rozmiar, char znak) {			// funkcja wypelnia cala macierz jednym znakiem
	for (int i = 0; i < rozmiar; i++) {										// tab - macierz do wypelnienia, rozmiar - rozmiar macierzy, znak - znak, ktorym wypelniamy macierz
		for (int j = 0; j < rozmiar; j++) {
			tab[i][j] = znak;												// wypelnienie macierzy znakiem
		}
	}
}

void wypelnijMacierzBombami(char** tab, int rozmiar, int bomby) {			// funkcja wstawiajaca bomby na plansze
	srand(time(NULL));														// tab - macierz, do ktorej wpisujemy bomby, rozmiar - rozmiar macierzy, bomby - ilosc bomb do wpisania
	int a, b;																// a, b - wspolrzedne bomby
	for (int i = 0; i < bomby; i++) {
		a = rand() % rozmiar;
		b = rand() % rozmiar;												// wylosowanie wspolrzednych
		losujPonownie(a, b, tab, rozmiar);									// ewentualne ponowne wylosowanie
		tab[a][b] = 'b';													// wpisanie bomby na plansze
	}
}

void wypelnijMacierzCyframi(char** tab, int rozmiar) {						// funkcja wpisujaca cyfry na plansze
	int licznik = 0;														// tab - plansza do wpisywania cyfr, rozmiar - rozmiar, licznik - licznik bomb dookola pola
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (tab[i][j] != 'b') {											
				if (i == 0 && j == 0) {										// sprawdzanie pol w naroznikach
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i + 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i == 0 && j == rozmiar - 1) {
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i + 1][j - 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i == rozmiar - 1 && j == 0) {
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i - 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i == rozmiar - 1 && j == rozmiar - 1) {
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i - 1][j - 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i == 0 && j > 0 && j < rozmiar - 1) {					// sprawdzanie pol na krawedziach
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i + 1][j - 1] == 'b') licznik++;
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i + 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i == rozmiar - 1 && j > 0 && j < rozmiar - 1) {
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i - 1][j - 1] == 'b') licznik++;
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i - 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (j == rozmiar - 1 && i > 0 && i < rozmiar - 1) {
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i - 1][j - 1] == 'b') licznik++;
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i + 1][j - 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (j == 0 && i > 0 && i < rozmiar - 1) {
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i - 1][j + 1] == 'b') licznik++;
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i + 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
				if (i > 0 && i < rozmiar - 1 && j > 0 && j < rozmiar - 1) {					// sprawdzenie reszty pol
					if (tab[i - 1][j - 1] == 'b') licznik++;
					if (tab[i - 1][j] == 'b') licznik++;
					if (tab[i - 1][j + 1] == 'b') licznik++;
					if (tab[i][j - 1] == 'b') licznik++;
					if (tab[i][j + 1] == 'b') licznik++;
					if (tab[i + 1][j - 1] == 'b') licznik++;
					if (tab[i + 1][j] == 'b') licznik++;
					if (tab[i + 1][j + 1] == 'b') licznik++;
					tab[i][j] = licznik + '0';
					licznik = 0;
				}
			}
		}
	}
}

void sprawdzSasiada(char** tab1, char** tab2, int** tab3, int rozmiar, int x, int y) {					// funkcja odkrywajaca kolejne pola
	tab3[x][y] = 1;			// ustawienie pola wprowadzonego przez uzytkownika na sprawdzone			// tab1 - tablica z rozmieszczeniem bomb, tab2 - tablica wyswietlana dla uzytkownika, tab3 - tablica sprawdzonych pol, rozmiar - rozmiar, x, y - wspolrzedne pola wprowadzone przez uzytkownika
	if (x == 0 && y == 0) {																		// sprawdzenie naroznikow
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {									// jezeli pole puste
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {							// jezeli pole z cyfra
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x + 1][y + 1] == '0' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y + 1);
		}
		else if (tab2[x + 1][y + 1] != 'b' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
		}
	}
	if (x == 0 && y == rozmiar - 1) {
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x + 1][y - 1] == '0' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y - 1);
		}
		else if (tab2[x + 1][y - 1] != 'b' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
		}
	}
	if (x == rozmiar - 1 && y == 0) {
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		else if (tab2[x - 1][y + 1] != 'b' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
		}
	}
	if (x == rozmiar - 1 && y == rozmiar - 1) {
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		if (tab2[x - 1][y - 1] == '0' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y - 1);
		}
		else if (tab2[x - 1][y - 1] != 'b' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
		}
	}
	if (x == 0 && y > 0 && y < rozmiar - 1) {												// sprawdzenie krawedzi
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x + 1][y - 1] == '0' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y - 1);
		}
		else if (tab2[x + 1][y - 1] != 'b' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x + 1][y + 1] == '0' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y + 1);
		}
		else if (tab2[x + 1][y + 1] != 'b' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
		}
	}
	if (x == rozmiar - 1 && y > 0 && y < rozmiar - 1) {
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x - 1][y - 1] == '0' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y - 1);
		}
		else if (tab2[x - 1][y - 1] != 'b' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
		}
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		if (tab2[x - 1][y + 1] == '0' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y + 1);
		}
		else if (tab2[x - 1][y + 1] != 'b' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
		}
	}
	if (y == 0 && x > 0 && x < rozmiar - 1) {
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x - 1][y + 1] == '0' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y + 1);
		}
		else if (tab2[x - 1][y + 1] != 'b' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
		}
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x + 1][y + 1] == '0' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y + 1);
		}
		else if (tab2[x + 1][y + 1] != 'b' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
		}
	}
	if (y == rozmiar - 1 && x > 0 && x < rozmiar - 1) {
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x - 1][y - 1] == '0' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y - 1);
		}
		else if (tab2[x - 1][y - 1] != 'b' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
		}
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x + 1][y - 1] == '0' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y - 1);
		}
		else if (tab2[x + 1][y - 1] != 'b' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
		}
	}
	if (x > 0 && x < rozmiar - 1 && y > 0 && y < rozmiar - 1) {									// sprawdzenie reszty pol
		if (tab2[x - 1][y - 1] == '0' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y - 1);
		}
		else if (tab2[x - 1][y - 1] != 'b' && tab3[x - 1][y - 1] == 0) {
			tab1[x - 1][y - 1] = tab2[x - 1][y - 1];
			tab3[x - 1][y - 1] = 1;
		}
		if (tab2[x - 1][y] == '0' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y);
		}
		else if (tab2[x - 1][y] != 'b' && tab3[x - 1][y] == 0) {
			tab1[x - 1][y] = tab2[x - 1][y];
			tab3[x - 1][y] = 1;
		}
		if (tab2[x - 1][y + 1] == '0' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x - 1, y + 1);
		}
		else if (tab2[x - 1][y + 1] != 'b' && tab3[x - 1][y + 1] == 0) {
			tab1[x - 1][y + 1] = tab2[x - 1][y + 1];
			tab3[x - 1][y + 1] = 1;
		}
		if (tab2[x][y - 1] == '0' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y - 1);
		}
		else if (tab2[x][y - 1] != 'b' && tab3[x][y - 1] == 0) {
			tab1[x][y - 1] = tab2[x][y - 1];
			tab3[x][y - 1] = 1;
		}
		if (tab2[x][y + 1] == '0' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x, y + 1);
		}
		else if (tab2[x][y + 1] != 'b' && tab3[x][y + 1] == 0) {
			tab1[x][y + 1] = tab2[x][y + 1];
			tab3[x][y + 1] = 1;
		}
		if (tab2[x + 1][y - 1] == '0' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y - 1);
		}
		else if (tab2[x + 1][y - 1] != 'b' && tab3[x + 1][y - 1] == 0) {
			tab1[x + 1][y - 1] = tab2[x + 1][y - 1];
			tab3[x + 1][y - 1] = 1;
		}
		if (tab2[x + 1][y] == '0' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y);
		}
		else if (tab2[x + 1][y] != 'b' && tab3[x + 1][y] == 0) {
			tab1[x + 1][y] = tab2[x + 1][y];
			tab3[x + 1][y] = 1;
		}
		if (tab2[x + 1][y + 1] == '0' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
			sprawdzSasiada(tab1, tab2, tab3, rozmiar, x + 1, y + 1);
		}
		else if (tab2[x + 1][y + 1] != 'b' && tab3[x + 1][y + 1] == 0) {
			tab1[x + 1][y + 1] = tab2[x + 1][y + 1];
			tab3[x + 1][y + 1] = 1;
		}
	}
}

void dajPodpowiedz(char** tab1, int rozmiar) {													// funkcja szukajaca miejsca z bomba
	int znaleziono = 0;		//zmienna mowiaca czy znaleziono bombe								// tab1 - tablica wyswietlana uzytkownikowi, rozmiar - rozmiar
	int x, y;				// wspolrzedne ostateczne polozenia bomby
	int a, b;				// wspolrzedne tymczasowe polozenia bomby
	int licznikf = 0;		// licznik flag
	int licznikb = 0;		// licznik bomb
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (znaleziono == 0) {															// sprawdzenie czy znaleziono juz bombe
				if (tab1[i][j] != '0' && tab1[i][j] != '#' && tab1[i][j] != 'f') {			// znalezienie cyfry na planszy
						if (i == 0 && j == 0) {												// sprawdzenie naroznikow
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {			// jezeli cyfra ma wokol siebie zakryte pole lub flage
								if (tab1[i + 1][j] == 'f')
								licznikf++;													// zwiekszenie licznika
								if (tab1[i + 1][j] == '#') {
									a = i + 1;												// wpisanie wspolrzednych mozliwej bomby do wspolrzednych tymczasowych
									b = j;
									licznikb++;												// zwiekszenie licznika
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if (tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j + 1] == '#' || tab1[i + 1][j + 1] == 'f') {
								if (tab1[i + 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j + 1] == '#') {
									a = i + 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {					// jezeli liczniki zgadzaja sie z cyferka i jest miejsce na bombe
								znaleziono = 1;																// ustawienie flagi
								x = a;
								y = b;																		// wpisanie wspolrzednych ostatecznych
							}
							licznikf = 0;																	// wyzerowanie licznikow
							licznikb = 0;
						}
						if (i == 0 && j == rozmiar - 1) {
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {
								if(tab1[i + 1][j] == 'f')
								licznikf++;
								if (tab1[i + 1][j] == '#') {
									a = i + 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if(tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j - 1] == '#' || tab1[i + 1][j - 1] == 'f') {
								if (tab1[i + 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j - 1] == '#') {
									a = i + 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (i == rozmiar - 1 && j == 0) {
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if(tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if(tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i - 1][j + 1] == '#' || tab1[i - 1][j + 1] == 'f') {
								if (tab1[i - 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j + 1] == '#') {
									a = i - 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (i == rozmiar - 1 && j == rozmiar - 1) {
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if (tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if (tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i - 1][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if(tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i - 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (i == 0 && j > 0 && j < rozmiar - 1) {													// sprawdzenie krawedzi
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if (tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if (tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j - 1] == '#' || tab1[i + 1][j - 1] == 'f') {
								if (tab1[i + 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j - 1] == '#') {
									a = i + 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {
								if (tab1[i + 1][j] == 'f')
								licznikf++;
								if (tab1[i + 1][j] == '#') {
									a = i + 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i + 1][j + 1] == '#' || tab1[i + 1][j + 1] == 'f') {
								if (tab1[i + 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j + 1] == '#') {
									a = i + 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (i == rozmiar - 1 && j > 0 && j < rozmiar - 1) {
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if (tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if(tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i - 1][j - 1] == '#' || tab1[i - 1][j - 1] == 'f') {
								if (tab1[i - 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j - 1] == '#') {
									a = i - 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if(tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i - 1][j + 1] == '#' || tab1[i - 1][j + 1] == 'f') {
								if (tab1[i - 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j + 1] == '#') {
									a = i - 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (j == 0 && i > 0 && i < rozmiar - 1) {
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if (tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {
								if (tab1[i + 1][j] == 'f')
								licznikf++;
								if (tab1[i + 1][j] == '#') {
									a = i + 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i - 1][j + 1] == '#' || tab1[i - 1][j + 1] == 'f') {
								if (tab1[i - 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j + 1] == '#') {
									a = i - 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if (tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j + 1] == '#' || tab1[i + 1][j + 1] == 'f') {
								if (tab1[i + 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j + 1] == '#') {
									a = i + 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (j == rozmiar - 1 && i > 0 && i < rozmiar - 1) {
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if(tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {
								if (tab1[i + 1][j] == 'f')
								licznikf++;
								if (tab1[i + 1][j] == '#') {
									a = i + 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i - 1][j - 1] == '#' || tab1[i - 1][j - 1] == 'f') {
								if (tab1[i - 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j - 1] == '#') {
									a = i - 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if (tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j - 1] == '#' || tab1[i + 1][j - 1] == 'f') {
								if (tab1[i + 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j - 1] == '#') {
									a = i + 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (licznikf + licznikb == tab1[i][j] - '0' && licznikb != 0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
						if (j < rozmiar - 1 && j > 0 && i > 0 && i < rozmiar - 1){									// sprawdzenie reszty pol
							if (tab1[i - 1][j - 1] == '#' || tab1[i - 1][j - 1] == 'f') {
								if (tab1[i - 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j - 1] == '#') {
									a = i - 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i - 1][j] == '#' || tab1[i - 1][j] == 'f') {
								if (tab1[i - 1][j] == 'f')
								licznikf++;
								if (tab1[i - 1][j] == '#') {
									a = i - 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i - 1][j + 1] == '#' || tab1[i - 1][j + 1] == 'f') {
								if (tab1[i - 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i - 1][j + 1] == '#') {
									a = i - 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i][j - 1] == '#' || tab1[i][j - 1] == 'f') {
								if (tab1[i][j - 1] == 'f')
								licznikf++;
								if (tab1[i][j - 1] == '#') {
									a = i;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i][j + 1] == '#' || tab1[i][j + 1] == 'f') {
								if (tab1[i][j + 1] == 'f')
								licznikf++;
								if (tab1[i][j + 1] == '#') {
									a = i;
									b = j + 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j - 1] == '#' || tab1[i + 1][j - 1] == 'f') {
								if (tab1[i + 1][j - 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j - 1] == '#') {
									a = i + 1;
									b = j - 1;
									licznikb++;
								}
							}
							if (tab1[i + 1][j] == '#' || tab1[i + 1][j] == 'f') {
								if (tab1[i + 1][j] == 'f')
								licznikf++;
								if (tab1[i + 1][j] == '#') {
									a = i + 1;
									b = j;
									licznikb++;
								}
							}
							if (tab1[i + 1][j + 1] == '#' || tab1[i+1][j+1] == 'f') {
								if (tab1[i + 1][j + 1] == 'f')
								licznikf++;
								if (tab1[i + 1][j + 1] == '#') {
									a = i + 1;
									b = j + 1;
									licznikb++;
								}
							}
							if (licznikf+licznikb == tab1[i][j] - '0' && licznikb!=0) {
								znaleziono = 1;
								x = a;
								y = b;
							}
							licznikf = 0;
							licznikb = 0;
						}
				}
			}
		}

	}
	if (znaleziono == 1) {																	// jezeli znalazl bombe to wypisuje wspolrzedne
		cout << "Bomba znajduje sie w miejscu o wspolrzednych: " << endl;
		cout << "Wspolrzedna pionowa: " << x << endl;
		cout << "Wspolrzedna pozioma: " << y << endl;
	}
	if (znaleziono == 0) {																	// jezeli nie znalazl bomby to pisze
		cout << "Nie mozna dac podpowiedzi." << endl;
	}
}

int main() {
	int bomby, rozmiar;							// bomby - zmienna przechowujaca ilosc bomb, rozmiar - zmienna przechowujaca rozmiar planszy
	int x, y;									// x,y - zmienne przechowujace wspolrzedne wprowadzone przez uzytkownika
	int wygrana = 0;							// wygrana - zmienna mowiaca czy uzytkownik spelnil wymagania, aby wygrac
	char opcja, flaga;							// opcja - zmienna przechowujaca wybrana przez uzytkownika opcje, flaga - zmienna przechowujaca wybrana opcje postawienia flagi
	cout << "Podaj rozmiar planszy: ";
	cin >> rozmiar;								// wprowadzenie rozmiaru planszy
	cout << endl;
	cout << "Podaj ilosc bomb: ";
	cin >> bomby;								// wprowadzenie ilosci bomb
	cout << endl;
	char** planszaP = new char* [rozmiar];	
	for (int i = 0; i < rozmiar; i++) {			// inicjalizacja planszy rozmieszczenia bomb
		planszaP[i] = new char[rozmiar];
	}
	char** planszaW = new char* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {			// inicjalizacja planszy wyswietlanej dla uzytkownika
		planszaW[i] = new char[rozmiar];
	}
	int** sprawdzone = new int* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {			// tablica przechowujaca sprawdzone przez funkcje pola
		sprawdzone[i] = new int[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			sprawdzone[i][j] = 0;				// ustawienie pol tablicy na 0
		}
	}
	wypelnijMacierzZnakiem(planszaW, rozmiar, '#');		// zakrycie pol planszy
	wypelnijMacierzBombami(planszaP, rozmiar, bomby);	// wylosowanie miejsc na bomby	
	wypelnijMacierzCyframi(planszaP, rozmiar);			// przypisanie cyfr na swoje miejsca
	//wypiszMacierz(planszaP, rozmiar);					// wyswietlenie rozmieszczenia bomb
	cout << endl;
	while (1) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (planszaP[i][j] != 'b' && planszaW[i][j] == '#') wygrana = 0;	// sprawdzenie czy uzytkownik juz wygral
			}
		}
		wypiszMacierz(planszaW, rozmiar);					// wypisanie planszy do wyswietlania
		if (wygrana == 1) {
			cout << "Brawo, wygrales :)" << endl;			// jezeli wygral to gratulacje
			return 0;
		}
		cout << endl;
		cout << "Dostepne opcje: " << endl;
		cout << "s - strzal" << endl;
		cout << "f - flaga" << endl;						// menu
		cout << "p - podpowiedz" << endl;
		cout << "Wybierz opcje: ";
		cin >> opcja;										// wczytanie wybranej opcji
		cout << endl;
		if (opcja == 's') {									// s - opcja strzalu
			cout << "Strzelaj: " << endl;
			cout << "Wspolrzedna piononwa: " << endl;
			cin >> x;										// wczytanie wspolrzednej pionowej
			cout << "Wspolrzedna pozioma: " << endl;	
			cin >> y;										// wczytanie wspolrzednej poziomej
			if (planszaP[x][y] == 'b') {
				wypiszMacierz(planszaP, rozmiar);
				cout << "Bomba, przegrales :(" << endl;		// jezeli uzytkownik trafi w bombe, zakonczenie rozgrywki
				return 0;
			}
			if (planszaP[x][y] != 'b' && planszaP[x][y] != '0') planszaW[x][y] = planszaP[x][y];		// jezeli uzytkownik odkryje cyfre to wpisujemy ja do planszy wyswietlanej
			if (planszaP[x][y] == '0') {
				planszaW[x][y] = planszaP[x][y];												// jezeli uzytkownik trafi na puste pole to odkrywamy odpowiednia ilosc pol
				sprawdzSasiada(planszaW, planszaP, sprawdzone, rozmiar, x, y);
			}
		}
		if (opcja == 'f') {															// f - opcja flagowania
			cout << "Dostepne opcje: " << endl;	
			cout << "d - daj dlage" << endl;										
			cout << "z - zdejmij flage" << endl;
			cout << "Wybierz opcje: ";
			cin >> flaga;										// wczytanie opcji flagowania
			if (flaga == 'd') {										// d - opcja polozenia flagi
				cout << "Wspolrzedna piononwa: " << endl;
				cin >> x;											// wczytanie wspolrzednych polozenia flagi
				cout << "Wspolrzedna pozioma: " << endl;
				cin >> y;
				planszaW[x][y] = 'f';								// wpisanie flagi na miejsce
			}
			if (flaga == 'z') {										// z - opcja zdjecia flagi
				cout << "Wspolrzedna piononwa: " << endl;
				cin >> x;											// wczytanie wspolrzednych zdjecia flagi
				cout << "Wspolrzedna pozioma: " << endl;
				cin >> y;
				planszaW[x][y] = '#';								// zakrycie flagi
			}
		}
		if (opcja == 'p') {									// p - opcja podpowiedzi
			dajPodpowiedz(planszaW, rozmiar);
		}
		wygrana = 1;										// ustawienie wygranej na 1, na poczatku petli sprawdzenie czy spelnia warunki
	}
}