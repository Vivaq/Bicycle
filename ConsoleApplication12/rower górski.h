#pragma once
#include <vector>
#include "rower.h"

using namespace std;
///pochodna klasy rower
class RowerGorski : public Rower
{
private:
	int sila_amortyzatora;///< okresla jak silny jest amortyzator
	vector <string> gorskie_wypady;///< przechowuje miejsca w jakie udano sie z gorskim rowerem
	bool czy_jest_bidon;///< okresla czy rower gorski posiada bidon, dzieciecy z zalozenia nie moze miec bidona
public:
	/// konstruktor domyslny
	RowerGorski(void);
	/// destruktor
	~RowerGorski();
	/// procedura wypisujaca info o obiekcie
	void virtual wypisz();
	/// procedura pozwalajaca wybrac sie na przejazdzke :)
	void virtual PrzejedzSie();
	/// procedura modyfikujaca zmienna czy_jest_bidon 
	void DolaczBidon();
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const RowerGorski &r);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, RowerGorski &r);
	///procedura zapisujaca obiekt do pliku
	void virtual ZapiszStan(fstream &plik);
	///procedura wczytujaca obiekt z pliku
	void virtual WczytajStan(fstream &plik);
};