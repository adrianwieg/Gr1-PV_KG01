//Stellt sicher, dass Header- Datei nur einmal genutzt wird
#pragma once

//nur wenn Test definiert wurde, tut das Makro etwas
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
bool user_login(char passwort[], int passwort_groesse);

//Funktion zum Service-Interface
void SI(daten kaffee);

//Funktion für die Zusätze
void UI_zusaetze_kaffee(bool beide, bool* pbmilch, bool* pbzucker);

//Funktion für das User-Interface
bool UI(bool* pbkaffee, bool* pbmilch, bool* pbzucker, bool* pbespresso, bool* pbservice, daten kaffee);

//Funktion zur Preisberechnung
float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee);

//Funktion zur Mengenaktualisierung
void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten* pkaffee);