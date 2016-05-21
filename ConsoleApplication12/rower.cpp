#include <iostream>
#include <Windows.h>
#include "rower.h"

using namespace std;

bool TorF=false;///< zmienna pomocnicza, flaga 
int Rower::liczba_obiektow = 0;

Rower::Rower()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor roweru" << endl;
#endif
	kierownica = NULL;
	model_roweru = "domyslny_model";
	kolor = "domyslny_kolor";
	nr_seryjny = 0;
	wysokosc = 50;
	cena_roweru = 100;
	liczba_obiektow++;
}

Rower::Rower(string model_roweru, string kolor, int nr_seryjny, int wysokosc, int cena_roweru)
{
#ifdef _DEBUG
	cout << "Konstruktor roweru posiadajcy parametry" << endl;
#endif
	kierownica = NULL;
	this->model_roweru = model_roweru;
	this->kolor = kolor;
	this->nr_seryjny = nr_seryjny;
	this->wysokosc = wysokosc;
	this->cena_roweru = cena_roweru;
	liczba_obiektow++;
}
Rower::Rower(const Rower &r)
{
#ifdef _DEBUG
	cout << "Kopiowanie obiektu" << endl;
#endif
	if (r.kierownica == NULL) {kierownica = NULL;}
	else 
	{
		kierownica = new Kierownica(*r.kierownica);
	}
	Kola kola(r.kola);
	Przerzutki przerzutki(r.przerzutki);
	model_roweru = r.model_roweru;
	kolor = r.kolor;
	wysokosc = r.wysokosc;
	nr_seryjny = r.nr_seryjny;
	cena_roweru = r.cena_roweru;
	liczba_obiektow++;
}
Rower::~Rower()
{
#ifdef _DEBUG
	cout << "Destruktor roweru" << endl;
#endif
	if (kierownica != NULL) { delete kierownica; }
	liczba_obiektow--;
}

void Rower::wypisz()
{
	cout << "Max predkosc: "<<max_predkosc<<"\tNaped: "<<rodzaj_napedu<< "\tModel: " << model_roweru << "\tKolor: " << kolor << "\tId: " << nr_seryjny<< "\tWys:"<<wysokosc<<"\tCena: "<<cena_roweru<<endl;
}
void Rower::PrzejedzSie()
{
	cout << "Wybrales sie na rowerowa wycieczke, bedzie trwac ok.3 sekund" << endl; 
	Sleep(3000);
}
bool Rower::operator == (Rower &r)
{
	if (nr_seryjny == r.nr_seryjny) { return true; }
	return false;
}	
bool Rower::operator<(Rower &r)
{
	if (wysokosc < r.wysokosc) { return true; }
	return false;
}

bool Rower::operator>(Rower &r)
{
	if (wysokosc > r.wysokosc) { return true; }
	return false;
}

Rower& Rower::operator+=(Rower &r)
{
	cena_roweru += r.cena_roweru;
	return *this;
}
Rower& Rower::operator-=(Rower &r)
{
	cena_roweru -= r.cena_roweru;
	return *this;
}
Rower Rower::operator+(Rower &r)
{
	Rower suma;
	suma.cena_roweru = r.cena_roweru + cena_roweru;
	return suma;
}

Rower& Rower::operator++()
{
	wysokosc ++;
	return *this;
}
Rower& Rower::operator--()
{
	wysokosc --;
	return *this;
}

int Rower::operator[](int a)
{
	if (a == 0) { return nr_seryjny; }
	if (a == 1) { return wysokosc; }
	if (a == 2) { return cena_roweru; }
	else {
		cout << "Przekroczono zakres ";
		return false;
	}
}

Rower& Rower::operator=(Rower &r)
{
	if (*this==r)
	{
		return *this;
	}
	if (kierownica != NULL) { delete kierownica; }
	if (r.kierownica == NULL) { kierownica = NULL; }
	else { *kierownica = *r.kierownica; }
	kola = r.kola;
	przerzutki = r.przerzutki;
	model_roweru = r.model_roweru;
	kolor = r.kolor;
	wysokosc = r.wysokosc;
	nr_seryjny = r.nr_seryjny;
	cena_roweru=r.cena_roweru;
	return *this;
}
ostream & operator << (ostream & os, const Rower &r)
{
	os << (Pojazd&)r<<endl;
	os << r.model_roweru << " " << r.kolor << " " << r.nr_seryjny << " " << r.wysokosc << " " << r.cena_roweru << endl;
	os << r.kola << endl;
	os << r.przerzutki << endl;
	if (r.kierownica != NULL)
	{
		TorF = true;
		os << *r.kierownica << endl;
	}
	return os;
}

istream & operator >> (istream & is, Rower &r)
{

	is >> (Pojazd&)r;
	is >> r.model_roweru>>r.kolor >> r.nr_seryjny>> r.wysokosc>> r.cena_roweru;
	is >> r.kola;
	is >> r.przerzutki;
	if (TorF==true)
		is >> *r.kierownica;
	return is;
}
void Rower::ZapiszStan(fstream &plik)
{
	plik << *this << endl;
}

void Rower::WczytajStan(fstream &plik)
{
	plik >> *this;
}