#include <iostream>
#include <string>
#include "pojazd.h"
#include <fstream>

using namespace std;
Pojazd::Pojazd()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor pojazdu, ktory nie moze sie wywolac" << endl;
#endif
	rodzaj_napedu = "mechaniczny";
	max_predkosc = 30;
}

Pojazd::~Pojazd()
{
#ifdef _DEBUG
	cout << "Domyslny destruktor pojazdu" << endl;
#endif
}
ostream & operator << (ostream & os, const Pojazd &p)
{
	os << p.max_predkosc << " " << p.rodzaj_napedu << " ";
	return os;
}

istream & operator >> (istream & is, Pojazd &p)
{
	is >> p.max_predkosc >> p.rodzaj_napedu;
	return is;
}

void Pojazd::ZapiszStan(fstream &plik)
{
	plik << *this << endl;
}

void Pojazd::WczytajStan(fstream &plik)
{
	plik >> *this;
}