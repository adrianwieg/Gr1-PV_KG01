#include<iostream>
using namespace std;
int main()
{
	int a = 2; //Initialisierung von a auf 2 (a=2)
	int b = 1; //Initialisierung von b auf 1 (b=1)
	a = b = 2; // b wird der Wert 2 zugewiesen und dann wird a der Wert von b zugewiesen (a=2; b=2)
	a = 5 * 3 + 2; //(a=17; b=2)
	a = 5 * (3 + 2); //(a=25; b=2)
	a *= 5 + 5; //lang: a= a*(5+5) (a=250; b=2)
	a %= 2 * 3; //lang: a= a % 2*3 (a=4; b=2)
	a = !(--b == 0); //--b == 0 ergibt false, also 0. Die Negation von 0 (im bool) ist 1 --> (a=1; b=1)
	a = 0 && 0 + 2; //Addition vor boolschen Operatoren; im Entdefekt steht hier 0 && 2 was ja 0 ist, da es dies normal nicht in der Schaltbelegungstabelle gibt (a=0; b=1)
	a = b++ * 2; //lang: (b(ist aktuell noch 1)*2); danach erst b=b+1 (a=2; b=2)
	a = -5 - 5; //(a=-10; b=2)
	a = -(+b++); //lang: b negieren und danach um eins inkrementieren (a=-2; b=3) 
	a = 5 == 5 && 0 || 1; //Schritt 1: 1 && 0 || 1; Schritt 2: 0 || 1; Schritt 3: a=1 (a=1; b=3)(Schritte folgen aus der Priorität der Boolschen Operatoren)
	a = ((((((b + b) * 2) + b) && b || b)) == b); //Schritt 1: ((((6*2)+b && b || b)) == b); Schritt 2: ((15 && b || b ) == b); Schritt 3: ((1 || 3) == 3); Schritt 4: (1 == 3)-->stimmt nicht-->(a=0; b=3)
	a = b + ++b; //lang: (b+1) + (b+1) (a=8; b=4)
	a = sizeof(int) * sizeof(a); //lang: 4*4 (weil es 2 int Variablen sind) (a=16; b=4)
	return 0;
}