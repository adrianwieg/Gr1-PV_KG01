#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

bool berechne_kugeldaten (float radius, double* oberflaeche, double* volumen)	//Funktion zur Berechnung von Oberfl�che und Volumen
{																				//sowie �berpr�fung ob Radius gr��er 0 ist
	if (radius > 0)																//�berpr�fung ob Radius positiv ist
	{
		*oberflaeche = 4 * M_PI * pow(radius, 2);								//Berechnung der Oberfl�che
		*volumen = 4 * M_PI * pow(radius, 3) / 3;								//Berechnung des Volumens
		return true;															//R�ckgabewert
	}
	else
	{
		return false;															//R�ckgabe false wenn Radius negativ ist
	}
}

int main()
{
	double oberflaeche = 0;
	double volumen = 0;
	float radius = 5;

	bool success = berechne_kugeldaten(radius, &oberflaeche, &volumen);			//Funktionsaufruf

	if (success)																//Ausgabe der Daten wenn der Radius positiv ist
	{
		cout << "Radius: " << radius << endl;
		cout << "Oberfl\x84 \bche: " << oberflaeche << endl;
		cout << "Volumen: " << volumen << endl;

	}
	else
	{
		cout << "Bitte Eingabe \x81 \bberpr\x81 \bfen! Radius ist negativ!\n";	//Ausgabe einer Fehlermeldung wenn Radius negativ ist
	}
}