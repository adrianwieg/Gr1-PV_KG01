#include <iostream>
#include <sstream>
using namespace std;

//Eigene Funktion zur Umwandlung eines Integer Werts in eine string variable
string IntToStr(int zahl) {
	ostringstream wandler;
	wandler << zahl;
	return wandler.str();
}

int main()
{
	//Definition der Variablen
	string Vorname;
	string Nachname;
	int Postleitzahl;
	string Wohnort;
	string Straﬂenname;
	int Hausnummer;
	string ausgabe;

	//Einlesen der Variablen
	cout << "Bitte geben Sie ihren Vornamen ein\n";
	cin >> Vorname;
	cout << "Bitte geben Sie ihren Nachnamen ein\n";
	cin >> Nachname;
	cout << "Bitte geben Sie ihre Postleitzahl ein\n";
	cin >> Postleitzahl;
	cout << "Bitte geben Sie ihren Wohnort ein\n";
	cin >> Wohnort;
	cout << "Bitte geben Sie ihren Stra" << "\xe1" << "ennamen ein\n";
	cin >> Straﬂenname;
	cout << "Bitte geben Sie ihre Hausnummer ein\n";
	cin >> Hausnummer;
	
	//Zusammensetzen der gesamten Adresse
	ausgabe = Vorname + " " + Nachname + "\n" +
		IntToStr(Postleitzahl) + " " + Wohnort + "\n" +
		Straﬂenname + " " + IntToStr(Hausnummer) + "\n";

	//Leeren der Konsole
	system("cls");

	//Ausgabe der Adresse
	cout << ausgabe;
}