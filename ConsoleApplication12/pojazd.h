#pragma once

using namespace std;
///klasa abstrakcyjna, sluzy tylko do dziedizczenia
class Pojazd
{
protected:
	string rodzaj_napedu;///<okresla typ napedu pojazdu
	int max_predkosc;///<okresla max predkosc jak moze osiagnac pojazd
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const Pojazd &p);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, Pojazd &p);
public:
	///funkcja wirtualna, tylko do dziedziczenia
	void virtual PrzejedzSie() = 0;
	///funkcja wirtualna, tylko do dziedziczenia
	void virtual wypisz() = 0;
	///konstruktor
	Pojazd();
	///wirtualny destruktor
	virtual ~Pojazd();
	///wirtualna procedura zapisujaca do pliku, do dziedziczenia
	void virtual ZapiszStan(fstream &plik);
	///wirtualna procedura wczytujaca z pliku, do dziedziczenia
	void virtual WczytajStan(fstream &plik);
};