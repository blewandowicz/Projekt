#include <iostream>
#include <conio.h>
#include <locale.h>
#include <vector>
//#include <algorithm>
#include <fstream>
#include <string>
//#include <stdlib.h>
#include <thread>
#include <chrono>
//#include <limits>
#include <Windows.h>
using namespace std;

//funkcje


void pomoc() {
	cout << "Dostêpne komendy to: lewo, prawo, przod, tyl, interakcja, rozgladanie, pomoc, koniec" << endl;
}




//Wyszukiwanie wersu
string wyszukajTekst(int wers, string adresPliku) {
	ifstream plik(adresPliku);
	string tekst;
	int licznik_wersow = 0;
	char wiersz[10000];
	if (plik.is_open()) {
		while (plik.getline(wiersz, 10000)) {
			if (licznik_wersow == wers) {
				tekst = wiersz;
				plik.close();
				return tekst;
			}
			else {
				licznik_wersow++;
			}
		}
	}
}
//Prolog

void prolog() {
	int x = 0;
	ifstream prolog("../pliki_tekstowe/prolog.txt");
	if (prolog.is_open()) {
		char znak;
		prolog.unsetf(ios::skipws);
		while (prolog >> znak) {
			cout << znak;
			if (GetKeyState(VK_SPACE) & 0x8000) {
				this_thread::sleep_for(chrono::milliseconds(1));
			}
			else {
				this_thread::sleep_for(chrono::milliseconds(20));
			}
		}
	}
	prolog.close();
	cout << endl << "Wcisnij enter aby kontynuowaæ";
	while (x != 13) {
		x = _getch();
	}
	system("cls");
}

//Epilog

void epilog() {
	int x = 0;
	ifstream epilog("../pliki_tekstowe/epilog.txt");
	if (epilog.is_open()) {
		char znak;
		epilog.unsetf(ios::skipws);
		while (epilog >> znak) {
			cout << znak;
			if (GetKeyState(VK_SPACE) & 0x8000) {
				this_thread::sleep_for(chrono::milliseconds(1));
			}
			else {
				this_thread::sleep_for(chrono::milliseconds(20));
			}
		}
	}
	epilog.close();
	cout << endl << endl << "Wcisnij enter aby zakoñczyæ";
	while (x != 13) {
		x = _getch();
	}
	exit(1);
}


//Menu_g³ówne

void menu_glowne() {
	int x;
	bool gameOn = false;
	while (gameOn == false) {
		system("cls");
		cout <<
			R"( 
########  ######## ##     ##  #######  
##     ## ##       ###   ### ##     ## 
##     ## ##       #### #### ##     ## 
##     ## ######   ## ### ## ##     ## 
##     ## ##       ##     ## ##     ## 
##     ## ##       ##     ## ##     ## 
########  ######## ##     ##  ####### 
)";
		cout << endl;

		cout << "1. Rozpocznij grê" << endl;
		cout << "2. Instrukcja" << endl;
		cout << "3. WyjdŸ" << endl;

		x = 0;

		while (x != 49 && x != 50 && x != 51) {
			x = _getch();
			if (x == 49) {
				gameOn = true;
				system("cls");
				//exit(1);
			}
			else if (x == 50) {
				system("cls");
				ifstream instrukcja;
				instrukcja.open("../pliki_tekstowe/Instrukcja.txt");

				if (instrukcja.is_open()) {


					char wiersz[10000]{};
					while (instrukcja.getline(wiersz, 10000)) {
						cout << wiersz << endl;
					}
					instrukcja.close();
				}
				else {
					cout << "Nie udalo sie otworzyc pliku" << endl;
				}
				_getch();
			}
			else if (x == 51) {
				exit(1);
			}
		}
	}
}






//struktura

struct pola {
	bool lewaSciana;
	bool prawaSciana;
	bool tylnaSciana;
	bool przedniaSciana;
	bool kontynuuj;
	bool korytarz;
	bool recepcja;
	int lewo(string(*wers)(int, string), int n);
	int prawo(string(*wers)(int, string), int n);
	int przod(string(*wers)(int, string), int n);
	int tyl(string(*wers)(int, string), int n);
	bool interakcja(string(*wers)(int, string), int n);
	int rozgladanie(string(*wers)(int, string), int n);
};

bool pola::interakcja(string(*wers)(int, string), int n) {
	bool kontynuuj = false;
	if (n == 7 || n == 12 || n == 27) {
		kontynuuj = true;
	}
	string tekst = wers(n, "../pliki_tekstowe/interakcja.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	return kontynuuj;
}


int pola::rozgladanie(string(*wers)(int, string), int n) {
	string tekst = wers(n, "../pliki_tekstowe/rozgladanie.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	return n;
}




int pola::lewo(string (*wers)(int, string), int n) {
	string tekst = wers(n, "../pliki_tekstowe/lewo.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	if (lewaSciana == true) {
		return n;
	}
	else {
		return n - 1;
	}
}

int pola::prawo(string(*wers)(int, string), int n) {
	string tekst = wers(n, "../pliki_tekstowe/prawo.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	if (prawaSciana == true) {
		return n;
	}
	else {
		return n + 1;
	}
}

int pola::przod(string(*wers)(int, string), int n) {
	string tekst = wers(n, "../pliki_tekstowe/przod.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	if (przedniaSciana == true) {
		return n;
	}
	else if (korytarz == true) {
			return n + 1;
	}
	else if (recepcja == true) {
		return n + 4;
	}
	else {
			return n + 3;
	}
}

int pola::tyl(string(*wers)(int, string), int n) {
	string tekst = wers(n, "../pliki_tekstowe/tyl.txt");
	for (int i = 0; i < tekst.length(); i++) {
		cout << tekst[i];
		if (GetKeyState(VK_SPACE) & 0x8000) {
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	cout << endl;
	if (tylnaSciana == true) {
		return n;
	}
	else if (korytarz == true) {
		return n - 1;
	}
	else if (recepcja == true) {
		return n - 4;
	}
	else {
		return n - 3;
	}
}

// komendy

int komendy(pola& pole, int lokacja, string komenda, int& licznik) {
	if (komenda == "lewo") {
		return pole.lewo(*wyszukajTekst, lokacja);
	}
	else if (komenda == "prawo") {
		return pole.prawo(*wyszukajTekst, lokacja);
	}
	else if (komenda == "przod") {
		return pole.przod(*wyszukajTekst, lokacja);
	}
	else if (komenda == "tyl") {
		return pole.tyl((*wyszukajTekst), lokacja);
	}
	else if (komenda == "rozgladanie") {
		return pole.rozgladanie((*wyszukajTekst), lokacja);
	}
	else if (komenda == "interakcja") {
		pole.kontynuuj = pole.interakcja((*wyszukajTekst), lokacja);
		return lokacja;
	}
	else if (komenda == "koniec") {
		exit(1);
	}
	else if (komenda == "pomoc") {
		pomoc();
		return lokacja;
	}
	else {
		cout << "Nie rozumiem." << endl;
		licznik++;
		if (licznik == 3) {
			cout << "Wpisz 'pomoc' aby wyœwietliæ listê dostêpnych komend" << endl;
			licznik = 0;
			return lokacja;
		}
		else {
			return lokacja;
		}
	}
		
}


int main() {

	int licznik = 0;
	// pola
	vector<pola> pole(30);

	int recepcja[16] = { 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28 };
	int leweSciany[11] = { 0,3,6,9,10,11,12,13,17,21,25 };
	int praweSciany[11] = { 2,5,8,9,10,11,12,16,20,24,28 };
	int przednieSciany[8] = { 6,7,8,12,25,26,27,28 };
	int tylneSciany[8] = { 0,1,2,9,13,14,15,16};
	int korytarz[4] = { 9, 10, 11, 12 };

	for (int i = 0; i < 29; i++) {
		if (find(begin(tylneSciany), end(tylneSciany), i) != end(tylneSciany)) {
			pole[i].tylnaSciana = true;
			if (find(begin(leweSciany), end(leweSciany), i) != end(leweSciany)) {
				pole[i].lewaSciana = true;
			}
			if (find(begin(praweSciany), end(praweSciany), i) != end(praweSciany)) {
				pole[i].prawaSciana = true;
			}
			if (find(begin(korytarz), end(korytarz), i) != end(korytarz)) {
				pole[i].korytarz = true;
			}
			if (find(begin(recepcja), end(recepcja), i) != end(recepcja)) {
				pole[i].recepcja = true;
			}
		}
		else if (find(begin(przednieSciany), end(przednieSciany), i) != end(przednieSciany)) {
			pole[i].przedniaSciana = true;
			if (find(begin(leweSciany), end(leweSciany), i) != end(leweSciany)) {
				pole[i].lewaSciana = true;
			}
			if (find(begin(praweSciany), end(praweSciany), i) != end(praweSciany)) {
				pole[i].prawaSciana = true;
			}
			if (find(begin(korytarz), end(korytarz), i) != end(korytarz)) {
				pole[i].korytarz = true;
			}
			if (find(begin(recepcja), end(recepcja), i) != end(recepcja)) {
				pole[i].recepcja = true;
			}
		}
		else if (find(begin(leweSciany), end(leweSciany), i) != end(leweSciany)) {
			pole[i].lewaSciana = true;
			if (find(begin(praweSciany), end(praweSciany), i) != end(praweSciany)) {
				pole[i].prawaSciana = true;
			}
			if (find(begin(korytarz), end(korytarz), i) != end(korytarz)) {
				pole[i].korytarz = true;
			}
			if (find(begin(recepcja), end(recepcja), i) != end(recepcja)) {
				pole[i].recepcja = true;
			}
		}
		else if (find(begin(praweSciany), end(praweSciany), i) != end(praweSciany)) {
			pole[i].prawaSciana = true;
			if (find(begin(recepcja), end(recepcja), i) != end(recepcja)) {
				pole[i].recepcja = true;
			}
		} else if (find(begin(recepcja), end(recepcja), i) != end(recepcja)) {
			pole[i].recepcja = true;
		}
		

	}



	//gra
	


	setlocale(LC_CTYPE, "Polish");
	int gameState = 1;
	while (true) {
		if (gameState == 1) {
			menu_glowne();
			gameState = 2;
		}
		else if (gameState == 2) {
			prolog();
			gameState = 3;
		}
		else if (gameState == 3) {
			int lokacja = 0;
			string komenda;
			while (pole[7].kontynuuj != true) {
				cout << endl;
				cin >> komenda;
				cout << endl;
				lokacja = komendy(pole[lokacja],lokacja, komenda, licznik);
			}
			gameState = 4;
		} else if (gameState == 4) {
			 int lokacja = 9;
			 string komenda;
			 while (pole[12].kontynuuj != true) {
				 cout << endl;
				 cin >> komenda;
				 cout << endl;
				 lokacja = komendy(pole[lokacja], lokacja, komenda, licznik);
			 } 
			 gameState = 5;
		}
		else if (gameState == 5) {
			 int lokacja = 15;
			 string komenda;
			 while (pole[27].kontynuuj != true) {
				 cout << endl;
				 cin >> komenda;
				 cout << endl;
				 lokacja = komendy(pole[lokacja], lokacja, komenda, licznik);
			 }
			 gameState = 6;
		}
		else if (gameState == 6) {
			this_thread::sleep_for(chrono::milliseconds(2000));
			system("cls");
			epilog();
		}
	}
	system("pause");
	return 0;
}