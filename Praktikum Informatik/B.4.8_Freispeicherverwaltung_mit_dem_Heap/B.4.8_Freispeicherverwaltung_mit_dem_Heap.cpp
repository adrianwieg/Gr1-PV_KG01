#include <iostream>
#include <array>
using namespace std;

//Funktion zur Ermitlung des Mittelwerts
/*float ermittle_mittelwert(float werte[], int groesse)
{
	float summe = 0;					//Summe auf 0 initialisieren
	float mittelwert = 0;				//Mittelwert auf 0 initialisieren

	for (int i = 0; i < groesse; i++)	//Berechnung der Summe aller Messwerte
	{
		summe += werte[i];
	}
	mittelwert = summe / groesse;		//Berechnung des Mittelwerts
	return mittelwert;					//Rückgabewert
}*/

//Funktion zur Ermittlung der Varianz
/*float ermittle_varianz(float werte[], int groesse)
{
	float mittelwert = ermittle_mittelwert(werte, groesse);	//Berechnung des Mittelwerts
	float zwischensumme = 0;			//Zwischensumme auf 0 initialisieren
	float varianz = 0;					//Varianz auf 0 initialisieren

	for (int i = 0; i < groesse; i++)	//Berechnung des Quadrates aus der Differenz des jeweiligen Messwertes und des Mittelwerts
	{
		zwischensumme += pow(werte[i] - mittelwert, 2);
	}
	varianz = zwischensumme / (groesse - 1);
	return varianz;						//Rückgabewert
}*/

void berechne_mittelwert_varianz(double* werte, int groesse, double* mittelwert, double* varianz)
{
	double summe = 0;

	for (int i = 0; i < groesse; i++)	//Berechnung der Summe aller Messwerte
	{
		summe += werte[i];
	}

	*mittelwert = summe / groesse;		//Berechnung des Mittelwerts

	double zwischensumme = 0;
	for (int i = 0; i < groesse; i++)	//Berechnung des Quadrates aus der Differenz des jeweiligen Messwertes und des Mittelwerts
	{
		zwischensumme += pow(werte[i] - *mittelwert, 2);
	}
	*varianz = zwischensumme / ((double)groesse - 1);
}

//Zeilenweise Ausgabe des Arrays
void ausgabe_array(double *werte, int groesse)
{
	cout << "Messwerte [m] \n";			//Ausgabe der Überschrift
	cout << "-----------------\n";		//Ausgabe der Trennzeile

	for (int i = 0; i < groesse; i++)
	{
		cout << werte[i] << endl;
	}
}

//Hauptprogramm
int main()
{
	int groesse = 0;

	//Einlesen, wie viele Messwerte eingegeben werden
	cout << "Wie viele Messwerte?\n";
	cin >> groesse;

	double* messwerte;
	messwerte = new double[groesse];

	//Zählschleife zum Einlesen der Messwerte
	for (int i = 0; groesse > i; i++)
	{
		cout << "Messwert " << i+1 << ": \n";
		cin >> messwerte[i];
	}

	//Zusatzaufgabe: Ja das ist möglich. Dies sieht man ja in Zeile 74 und 75. Wir erstellen ein leeres Array, welches während der Laufzeit gefüllt wird. 
	//Somit kann die Frage mit Ja beantwortet werden. 
	//Oben geschriebene Funktion zur Berechnung des Mittelwerts und der Varianz
	double mittelwert = 0;
	double varianz = 0;
	berechne_mittelwert_varianz(messwerte, groesse, &mittelwert, &varianz);

	//Aushabe der Messwerte
	ausgabe_array(messwerte, groesse);
	cout << endl;
	//Ausgabe der berechneten Werte
	cout << "Mittelwert = " << mittelwert << "m Varianz = " << varianz << " quadratmeter" << endl;

	return 0;
}