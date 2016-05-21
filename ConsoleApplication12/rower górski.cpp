#include <Windows.h>
#include <iostream>
#include"rower górski.h"

using namespace std;
RowerGorski::RowerGorski()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor roweru gorskiego" << endl;
#endif
	sila_amortyzatora = 5;
	gorskie_wypady.push_back("Tatry");
	czy_jest_bidon = 0;
}

RowerGorski::~RowerGorski()
{
#ifdef _DEBUG
	cout << "Destruktor roweru gorskiego" << endl;
#endif
}

void RowerGorski::wypisz()
{
	cout << "Max predkosc: " << max_predkosc << "\tNaped: " << rodzaj_napedu << "\tModel: " << model_roweru << "\tKolor: " << kolor << "\tId: " << nr_seryjny << "\tWys:" << wysokosc << "\tCena: " << cena_roweru << "\tSila amortyzatora: " << sila_amortyzatora << "\tGorskie wypady: ";
	int ile = gorskie_wypady.size();
	for (int i = 0; i < ile; i++)
	{
		cout<<gorskie_wypady[i]<<" ";
	}
	if (czy_jest_bidon == 0)
		cout << "\tNie ma bidona" << endl;
	if (czy_jest_bidon == 1)
		cout << "\tJest bidon" << endl;
}

void RowerGorski::DolaczBidon()
{
	if (czy_jest_bidon == 1)
		cout << "Bidon jus jest"<<endl;
	else
	{
		czy_jest_bidon = 1;
		cout << "Dolaczono bidon" << endl;
	}
}

void RowerGorski::PrzejedzSie()
{
	cout << "Wybrales sie na gorska rowerowa wycieczke, bedzie trwac ok. 5 sekund" << endl;
	Sleep(5000);
}

ostream & operator << (ostream & os, const RowerGorski &r)
{
	os << (Rower&)r;
	os << r.sila_amortyzatora << " ";
	int ile = r.gorskie_wypady.size();
	for (int i = 0; i < ile; i++)
		os << r.gorskie_wypady[i] << " ";
	os << r.czy_jest_bidon << " ";
	return os;
}

istream & operator >> (istream & is, RowerGorski &r)
{
	is >> (Rower&)r;
	is >> r.sila_amortyzatora;
	cout << "Ile gorskich wypadow? [Domyslnie 1]" << endl;
	int ile;
	cin >> ile;
	for (int i = 0; i < ile; i++)
	{
		r.gorskie_wypady.push_back("");
		is >> r.gorskie_wypady[i];
	}
	is >> r.czy_jest_bidon;
	return is;
}
void RowerGorski::ZapiszStan(fstream &plik)
{
	plik << *this << endl;
}

void RowerGorski::WczytajStan(fstream &plik)
{
	plik >> *this;
}