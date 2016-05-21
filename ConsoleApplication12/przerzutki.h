#pragma once
#include <string>

using namespace std;
///podklasa roweru
class Przerzutki
{
private:
	int bieg;///< okresla bieg, na ktory sa ustawione przerzutki
public:
	///procedura pozwalajaca na modyfikacje pola bieg
	/**
	\param nowa wartosc pola bieg
	\return nic nie zwraca*/
	void zmien_bieg(int nowy_bieg);
	///konstruktor
	Przerzutki();
	///konstruktor kopijacy
	Przerzutki(const Przerzutki &p);
	///destruktor
	~Przerzutki();
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const Przerzutki &p);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, Przerzutki &p);
};