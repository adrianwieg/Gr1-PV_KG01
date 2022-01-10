#include <iostream>
#include <array>
using namespace std;

//Funktion zur Ermitlung des Mittelwerts
float ermittle_mittelwert(float werte[], int groesse)
{
	float summe = 0;					//Summe auf 0 initialisieren
	float mittelwert = 0;				//Mittelwert auf 0 initialisieren

	for (int i = 0; i < groesse; i++)	//Berechnung der Summe aller Messwerte
	{
		summe += werte[i];
	}
	mittelwert = summe / groesse;		//Berechnung des Mittelwerts
	return mittelwert;					//Rückgabewert
}

//Funktion zur Ermittlung der Varianz
float ermittle_varianz(float werte[], int groesse)
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
}

//Zeilenweise Ausgabe des Arrays
void ausgabe_array(float werte[], int groesse)
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
	float messwerte[]{99.975, 100.002, 99.999, 99.982,100.100, 100.009, 99.826, 100.547, 100.023, 100.008};
	int groesse = sizeof(messwerte) / sizeof(*messwerte);

	ausgabe_array(messwerte, groesse);
	cout << endl;
	cout << "Mittelwert = " << ermittle_mittelwert(messwerte, groesse) << "m Varianz = " << ermittle_varianz(messwerte, groesse) << " quadratmeter" << endl;
}