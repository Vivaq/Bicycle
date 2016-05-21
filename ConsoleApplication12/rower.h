#pragma once
#include <fstream>
#include "ko³a.h"
#include "przerzutki.h"
#include "kierownica.h"
#include "pojazd.h"

using namespace std;
///Glowna klasa
class Rower : public Pojazd
{
private:
	static int liczba_obiektow; ///< okresla ile obiektow istnieje
protected:
	int wysokosc; ///<okresla wysokosc roweru
	string model_roweru; ///<okresla nazwe modelu roweru
	string kolor; ///<okresla kolor roweru
	int nr_seryjny; ///<unikatowy numer seryjny roweru
	int cena_roweru;///<okresla cene roweru
	Kola kola;///<podobiekt
	Kierownica *kierownica;///<dynamiczny podobiekt
	Przerzutki przerzutki;///<podobiekt
public:
	///konstruktor domyslny
	Rower(void);
	/// konstruktor przyjmujacy parametry
	Rower(string model_roweru, string kolor, int nr_seryjny, int wysokosc, int cena_roweru=100);
	///konstruktor kopiujacy
	Rower(const Rower &r);
	///destruktor
	~Rower();
	/// statyczna funkcja zwracajaca ilosc istniejacych obiektow
	static int liczba() {return liczba_obiektow;}
	/// procedura wypisujaca informacje o obiekcie
	void virtual wypisz();
	/// procedura pozwalajaca wybrac sie na przejazdzke :)
	void virtual PrzejedzSie();
	///operator ==
	bool operator==(Rower &r);
	///operator <
	bool operator<(Rower &r);
	///operator >
	bool operator>(Rower &r);
	///operator+=
	Rower& operator+=(Rower &r);
	///operator-=
	Rower& operator-=(Rower &r);
	///operator +
	Rower operator+(Rower &r);
	///operator ++
	Rower& operator++();
	///operator --
	Rower& operator--();
	///operator indeksowania
	int operator[](int a);
	///operator konwersji
	operator int() { return cena_roweru; }
	/// operator przypisania
	Rower& operator=(Rower &r); //Aby uniemosliwic wywolanie operatora przypisania nalesy jego definicje umiescic w sekcji private
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const Rower &r);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, Rower &r);
	///procedura zapisujaca do pliku
	void virtual ZapiszStan(fstream &plik);
	///procedura wczytujaca z pliku
	void virtual WczytajStan(fstream &plik);
};