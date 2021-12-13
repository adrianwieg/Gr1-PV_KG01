#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	//Variablendeklaration
	char auswahl;

	//Clearen des User Interfaces
	system("cls");

	//Textausgabe
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n" 
		    "Bitte w\x84hlen Sie aus:\n" 
		    "(k) Kaffee\n" 
		    "(e) Espresso\n" 
		    "(s) Service-Mode\n";

	//Einlesen der Auswahl
	auswahl = _getch();

	//Umwandlung der Auswahl- Buchstaben in einen String und Ausgabe
	switch (auswahl)
	{
	case 'k':
		cout << "Sie haben sich f\x81r Auswahl Kaffee entschieden.\n";
		break;

	case 'e':
		cout << "Sie haben sich f\x81r Auswahl Espresso entschieden.\n";
		break;

	case 's':
		cout << "Sie haben sich f\x81r Auswahl Service-Mode entschieden.\n";
		break;

	default:
		break;
	}

	//Break der Konsolenanwendung
	system("pause");
	return 0;
}