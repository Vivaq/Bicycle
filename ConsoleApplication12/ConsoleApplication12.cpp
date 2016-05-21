#include "stdafx.h"
#include "rower.h"
#include "rower górski.h"
#include "rower dzieiciêcy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <vector>

#define TEST

using namespace std;
///funkcja pomocnicza pozwalajca ustawic kursor w odpowiednim miejscu na ekranie
/**
\param x okresla pozycje wertykalna
\param y okresla pozycje horyzontalna
\return nic nie zwraca
*/
void PrzesunKursor(int x, int y)
{
	COORD pozycja = { x, y };///< struktura przechowujaca x i y
	///ustawia pozycje kursora
	/**
	\param struktura przechowujaca pozycje kursora
	*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
}

///funkcja obrazujaca dzialanie operatora konwersji
void ZwrocCene(int cena)
{
	cout <<"Cena obiektu rower: "<< cena << endl;
}
///funkcja testujaca klasy
void TestKlas()
{
#ifdef TEST
	Rower r;
	RowerGorski rg;
	RowerDzieciecy rd;
	
	vector <Pojazd*> pojazdy;///<przechowuje pojazdy
	pojazdy.push_back(&r);
	pojazdy.push_back(&rg);
	pojazdy.push_back(&rd);
	
	pojazdy[0]->wypisz();

	string plik_nazwa1 = "plik dla gorskiego.txt"///<przechowuje nazwe pliku
		,plik_nazwa2 = "plik dla dzieciecego.txt";///<przechowuje nazwe pliku
	
	fstream plik1(plik_nazwa1);
	pojazdy[1]->ZapiszStan(plik1);
	rg.DolaczBidon();
	pojazdy[1]->wypisz();
	plik1.close();

	plik1.open(plik_nazwa1);
	pojazdy[1]->WczytajStan(plik1);
	pojazdy[1]->wypisz();
	plik1.close();

	fstream plik2(plik_nazwa2);
	pojazdy[2]->ZapiszStan(plik2);
	rd.OdczepKolka();
	pojazdy[2]->wypisz();
	plik2.close();

	plik2.open(plik_nazwa2);
	pojazdy[2]->WczytajStan(plik2);
	pojazdy[2]->wypisz();
	plik2.close();

	rd.zatrab();

	Kola ko;
	ko.napompuj(10);
	ko.zmien_kola();

	Przerzutki p;
	p.zmien_bieg(20);

	Kierownica kier;
	kier.skrec(PRAWO);
#endif 
}
///funkcja testujaca operatory
void operatory()
{
#ifdef TEST
	Rower rower("Kelly", "bialy",23,99,2000), rower1;

	cout << "Wypisuje obiekty na, ktorych bede operowac:" << endl;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator ==" << endl;
	if (rower1 == rower) { cout << "Rowne" << endl; }
	else { cout << "Inne" << endl; }

	cout << "Operator <" << endl;
	if (rower1 > rower) { cout << "Rower1 wiekszy od Rower" << endl; }
	else { cout << "Rower wiekszy od Rower1" << endl; }

	cout << "Operator >" << endl;
	if (rower>rower1) { cout << "Rower wiekszy od Rower1" << endl; }
	else { cout << "Rower1 wiekszy od Rower" << endl; }

	cout << "Operator +=" << endl;
	rower += rower1;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator -=" << endl;
	rower -= rower1;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator +" << endl;
	cout<<rower + rower1<<endl;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator ++" << endl;
	++rower;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator --";
	--rower;
	rower.wypisz();
	rower1.wypisz();

	cout << "Operator indeksowania []" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout<<rower[i]<<endl;
	}
	
	cout << "Operator konwersji" << endl;
	ZwrocCene(rower);

	cout << "Operator przypisania =" << endl;
	rower1 = rower;
	rower.wypisz();
	rower1.wypisz();
#endif
}
///funkcja odpowiadajaca za interfejs
int menu()
{
	char klawisz = 0;
	int opcja = 3;
	int min = 1, max = 3;
	PrzesunKursor(24, 7);
	cout << "Poruszanie za pomoca 'w' i 's'";
	PrzesunKursor(30, 9);
	cout << "Zatwierdz-Enter";
	PrzesunKursor(20, 10);
	cout << "Nacisnij Enter, aby przejsc dalej";
	while (_getch() != 13)
	{}
	while (1){

		system("cls");
		if (klawisz == 'w' && opcja != 3){
			opcja++;
		}
		else if (klawisz == 's' && opcja != 1){
			opcja--;
		}
		switch (opcja){
		
		case 1:
			PrzesunKursor(30, 9);
			cout << "Test operatorow" << endl;
			PrzesunKursor(30, 10);
			cout << "Test klas" << endl;
			PrzesunKursor(30, 11);
			cout << "Wyjdz *" << endl;
			if (klawisz == 13)
			{
				return 0;
			}
			break;
		case 2:
			PrzesunKursor(30, 9);
			cout << "Test operatorow" << endl;
			PrzesunKursor(30, 10);
			cout << "Test klas *" << endl;
			PrzesunKursor(30, 11);
			cout << "Wyjdz" << endl;
			if (klawisz == 13)
			{
				system("cls");
				TestKlas();
				cout <<endl<< "Enter-wyswietl ponownie" << endl << "Inny klawisz-wroc do menu" << endl;
			}
			break;
		case 3:
			PrzesunKursor(30, 9);
			cout << "Test operatorow *" << endl;
			PrzesunKursor(30, 10);
			cout << "Test klas" << endl;
			PrzesunKursor(30, 11);
			cout << "Wyjdz" << endl;
			if (klawisz == 13)
			{
				system("cls");
				operatory();
				cout << endl<<"Enter-wyswietl ponownie" << endl<<"Inny klawisz-wroc do menu"<<endl;
			}
			break;
		}
		klawisz = _getch();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
	Rower r;
	RowerGorski rg;
	RowerDzieciecy rd;

	Pojazd *pojazdy[3];
	pojazdy[0] = &r;
	pojazdy[1] = &rg;
	pojazdy[2] = &rd;

	
	for (int i = 0; i < 3; i++)
	{
		///Test funkcji wirtualnej:
		pojazdy[i]->PrzejedzSie();
	}
	cout << "Nacisnij Enter, aby przejsc dalej";
	_getch();
	system("cls");
	menu();

	///Testy z poprzedniego projektu
	Rower rower("Kross", "Czarny", 345, 92, 1500), rower1; 
	Rower * rower2;
	rower2 = new Rower;
	static Rower rower3;

	Rower rower4(rower);
	rower4.wypisz();

	cout <<"Utworzonych jest "<<Rower::liczba()<<" obiektow glownej klasy."<< endl;

	delete rower2;
#endif
	return 0;
}

