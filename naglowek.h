#include <string>
#pragma once
using namespace std;

void start();																	//1
void przywitanie();																//1
void jedenGracz();																//1
void instrukcje();																//1
void statystyki();																//1		//S
void odczytanie();																//1		//T
void wczytanie();																//1		//A
void porownanie();																//1		//T
void czyszczenie();																//1		//S
void szablonStat();																//1		//
void powrot();																	//1
void opcje();																	//1
void reset();																	//1
void suchar();																	//1		
void plansza();																	//1			//
string losowanie();																//1			//P
bool odp(string odpowiedz, string* wsk, int nrPyt);								//1			//L
bool dOdp(string odpowiedz, string* wska, int odpowiedzi);						//1			//A
bool czyKoniecRundy(int proby, int odpowiedzi, int bledy);						//1			//N
void tresciPytan();																//1			//S
void numerZadania(string* wtp, string* wsk);									//1			//Z
void szablon();																	//1			//A
void poleOdpowiedzi(string* ww, int odpowiedzi, string* wno);					//1			//
void prawidloweOdpowiedzi(string* wsk, int nrPyt);								//1			//
void koniecRundy();																//1			//
void final();																	//1				//F
string losowanieF();															//1				//I
void numerZadaniaF(string* wt, string* wp);										//1				//N
bool odpF(string odpowiedz, string* wp, int nrPyt);								//1				//A
void trF();																		//1				//L
void zakonczenie();																//1