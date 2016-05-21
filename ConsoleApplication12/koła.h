#pragma once
#include <string>

using namespace std;

///podklasa roweru
class Kola
{
private:
	int powietrze_procent;///<okresla procentowa ilosc powietrza w kolach
	int zuzycie;///<okresla stopien zuzycia kol
public:
	///konstruktor
	Kola();
	///konstruktor kopiujacy
	Kola(const Kola &kola);
	///destruktor
	~Kola();
	///procedura modyfikujaca pole powietrze_procent
	/**
	\param parametr ile_procent jest iloscia punktow procentowych, o ktore zwiekszamy ilosc powietrza w kolach
	\return nic nie zwraca*/
	void napompuj(int ile_procent);
	///procedura zerujaca pole zuzycie
	void zmien_kola();
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const Kola &k);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, Kola &k);
};