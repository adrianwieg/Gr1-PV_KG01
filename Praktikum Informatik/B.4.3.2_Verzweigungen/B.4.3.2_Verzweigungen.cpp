#include<iostream>
using namespace std;
int main()
{
	int i, j;

	i = 0; j = -5;
	if (i++ || j++) ++i; 
	//Das logische Oder prüft ob eine Variable (i oder j) nicht 0 ist. Da i 0 IST, ist der erste Teil false, i wird um 1 erhöht und es wird mit dem 2. Teil der if Anweisung weiter gemacht (j+1). Dieser Teil ist true. Deshalb wird mit dem Anweisungsblock (++i) fortgesetzt.
	//Ergebnis: i=2,j=-4
	cout << i << ',' << j << endl;
	
	i = 1; j = -5;
	if (i++ || j++) ++i; 
	//Das logische Oder prüft erneut ob eine Variable ungleich 0 ist. Dies ist nicht der Fall --> I wird um 1 erhöht, J jedoch nicht, da der erste Teil true ist. Das ++i wird jedoch dennoch ausgeführt, da eine Bedingung true ist.
	//Ergebnis: i=3,j=-5
	cout << i << ',' << j << endl;

	i = 0; j = -5;
	if (i++ && j++) ++i; 
	//Das logische Und prüft ob beide Variablen ungleich 0 sind. Der erste Teil (i++) ist false. Daher wird i um 1 erhöht, j++ jedoch nicht angefasst, da das Ergebnis schon feststeht. Auch das ++i wird nicht ausgeführt, da eine Bedingungen nicht true ist (i++). 
	//Ergebnis: i=1,j=-5
	cout << i << ',' << j << endl;

	i = 1; j = -5;
	if (i++ && j++) ++i; 
	//Das logische Und prüft ob beide Variablen ungleich 0 sind. I ist ungleich 0 (i=1) und j ebenfalls (j=-5). Daher sind beide Bedingungen true und die Anweisung ++i wird ebenfalls ausgeführt.
	//Ergebnis: i=3,j=-4	cout << i << ',' << j << endl; }