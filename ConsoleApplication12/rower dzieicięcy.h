#pragma once
#include"rower.h"

using namespace std;
///pochodna klasy rower
class RowerDzieciecy : public Rower
{
private:
	int ile_bocznych_kolek;///<okresla ile dodatkowych kolek posiada rower
	int glosnosc_dzwonka;///<okresla jak glosna jest trabka fabrycznie zamocowana w rowerze
public:
	///konstruktor domyslny
	RowerDzieciecy(void);
	///destruktor
	~RowerDzieciecy();
	/// procedura wypisujaca info o obiekcie
	void virtual wypisz();
	/// procedura pozwalajaca wybrac sie na przejazdzke :)
	void virtual PrzejedzSie();
	///procedura wydajaca systemowy dzwiek
	void zatrab();
	///procedura modyfikujaca pole ile_bocznych_kolek
	void OdczepKolka();
	///operator strumieniowy <<
	friend ostream & operator << (ostream &os, const RowerDzieciecy &r);
	///operator strumieniowy >>
	friend istream & operator >> (istream &is, RowerDzieciecy &r);
	///procedura zapisujaca obiekt do pliku
	void virtual ZapiszStan(fstream &plik);
	///procedura wczytujaca obiekt z pliku
	void virtual WczytajStan(fstream &plik);
};