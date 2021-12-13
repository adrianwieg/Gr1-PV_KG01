#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int main()
{
	//Variablendeklaration
	char eingabe;
	string produkt;
	
	//Vorratsvariablen
	unsigned int kaffeebohnen	= 1000;
	unsigned int espressobohnen = 1000;
	unsigned int wasser			= 5000;
	unsigned int milch			= 1000;
	unsigned int zucker			= 500;

	//benötigte Mengen
	const unsigned int ben_kaffeebohnen		= 5;
	const unsigned int ben_wasser_kaffee	= 125;
	const unsigned int ben_wasser_espresso	= 25;
	const unsigned int ben_milch			= 30;
	const unsigned int ben_zucker			= 3;

	//Preise
	const double preis_tasse	= 1.0;
	const double preis_zusatz	= 0.1;

	//Auswahl
	bool milch;
	bool zucker;

	while (true)
	{	
		//Clearen des User Interfaces
		system("cls");

		//Textausgabe
		cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Preis pro Tasse:\n"
			"Kaffee oder Espresso:  " << preis_tasse << " Euro\n"
			"Milch oder Zucker:     " << preis_zusatz << " Euro\n\n"
			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";

		//Einlesen der Auswahl
		eingabe = _getch();

		//Umwandlung der Auswahl- Buchstaben in einen String und Ausgabe
		switch (eingabe)
		{
		case 'k':
			produkt = "Kaffee";
			break;

		case 'e':
			produkt = "Espresso";
			break;

		case 's':
			produkt = "Service-Mode";
			break;

		default:
			break;
		}
		cout << "Sie haben sich f\x81r Auswahl " << produkt << " entschieden.\n";

		//Abfrage Zucker
		cout << "Möchten Sie Zucker (j/n)?";
		if (_getch() == 'j')
		{
			zucker = true;
		}
		else if (_getch() == 'n')
		{
			zucker = false;
		}
		else
		{
			cout << "Falsche Eingabe!\n";
		}

		//Abfrage Milch
		cout << "Möchten Sie Milch (j/n)?";
		if (_getch() == 'j')
		{
			milch = true;
		}
		else if (_getch() == 'n')
		{
			milch = false;
		}
		else
		{
			cout << "Falsche Eingabe!\n";
			continue;
		}
	}
	//Break der Konsolenanwendung
	system("pause");
	return 0;
}