#include "przerzutki.h"
#include <iostream>

using namespace std;

Przerzutki::Przerzutki()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor przerzutek" << endl;
#endif 
	bieg = 15;
}
Przerzutki::Przerzutki(const Przerzutki &p)
{
#ifdef _DEBUG
	cout << "Kopiowanie obiektu" << endl;
#endif 
	bieg = p.bieg;
}
Przerzutki::~Przerzutki()
{
#ifdef _DEBUG
	cout << "Destruktor przerzutek" << endl;
#endif 
}
void Przerzutki::zmien_bieg(int nowy_bieg)
{
	bieg = nowy_bieg;
	cout << "Bieg zmieniony na " << bieg << endl;
}
ostream & operator << (ostream & os, const Przerzutki &p)
{
	os << p.bieg << " ";
	return os;
}

istream & operator >> (istream & is, Przerzutki &p)
{
	is >> p.bieg;
	return is;
}