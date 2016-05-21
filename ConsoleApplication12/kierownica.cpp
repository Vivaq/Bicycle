#include "kierownica.h"
#include <iostream>
#include <fstream>

using namespace std;

Kierownica::Kierownica()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor kierownicy" << endl;
#endif
	czy_jest_lampka = 0;
	kierunek = "prosto";
}
Kierownica::Kierownica(const Kierownica &k)
{
	czy_jest_lampka = k.czy_jest_lampka;
	kierunek = k.kierunek;
}
Kierownica::~Kierownica()
{
#ifdef _DEBUG
	cout << "Destruktor kierownicy" << endl;
#endif 
}

void Kierownica::skrec(int gdzie)
{
	switch (gdzie)
	{
		case 0:
			kierunek = "prosto";
		case 1:
			kierunek = "lewo";
		case 2:
			kierunek = "prawo";
	}
		
}
ostream & operator << (ostream & os, const Kierownica &k)
{
	os << k.czy_jest_lampka << " " << k.kierunek << " ";
	return os;
}

istream & operator >> (istream & is, Kierownica &k)
{
	is >> k.czy_jest_lampka>> k.kierunek;
	return is;
}
