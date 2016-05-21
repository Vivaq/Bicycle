#include <iostream>
#include <Windows.h>
#include <iostream>
#include "rower dzieiciêcy.h"

using namespace std;
RowerDzieciecy::RowerDzieciecy()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor roweru dla dzieci" << endl;
#endif
	ile_bocznych_kolek = 2;
	glosnosc_dzwonka = 2;
}

RowerDzieciecy::~RowerDzieciecy()
{
#ifdef _DEBUG
	cout << "Destruktor roweru dla dzieci" << endl;
#endif
}

void RowerDzieciecy::wypisz()
{
	cout << "Max predkosc: " << max_predkosc << "\tNaped: " << rodzaj_napedu <<"\tModel: " << model_roweru << "\tKolor: " << kolor << "\tId: " << nr_seryjny << "\tWys:" << wysokosc << "\tCena: " << cena_roweru << "\tIlosc bocznych kolek: " << ile_bocznych_kolek << "\tGlosnosc dzwonka: " << glosnosc_dzwonka << endl;
}


void RowerDzieciecy::zatrab()
{
	int ile;
	cout << "Ile razy mam zatrabic?";
	cin >> ile;
	for (int i = 0; i < ile; i++)
		Beep(500*glosnosc_dzwonka, 500);
}

void RowerDzieciecy::OdczepKolka()
{
	if (ile_bocznych_kolek == 0)
	{
		cout << "Nie ma bocznych kolek" << endl;
	}
	else
	{
		ile_bocznych_kolek = 0;
		cout << "Kolka odczepione" << endl;
	}
}

void RowerDzieciecy::PrzejedzSie()
{
	cout << "Wybrales sie na wycieczke z dzieckiem, bedzie trwac ok. 1 sekund" << endl;
	Sleep(1000);
}

ostream & operator << (ostream & os, const RowerDzieciecy &r)
{
	os << (Rower&)r;
	os << r.ile_bocznych_kolek << " " << r.glosnosc_dzwonka << " ";
	return os;
}

istream & operator >> (istream & is, RowerDzieciecy &r)
{
	is >> (Rower&)r;
	is >> r.ile_bocznych_kolek>> r.glosnosc_dzwonka;
	return is;
}

void RowerDzieciecy::ZapiszStan(fstream &plik)
{
	plik << *this << endl;
}

void RowerDzieciecy::WczytajStan(fstream &plik)
{
	plik >> *this;
}