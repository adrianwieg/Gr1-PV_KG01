#include <iostream>
#include <string>	
using namespace std;
int main()
{
	double l;
	double laenge{ 100.05 };
	char zeichen;
	l = round(laenge); 
	//es wird eine double-Variable in eine int-Variable umgewandelt. Da int keine Nachkommastellen wie beim double versteht/ interpretieren kann, werden die Nachkommastellen gerundet und weggelassen.
	zeichen = laenge; 
	//es werden nur die ersten 8 Bit der double- Variable an "zeichen" �bergeben
	cout << laenge << " " << l << " " << zeichen << endl;
	string messlatte{ "777.77" };
	laenge = static_cast<double>(messlatte); 
	//Kann nicht mittels static_cast umgewandelt werden, da string kein verwandter Datentyp von double ist
}