#include "ko³a.h"
#include <iostream>

using namespace std;
Kola::Kola()
{
#ifdef _DEBUG
	cout << "Domyslny konstruktor kola"<<endl;
#endif 
	zuzycie = 7;
	powietrze_procent = 80;
}
Kola::Kola(const Kola &kola)
{
	powietrze_procent = kola.powietrze_procent;
	zuzycie = kola.zuzycie;
}
Kola::~Kola()
{
#ifdef _DEBUG
	cout << "Destruktor kola"<<endl;
#endif
}
void Kola::napompuj(int ile_procent)
{
	powietrze_procent += ile_procent;
	if (powietrze_procent > 100)
	{
		cout << "Maksimum powietrza, nie da sie bardziej napompowac"<<endl;
		powietrze_procent = 100;
	}
}
void Kola::zmien_kola()
{
	cout << "Kola wymienione" << endl;
	zuzycie = 0;
}
ostream & operator << (ostream & os, const Kola &k)
{
	os << k.powietrze_procent << " " << k.zuzycie << " ";
	return os;
}

istream & operator >> (istream & is, Kola &k)
{
	is >> k.powietrze_procent>> k.zuzycie;
	return is;
}