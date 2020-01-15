#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include "naglowek.h"
using namespace std;

int suma = 0, runda = 1, punktyRunda, nrPyt, nrPytF, numerPytania, bledy = 0;		//zmienne globalne
string nrOdp, punkty, trescPytania, pytania[340] = {}, trescPytan[5] = {}, imie;
string nrZad[5] = {}, wiersz[5] = {}, NrOdp[5] = {}, tresciOdpowiedzi[5] = {};
string pktF, trescF, pytaniaF[240] = {}, tresciF[5] = {}, nrZadF[5] = {};
string odpowiedziF[5] = {}, punktyF[5] = {}, pof[5] = {}, ppF[5] = {};
string miejsce[10] = {}, nazwa[10] = {}, wynik[10] = {};
string* wsk = &pytania[0];
string* wtp = &trescPytan[0];
string* ww = &wiersz[0];
string* wno = &NrOdp[0];
string* wto = &tresciOdpowiedzi[0];
string* wp = &pytaniaF[0];
string* wt = &tresciF[0];
string* wsm = &miejsce[0];
string* wsnz = &nazwa[0];
string* wsw = &wynik[0];
string* wsof = &odpowiedziF[0];
string* wspf = &punktyF[0];
string* wspof = &pof[0];
string* wsprpf = &ppF[0];

void powrot()
{
	system("cls");
	start();
}

void suchar()
{
	random_device zart;
	mt19937 generator(zart());
	uniform_int_distribution<int> losowanie(1, 6);
	int kawal = losowanie(generator);									//losowanie suchara

	ifstream suchar;
	suchar.open("suchary.txt");
	string historyjka, linijka[18];
	int i = 0;

	while (getline(suchar, historyjka))									//wczytanie pliku z sucharami do tabeli
	{
		linijka[i] = historyjka;
		i++;
	}

	ostringstream ins;
	ins << kawal;
	string kawalStr = ins.str();

	for (i = 2; i < 18; i++)											//wypisanie suchara
	{
		if (kawalStr == linijka[i - 2])
		{
			cout << "\t" << linijka[i - 1] << endl;
			cout << "\t" << linijka[i] << endl;
		}
	}
}
void przywitanie()
{
	cout << endl << "Witam bardzo serdecznie w programie 'Familiada'!";
	cout << endl << endl << "Na pocz¥tek kr¢tka historyjka: " << endl;
	suchar();
}

void instrukcje()
{
	char z = '0';
	cout << "\n\t\tRozgrywka podzielona zostaˆa na pi©† rund (w ka¾dej do zdobycia 100 punkt¢w)";
	cout << "\n\t\toraz finaˆ skˆadaj¥cy si© z nast©pnych pi©ciu rund.";
	cout << "\n\n\t\tW celu udzielenia odpowiedzi nale¾y wprowadzi† tekst zaczynaj¥c z du¾ej litery";
	cout << "\n\t\t(z wyj¥tkiem nazw wˆasnych) i zatwierdzi† klawiszem 'Enter'.";
	cout << "\n\n\t\tPo udzieleniu pi©ciu prawidˆowuch odpowiedzi lub popeˆnieniu trzech bˆ©d¢w";
	cout << "\n\t\trunda si© koäczy i nast©puje mo¾liwo˜† przejrzenia prawidˆowych odpowiedzi";
	cout << "\n\t\twraz z dost©pnymi punktami lub przej˜cia do nast©pnej rundy.";
	cout << "\n\n\t\tW przypadku wybrania opcji przejrzenia prawidˆowych odpowiedzi,";
	cout << "\n\t\tka¾dorazowo jest to mo¾liwe przez okres pi©ciu sekund.";
	cout << "\n\t\tPo tym czasie rozpoczyna si© nast©pna runda lub finaˆ.";
	cout << "\n\n\n\t\tOdpowiedzi zawieraj¥ polskie znaki diakrytyczne (¥, †, ©, ˆ, ä, ¢, ˜, «, ¾).";
	cout << endl << endl;
	while (z != '1')
	{
		cout.width(34);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cout.width(64);
		cout.fill(' ');
		cout << "1. Powr¢t.";
		cout << endl;
		cout.width(34);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cin >> z;
	}
	powrot();
}

string losowanie()
{
	random_device pytanie;
	mt19937 generator(pytanie());
	uniform_int_distribution<int> losowanie(1001, 1020);
	int zadanie = losowanie(generator);

	ostringstream ins;
	ins << zadanie;
	string zadStr = ins.str();

	ifstream zad;
	zad.open("zadania.txt");
	string tekst;

	int l = 0;

	while (getline(zad, tekst))
	{
		pytania[l] = tekst;
		l++;
	}

	for (int i = 16; i < 340; i += 17)
	{
		if (pytania[i - 16] == zadStr)
		{
			punktyRunda = i - 16;
			return trescPytania = pytania[i - 15];
		}
	}
	zad.close();
}
bool odp(string odpowiedz, string* wsk, int nrPyt)
{
	string a;
	int l = 3;
	for (int i = 0; i < 5; i++)
	{
		a = *(wsk + nrPyt + l - 1);
		if (odpowiedz == a)
		{
			nrOdp = *(wsk + nrPyt + l - 2);
			punkty = *(wsk + nrPyt + l);
			return true;
		}
		l += 3;
	}
	return false;
}
bool dOdp(string odpowiedz, string* wska, int odpowiedzi)
{
	for (int i = 0; i < odpowiedzi; i++)
	{
		if (odpowiedz == *(wska + i)) return false;
	}
	return true;
}
bool czyKoniecRundy(int proby, int odpowiedzi, int bledy)
{
	if (proby == 7 || odpowiedzi == 5 || bledy == 3) return true;
	else return false;
}
void tresciPytan()
{
	for (int i = 0; i < 5; i++)
	{
		trescPytan[i] = losowanie();
		for (int j = 0; j < i; j++)
		{
			if (trescPytan[j] == trescPytan[i])
			{
				trescPytan[i] = losowanie();
				j = -1;
			}
		}
	}
}
void numerZadania(string* wtp, string* wsk)
{
	string ll, lll;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 340; j++)
		{
			if (*(wtp + i) == *(wsk + j))
			{
				ostringstream iii;
				iii << j;
				string jStr = iii.str();
				nrZad[i] = jStr;
			}
		}
	}
}
void szablon()
{
	cout.width(20);
	cout.fill(' ');
	cout << "Suma punkt¢w";
	cout.width(20);
	cout.fill(' ');
	cout << "Runda";
	cout.width(20);
	cout.fill(' ');
	cout << "Bˆ©dy" << endl;
	cout.width(15);
	cout.fill(' ');
	cout << suma;
	cout.width(23);
	cout.fill(' ');
	cout << runda;
	cout.width(19);
	cout.fill(' ');
	cout << bledy << endl << endl;
	cout << "     ";
}
void poleOdpowiedzi(string* ww, int odpowiedzi, string* wno)
{
	int b[5] = {}, ppt[1] = {}, i = 0;
	for (int i = 0; i < 5; i++)
	{
		istringstream ii(*(wno + i));
		ii >> b[i];
	}
	string pt[1] = {}, aaa;
	bool w = false;
	if (odpowiedzi == 0)
	{
		for (int i = 1; i < 6; i++)
		{
			cout.width(5);
			cout.fill(' ');
			cout << i << ".   ";
			cout.width(35);
			cout.fill('-');
			cout << "";
			cout.width(12);
			cout.fill(' ');
			cout << "";
			cout.width(6);
			cout.fill('-');
			cout << "" << endl;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			int a = i;
			a++;
			w = false;
			for (int j = 0; j < odpowiedzi; j++)
			{
				if (b[j] == a)
				{
					cout << *(ww + j) << endl;
					w = true;
				}
			}
			if (w) continue;
			cout.width(5);
			cout.fill(' ');
			cout << a << ".   ";
			cout.width(35);
			cout.fill('-');
			cout << "";
			cout.width(12);
			cout.fill(' ');
			cout << "";
			cout.width(6);
			cout.fill('-');
			cout << "" << endl;
		}
	}
}
void prawidloweOdpowiedzi(string* wsk, int nrPyt)
{
	int l = 3;
	string to, tp;
	cout << endl << endl << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		int a = i;
		a++;
		to = *(wsk + nrPyt + l - 1);
		tp = *(wsk + nrPyt + l);
		if (to.length() >= 7 && to.length() < 15) cout << "    " << a << ".   " << to << "\t\t\t\t\t  " << tp << endl;
		else if (to.length() >= 15) cout << "    " << a << ".   " << to << "\t\t\t\t  " << tp << endl;
		else cout << "    " << a << ".   " << to << "\t\t\t\t\t\t  " << tp << endl;
		l += 3;
	}
}
void koniecRundy()
{
	char kr = '0';
	while (kr > '2' || kr < '1')
	{
		system("cls");
		cout << "\n\n\n\t1. Wy˜wietl prawidˆowe odpowiedzi." << endl;
		cout << "\t2. Przejd« dalej." << endl;
		cin >> kr;
	}
	switch (kr)
	{
	case '1':
		system("cls");
		prawidloweOdpowiedzi(wsk, nrPyt);
		Sleep(5000);
		system("cls");
		kr = 0;
		break;
	case '2':
		system("cls");
		kr = 0;
		break;
	}
}
void plansza()
{
	string odpowiedz, punkt[5] = {};
	int proby = 0, odpowiedzi = 0, r = 0;

	tresciPytan();
	numerZadania(wtp, wsk);
	for (runda = 1; runda < 6; runda++)
	{
		proby = 0;
		odpowiedzi = 0;
		bledy = 0;
		for (int i = 0; i < 5; i++)
		{
			NrOdp[i] = {};
			tresciOdpowiedzi[i] = {};
			punkt[i] = {};
			wiersz[i] = {};
		}
		while (!czyKoniecRundy(proby, odpowiedzi, bledy))
		{
			szablon();
			cout << "\t\t\t" << trescPytan[r] << endl << endl;
			cout.width(19);
			cout.fill(' ');
			cout << "Odpowiedzi";
			cout.width(43);
			cout.fill(' ');
			cout << "Punkty" << endl;
			poleOdpowiedzi(ww, odpowiedzi, wno);
			cout << endl << endl << "Wpisz odpowied«: ";
			getline(cin, odpowiedz);
			istringstream ii(nrZad[r]);
			ii >> nrPyt;
			if (odp(odpowiedz, wsk, nrPyt) && dOdp(odpowiedz, wno, odpowiedzi))
			{
				istringstream  sis(punkty);
				sis >> punktyRunda;
				suma += punktyRunda;
				NrOdp[odpowiedzi] = nrOdp;
				tresciOdpowiedzi[odpowiedzi] = odpowiedz;
				punkt[odpowiedzi] = punkty;
				if (odpowiedz.length() >= 7 && odpowiedz.length() < 15) wiersz[odpowiedzi] = "    " + NrOdp[odpowiedzi] + ".   " + tresciOdpowiedzi[odpowiedzi] + "\t\t\t\t\t  " + punkt[odpowiedzi];
				else if (odpowiedz.length() >= 15) wiersz[odpowiedzi] = "    " + NrOdp[odpowiedzi] + ".   " + tresciOdpowiedzi[odpowiedzi] + "\t\t\t\t  " + punkt[odpowiedzi];
				else wiersz[odpowiedzi] = "    " + NrOdp[odpowiedzi] + ".   " + tresciOdpowiedzi[odpowiedzi] + "\t\t\t\t\t\t  " + punkt[odpowiedzi];
				odpowiedzi++;
				proby++;
			}
			else
			{
				if (proby == 0)
				{
					proby++;
				}
				else
				{
					proby++;
					bledy++;
				}
			}
			if (odpowiedzi < 5)
			{
				system("cls");
			}
			else
			{
				system("cls");
				szablon();
				cout << "\t\t\t" << trescPytan[r] << endl << endl;
				cout.width(19);
				cout.fill(' ');
				cout << "Odpowiedzi";
				cout.width(43);
				cout.fill(' ');
				cout << "Punkty" << endl;
				poleOdpowiedzi(ww, odpowiedzi, wno);
				Sleep(1000);
				system("cls");
			}
		}
		r++;
		koniecRundy();
	}
}
string losowanieF()
{
	random_device pytanie;
	mt19937 generator(pytanie());
	uniform_int_distribution<int> losowanie(1001, 1020);
	int zadanie = losowanie(generator);

	ostringstream ins;
	ins << zadanie;
	string zadStr = ins.str();

	ifstream zad;
	zad.open("zadaniaF.txt");
	string tekst;

	int l = 0;

	while (getline(zad, tekst))
	{
		pytaniaF[l] = tekst;
		l++;
	}

	for (int i = 11; i < 240; i += 12)
	{
		if (pytaniaF[i - 11] == zadStr)
		{
			return trescF = pytaniaF[i - 10];
		}
	}
	zad.close();
}
void trF()
{
	for (int i = 0; i < 5; i++)
	{
		tresciF[i] = losowanieF();
		for (int j = 0; j < i; j++)
		{
			if (tresciF[j] == tresciF[i])
			{
				tresciF[i] = losowanieF();
				j = -1;
			}
		}
	}
}
void numerZadaniaF(string* ww, string* wsk)
{
	string ll, lll;
	int l = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 240; j++)
		{
			if (*(ww + i) == *(wsk + j))
			{
				ostringstream iii;
				iii << j;
				string jStr = iii.str();
				nrZadF[i] = jStr;
			}
		}
		istringstream iss(nrZadF[i]);
		iss >> l;
		*(wspof + i) = *(wsk + l + 1);
		*(wsprpf + i) = *(wsk + l + 2);
	}
}
bool odpF(string odpowiedz, string* wsk, int nrPyt)
{
	string a;
	int l = 2;
	for (int i = 0; i < 5; i++)
	{
		a = *(wsk + nrPyt + l - 1);

		if (odpowiedz == a)
		{
			pktF = *(wsk + nrPyt + l);
			return true;
		}
		l += 2;
	}
	return false;
}
void zakonczenie()
{
	char z = '0';
	string tof, tpof, tpkof;
	cout << " Twoje odpowiedzi";
	cout.width(9);
	cout.fill(' ');
	cout << "";
	cout << "Zdobyte punkty";
	cout.width(15);
	cout.fill(' ');
	cout << "";
	cout << "Najlepsze odpowiedzi";
	cout.width(14);
	cout.fill(' ');
	cout << "";
	cout << "Punkty" << endl;
	cout.width(95);
	cout.fill('=');
	cout << "" << endl;
	for (int i = 0; i < 5; i++)
	{
		tof = *(wsof + i);
		tpof = *(wspof + i);
		tpkof = *(wspf + i);
		cout << " " << *(wsof + i);
		if (tof.length() > 6 && tof.length() < 15)
		{
			cout << "\t\t\t" << *(wspf + i);
		}
		else if (tof.length() > 14 && tof.length() < 23)
		{
			cout << "\t\t" << *(wspf + i);
		}
		else if (tof.length() > 22)
		{
			cout << "\t" << *(wspf + i);
		}
		else
		{
			cout << "\t\t\t\t" << *(wspf + i);
		}
		if (tpkof.length() == 2)
		{
			cout.width(21);
			cout.fill(' ');
			cout << "";
			cout << *(wspof + i);
		}
		else
		{
			cout.width(22);
			cout.fill(' ');
			cout << "";
			cout << *(wspof + i);
		}
		if (tpof.length() > 6 && tpof.length() < 10)
		{
			cout << "\t\t\t\t" << "   " << *(wsprpf + i) << endl;
		}
		else if (tpof.length() > 9 && tpof.length() < 23)
		{
			cout << "\t\t\t" << "   " << *(wsprpf + i) << endl;
		}
		else if (tpof.length() > 22)
		{
			cout << "\t\t" << "   " << *(wsprpf + i) << endl;
		}
		else
		{
			cout << "\t\t\t\t" << "   " << *(wsprpf + i) << endl;
		}
	}
	cout.width(95);
	cout.fill('=');
	cout << "" << endl << endl << endl;
	cout.width(10);
	cout << endl;
	cout.width(20);
	cout.fill(' ');
	cout << "";
	cout << "Gratulacje " << imie << "! Zakoäczono rozgrywk© z dorobkiem " << suma << " punkt¢w." << endl << endl;

	while (z != '1')
	{
		cout.width(26);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cout.width(56);
		cout.fill(' ');
		cout << "1. Powr¢t.";
		cout << endl;
		cout.width(26);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cin >> z;
	}
}
void final()
{
	int s;
	string odpowiedz, t;

	trF();
	numerZadaniaF(wt, wp);
	for (int i = 0; i < 5; i++)
	{
		cout.width(20);
		cout.fill(' ');
		cout << endl << "";
		cout << tresciF[i] << endl;
		cout.width(20);
		cout.fill(' ');
		cout << "";
		if (i == 0)
		{
			while (cin.get() != '\n')
			{
				getline(cin, odpowiedz);
				*(wsof + i) = odpowiedz;

				istringstream iss(nrZadF[i]);
				iss >> nrPytF;

				if (odpF(odpowiedz, wp, nrPytF))
				{
					istringstream ss(pktF);
					ss >> s;
					suma += s;
					*(wspf + i) = pktF;
				}
				else
				{
					*(wspf + i) = '0';
				}
				continue;
				system("cls");
			}
		}
		getline(cin, odpowiedz);
		*(wsof + i) = odpowiedz;

		istringstream iss(nrZadF[i]);
		iss >> nrPytF;

		if (odpF(odpowiedz, wp, nrPytF))
		{
			istringstream ss(pktF);
			ss >> s;
			suma += s;
			*(wspf + i) = pktF;
		}
		else
		{
			*(wspf + i) = '0';
		}
		system("cls");
	}
}
void jedenGracz()
{
	cout << "\n\nWpisz swoje imi©: ";
	cin >> imie;
	cout << "\n\n\tWitaj, " << imie << "!";
	Sleep(2000);
	system("cls");
	plansza();
	final();
	zakonczenie();
	odczytanie();
	porownanie();
	wczytanie();
	suma = 0;
}

void odczytanie()
{
	int i = 0;
	string tekst;

	ifstream wyniki;
	wyniki.open("statystyki.txt");

	for (int i = 0; i < 10; i++)
	{
		wyniki >> miejsce[i];
		wyniki >> nazwa[i];
		wyniki >> wynik[i];
	}
	wyniki.close();
}
void wczytanie()
{
	ofstream noweW("statystyki.txt");

	for (int i = 0; i < 10; i++)
	{
		noweW << *(wsm + i);
		noweW << endl;
		noweW << *(wsnz + i);
		noweW << endl;
		noweW << *(wsw + i);
		noweW << endl;
	}
	noweW.close();
}
void porownanie()
{
	string sumaStr;
	int pkt;

	ostringstream os;
	os << suma;
	sumaStr = os.str();

	for (int i = 0; i < 10; i++)
	{
		istringstream iss(*(wsw + i));
		iss >> pkt;
		if (suma > pkt)
		{
			int a = i;
			--a;
			for (int j = 8; j > a; --j)
			{
				*(wsnz + j + 1) = *(wsnz + j);
				*(wsw + j + 1) = *(wsw + j);
			}

			*(wsnz + i) = imie;
			*(wsw + i) = sumaStr;
			break;
		}
	}
}
void czyszczenie()
{
	for (int i = 0; i < 10; i++)
	{
		int a = i;
		++a;
		ostringstream os;
		os << a;
		string aStr = os.str();
		*(wsm + i) = aStr;
		*(wsnz + i) = "------------";
		*(wsw + i) = "0";
	}
}
void szablonStat()
{
	cout.width(17);
	cout.fill(' ');
	cout << "Miejsce";
	cout.width(20);
	cout.fill(' ');
	cout << "Imi© Gracza";
	cout.width(20);
	cout.fill(' ');
	cout << "Wynik" << endl;
	cout.width(10);
	cout.fill(' ');
	cout << "";
	cout.width(47);
	cout.fill('=');
	cout << "" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.width(14);
		cout.fill(' ');
		cout << *(wsm + i);
		cout.width(23);
		cout.fill(' ');
		cout << *(wsnz + i);
		cout.width(18);
		cout.fill(' ');
		cout << *(wsw + i) << endl;
	}
	cout.width(10);
	cout.fill(' ');
	cout << "";
	cout.width(47);
	cout.fill('=');
	cout << "" << endl;
	cout << "\n\n";
	cout.width(10);
}
void statystyki()
{
	char z = '0';
	odczytanie();
	szablonStat();
	while (z != '1')
	{
		cout.width(10);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cout.width(40);
		cout.fill(' ');
		cout << "1. Powr¢t.";
		cout << endl;
		cout.width(10);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cin >> z;
	}
	powrot();
}
void reset()
{
	odczytanie();
	porownanie();
	czyszczenie();
	wczytanie();
}

void opcje()
{
	char z = '0';

	while (z != '2')
	{
		cout.width(10);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cout.width(45);
		cout.fill(' ');
		cout << "1. Zresetuj statystyki." << endl;
		cout.width(32);
		cout.fill(' ');
		cout << "2. Powr¢t." << endl;
		cout.width(10);
		cout.fill(' ');
		cout << "";
		cout.width(47);
		cout.fill('=');
		cout << "" << endl;
		cin >> z;
		system("cls");
		if (z == '1')
		{
			reset();
			powrot();
			break;
		}
		if (z == '2')
		{
			powrot();
			break;

		}
	}
}

void start()
{
	char tryb = '0';
	while (tryb > '5' || tryb < '1')
	{
		cout.width(40);
		cout.fill('=');
		cout << "" << endl;
		cout << "\t\tFAMILIADA" << endl;
		cout.width(40);
		cout.fill('=');
		cout << "" << endl << endl;
		cout << "\t1. Zagraj." << endl;
		cout << "\t2. Statystyki." << endl;
		cout << "\t3. Opcje." << endl;
		cout << "\t4. Instrukcja gry." << endl;
		cout << "\t5. Wyj˜cie." << endl;
		cin >> tryb;
		system("cls");
	}
	switch (tryb)
	{
	case '1':
		przywitanie();
		jedenGracz();
		powrot();
		break;
	case '2':
		statystyki();
		break;
	case '3':
		opcje();
		break;
	case '4':
		system("cls");
		instrukcje();
		break;
	case '5':
		break;
	}
}