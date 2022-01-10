#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Funktion für das User-Login Popup 
bool user_login(char passwort[], int passwort_groesse)
{
	char eingabe[6]{};								//Passwort-Eingabe des Nutzers
	bool passwort_korrekt = false;					//Passwort_Korrekt Variable auf false initialisieren
	cout << "Bitte geben Sie das Passwort ein:";	

	for (int i = 0; i < passwort_groesse-1; i++)	//Zählschleife für das zeichenweise Einlesen
	{
		eingabe[i] = _getch();
		cout << "*";
	}

	for (int i = 0; i < passwort_groesse-1; i++)	//Überprüfung ob das eingegebene Passwort korrekt ist
	{
		if (eingabe[i] == passwort[i])
		{
			passwort_korrekt = true;
		}
		else
		{
			passwort_korrekt = false;
			break;
		}
	}
	cout << "\n";									
	return passwort_korrekt;						//Rückgabewert
}

int main()
{
	//Variablendeklaration
	char eingabe;
	string produkt;

	//Passwort für den Service-Mode
	char service_passwort[] = "passwd";
	int passwort_groesse = sizeof(service_passwort) / sizeof(*service_passwort);
	
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
	const float preis_tasse	= 1.0f;
	const float preis_zusatz = 0.1f;
	float preis_gesamt = 0;
	float geldeingabe = 0;
	float rueckgeld = 0;

	//Auswahl
	bool auswahl_milch = false;
	bool auswahl_zucker = false;

	while (true)
	{	
		//Variablen auf 0/false setzen
		preis_gesamt = 0;
		geldeingabe = 0;
		rueckgeld = 0;
		auswahl_milch = false;
		auswahl_zucker = false;

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
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}
		cout << "\nSie haben sich f\x81r Auswahl " << produkt << " entschieden.\n\n";

		//Run für Nicht-Service-Mode
		if (eingabe != 's')
		{
			//Abfrage Zucker
			cout << "M""\x94""chten Sie Zucker (j/n)?\n";
			if (_getch() == 'j')
			{
				auswahl_zucker = true;
			}
			else if (_getch() == 'n')
			{
				auswahl_zucker = false;
			}
			else
			{
				cout << "Falsche Eingabe!\n";
				system("pause");
				continue;
			}

			//Abfrage Milch
			cout << "M""\x94""chten Sie Milch (j/n)?\n";
			if (_getch() == 'j')
			{
				auswahl_milch = true;
			}
			else if (_getch() == 'n')
			{
				auswahl_milch = false;
			}
			else
			{
				cout << "Falsche Eingabe!\n";
				system("pause");
				continue;
			}

			//Tassenpreis draufrechnen
			if (eingabe == 'k')
			{
				preis_gesamt += preis_tasse;
			}
			if (eingabe == 'e')
			{
				preis_gesamt += preis_tasse;
			}

			//Preis für Zusatz hinzufügen
			if (auswahl_milch == true)
			{
				preis_gesamt += preis_zusatz;
			}
			if (auswahl_zucker == true)
			{
				preis_gesamt += preis_zusatz;
			}

			//Preis ausgeben
			cout << "Bitte " << preis_gesamt << " Euro eingeben und ENTER dr""\x81""cken:\n";
			cin >> geldeingabe;
			if (geldeingabe >= preis_gesamt)
			{
				rueckgeld = geldeingabe - preis_gesamt;
			}
			else
			{
				cout << "Zu wenig Geld, Bestellung abgebrochen\n";
				system("pause");
				continue;
			}

			//Ausgabe Zubereitung
			cout << "Ihr Getr\x84nk wird zubereitet.....\n"
				"Bitte " << rueckgeld << " Euro R\x81""ckgeld und das Getr\x84nk entnehmen und eine Taste dr\x81""cken\n";
			system("pause");
		}

		//Vorratsberechnung
		if (eingabe == 'k')
		{
			kaffeebohnen -= 5;
			wasser -= 125;
		}
		if (eingabe == 'e')
		{
			espressobohnen -= 5;
			wasser -= 25;
		}
		if (auswahl_zucker == true)
		{
			zucker -= 3;
		}
		if (auswahl_milch == true)
		{
			milch -= 30;
		}

		//Ausgabe Service-Interface
		if (eingabe == 's')
		{
			if (user_login(service_passwort, passwort_groesse) == true)
			{
				cout << "Service-Interface\n"
					"----------------------------------------------------------------------\n"
					"Noch vorhandene Mengen:\n"
					"Kaffee: " << kaffeebohnen << "\t Milch: " << milch << "\n"
					"Espresso: " << espressobohnen << "\t Wasser: " << wasser << "\n"
					"Zucker: " << zucker << "\n"
					"----------------------------------------------------------------------\n"
					"Mengen pro Tasse:\n"
					"Kaffee: 5 g \t Milch: 30 ml\n"
					"Espresso: 5 g \t Wasser f\x81r Kaffee: 125 ml\n"
					"Zucker: 3 g \t Wasser f\x81r Espresso: 25 ml\n"
					"----------------------------------------------------------------------\n";
				system("pause");
			}
			else
			{
				cout << "Falsches Passwort! Zugang zum Service-Interface verweigert!\n";
				system("pause");
			}
		}
	}

	//Break der Konsolenanwendung
	system("pause");
	return 0;
}