#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

//nur wenn Test definiert wurde, tut das Makro etwas
#define TEST
#ifdef TEST
#define TESTAUSGABE(x) x												//Führt einen beliebigen Testcommand aus
#define PRINTVARIABLE(x) cout << endl << (#x) << "=" << (x) << endl		//Gibt die Variable aus
#define PRINTSTRING(x) cout << endl << x << endl						//Gibt den String aus
#else
#define TESTAUSGABE(x)		//Macht nichts
#define PRINTVARIABLE(x)	//Macht nichts
#define PRINTSTRING(x)		//Macht nichts
#endif


//Definition Struct
struct daten
{
	//Vorratsvariablen
	unsigned int kaffeebohnen = 1000;
	unsigned int espressobohnen = 1000;
	unsigned int wasser = 5000;
	unsigned int milch = 1000;
	unsigned int zucker = 500;

	//benötigte Mengen
	const unsigned int ben_kaffeebohnen = 5;
	const unsigned int ben_wasser_kaffee = 125;
	const unsigned int ben_wasser_espresso = 25;
	const unsigned int ben_milch = 30;
	const unsigned int ben_zucker = 3;

	//Preise
	const float preis_tasse = 1.0f;
	const float preis_zusatz = 0.1f;

};

//Funktion für das User-Login Popup 
bool user_login(char passwort[], int passwort_groesse)
{
	char eingabe[6]{};								//Passwort-Eingabe des Nutzers
	bool passwort_korrekt = false;					//Passwort_Korrekt Variable auf false initialisieren
	cout << "Bitte geben Sie das Passwort ein:";

	PRINTSTRING("Debug Mode aktiv. Das ist das Passwort:");
	PRINTVARIABLE(passwort);

	for (int i = 0; i < passwort_groesse - 1; i++)	//Zählschleife für das zeichenweise Einlesen
	{
		eingabe[i] = _getch();
		cout << "*";
	}

	for (int i = 0; i < passwort_groesse - 1; i++)	//Überprüfung ob das eingegebene Passwort korrekt ist
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

//Funktion zum Service-Interface
void SI(daten kaffee)
{
	//Passwort für den Service-Mode
	char service_passwort[] = "passwd";
	int passwort_groesse = sizeof(service_passwort) / sizeof(*service_passwort);

	//Service Interface
	if (user_login(service_passwort, passwort_groesse))
	{
		cout << "Service-Interface\n"
			"----------------------------------------------------------------------\n"
			"Noch vorhandene Mengen:\n"
			"Kaffee: " << kaffee.kaffeebohnen << "\t Milch: " << kaffee.milch << "\n"
			"Espresso: " << kaffee.espressobohnen << "\t Wasser: " << kaffee.wasser << "\n"
			"Zucker: " << kaffee.zucker << "\n"
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
		cout << "Falsches Passwort! Zugang zum Service-Interface verweigert!\n\a";
		system("sleep 5");
	}
}

//Funktion für die Zusätze
void UI_zusaetze_kaffee(bool beide, bool* pbmilch, bool* pbzucker)
{
	//Abfrage Zucker
	while (true)
	{
		cout << "M""\x94""chten Sie Zucker (j/n)?\n";
		if (_getch() == 'j')
		{
			*pbzucker = true;
			break;
		}
		else if (_getch() == 'n')
		{
			*pbzucker = false;
			break;
		}
		else
		{
			cout << "Falsche Eingabe!\n\a";
			system("pause");
			continue;
		}
	}

	//Abfrage Milch
	if (beide)
	{
		while (true)
		{
			cout << "M""\x94""chten Sie Milch (j/n)?\n";
			if (_getch() == 'j')
			{
				*pbmilch = true;
				break;
			}
			else if (_getch() == 'n')
			{
				*pbmilch = false;
				break;
			}
			else
			{
				cout << "Falsche Eingabe!\n\a";
				system("pause");
				continue;
			}
		}
	}
}

//Funktion für das User-Interface
bool UI(bool* pbkaffee, bool* pbmilch, bool* pbzucker, bool* pbespresso, bool* pbservice, daten kaffee)
{
	//Variablendeklaration
	char eingabe;

	//Textausgabe
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
		"Preis pro Tasse:\n"
		"Kaffee oder Espresso:  " << kaffee.preis_tasse << " Euro\n"
		"Milch oder Zucker:     " << kaffee.preis_zusatz << " Euro\n\n"
		"Bitte w\x84hlen Sie aus:\n"
		"(k) Kaffee\n"
		"(e) Espresso\n"
		"(s) Service-Mode\n"
		"(h) Herunterfahren\n";

	//Einlesen der Auswahl
	eingabe = _getch();

	//Umwandlung der Auswahl- Buchstaben in einen boolean
	switch (eingabe)
	{
	case 'k':
		*pbkaffee = true;
		cout << "\nSie haben sich f\x81r Auswahl Kaffee entschieden.\n\n";
		UI_zusaetze_kaffee(true, pbmilch, pbzucker);
		return false;
		break;

	case 'e':
		*pbespresso = true;
		cout << "\nSie haben sich f\x81r Auswahl Espresso entschieden.\n\n";
		UI_zusaetze_kaffee(false, pbmilch, pbzucker);
		return false;
		break;

	case 's':
		*pbservice = true;
		cout << "\nSie haben sich f\x81r Auswahl Service-Mode entschieden.\n\n";
		SI(kaffee);
		return false;
		break;

	case 'h':
		return true;

	default:
		cout << "\n\nBitte Eingabe pr\x81 \bfen!\n\a";
		system("timeout 5");
		return false;
	}
}

//Funktion zur Preisberechnung
float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee)
{
	float preis = 0;
	//Tassenpreis draufrechnen
	if (bkaffee)
	{
		preis += kaffee.preis_tasse;
	}
	if (bespresso)
	{
		preis += kaffee.preis_tasse;
	}

	//Preis für Zusatz hinzufügen
	if (bmilch)
	{
		preis += kaffee.preis_zusatz;
	}
	if (bzucker)
	{
		preis += kaffee.preis_zusatz;
	}
	return preis;
}

//Funktion zur Aktualisierung der Vorratsvariablen
void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten* pkaffee)
{
	//Auswahl Kaffee
	if (bkaffee)
	{
		pkaffee->kaffeebohnen -= pkaffee->ben_kaffeebohnen;
		pkaffee->wasser -= pkaffee->ben_wasser_kaffee;
	}
	//Auswahl Espresso
	if (bespresso)
	{
		pkaffee->espressobohnen -= pkaffee->espressobohnen;
		pkaffee->wasser -= pkaffee->ben_wasser_espresso;
	}
	//Auswahl mit Zucker
	if (bzucker)
	{
		pkaffee->zucker -= pkaffee->ben_zucker;
	}
	//Auswahl mit Milch
	if (bmilch)
	{
		pkaffee->milch -= pkaffee->ben_milch;
	}
}
