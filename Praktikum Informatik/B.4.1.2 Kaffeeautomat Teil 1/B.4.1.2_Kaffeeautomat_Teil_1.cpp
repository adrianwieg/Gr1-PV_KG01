#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

//Main-Funktion
int main()
{
	//Variablendeklaration
	string produkt;

	//Struct definieren
	daten kaffee;

	//Auswahl
	bool auswahl_milch = false;
	bool auswahl_zucker = false;

	//Geld
	float preis_gesamt = 0;
	float geldeingabe = 0;
	float rueckgeld = 0;
	
	bool herunterfahren = false;

	while (herunterfahren != true)
	{	
		//Clearen des User Interfaces
		system("cls");

		bool bkaffee = false;
		bool bespresso = false;
		bool bmilch = false;
		bool bzucker = false;
		bool bservice = false;

		//Abfrage Herunterfahren ja/nein
		herunterfahren = UI(&bkaffee, &bmilch, &bzucker, &bespresso, &bservice, kaffee);
		
		//Preisberechnung wenn Kaffee oder Espresso ausgewählt wurde
		if (bkaffee or bespresso)
		{
			preis_gesamt = 0;
			preis_gesamt = preis_berechnen(bkaffee, bmilch, bzucker, bespresso, kaffee);
			geldeingabe = 0;
			rueckgeld = 0;

			cout << "Bitte " << preis_gesamt << " Euro eingeben und ENTER dr\x81 \bcken:\n";
			cin >> geldeingabe;
			if (geldeingabe >= preis_gesamt)
			{
				rueckgeld = geldeingabe - preis_gesamt;
			}
			else
			{
				cout << "Zu wenig Geld, Bestellung abgebrochen\n\a";
				system("sleep 5");
				continue;
			}

			//Aktualisieren der Mengen
			mengen_aktualisieren(bkaffee, bmilch, bzucker, bespresso, &kaffee);

			PRINTSTRING("Debug Mode aktiv. Folgende Mengen sind noch vorhanden:");
			PRINTVARIABLE(kaffee.kaffeebohnen);
			PRINTVARIABLE(kaffee.espressobohnen);
			PRINTVARIABLE(kaffee.wasser);
			PRINTVARIABLE(kaffee.zucker);
			PRINTVARIABLE(kaffee.milch);

			//Ausgabe Zubereitung
			cout << "Ihr Getr\x84nk wird zubereitet.....\n"
				"Bitte " << rueckgeld << " Euro R\x81""ckgeld und das Getr\x84nk entnehmen und eine Taste dr\x81""cken\n";
			system("pause");
		}
	}
		
	//Break der Konsolenanwendung
	system("pause");
	return 0;
}