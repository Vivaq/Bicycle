#pragma once
#include <string>

using namespace std;
/// pomocniczy typ wyliczeniowy dla kierunkow
enum Kierunek {PROSTO,LEWO,PRAWO};
///podklasa roweru
class Kierownica
{
private:
	bool czy_jest_lampka; ///<okresla czy jest lampka na kierownicy
	string kierunek; ///<okresla kierunek, w ktorym zwrocona jest kierownica
public:
	///procedura pozwalajaca modyfikowac pole kierunek
	/**Jako parametr przyjmuje nowy kierunek
	\param gdzie jest nowym kierunkiem
	\return nic nie zwraca*/
	void skrec(int gdzie);
	/// konstruktor
	Kierownica();
	///konstruktor kopiujacy
	Kierownica(const Kierownica &k);
	///destruktor
	~Kierownica();
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const Kierownica &k);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, Kierownica &k);
};