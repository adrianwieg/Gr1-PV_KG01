#include <iostream>
using namespace std;
int main()
{
	char auswahl;
	system("cls");
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n" 
		    "Bitte w\x84hlen Sie aus:\n" 
		    "(k) Kaffee\n" 
		    "(e) Espresso\n" 
		    "(s) Service-Mode\n";
	cin >> auswahl;
	cout << "Sie haben sich f\x81r Auswahl " << auswahl << " entschieden." << endl;
	system("pause");
	return 0;
}