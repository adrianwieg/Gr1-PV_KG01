#include <iostream>
int main()
{
	int i, k, n;
	i = 101, k = 5, n = 10;
	while (i > 0) k = 2 * k; //Es handelt sich um eine Endlosschleife, da die Variable i unverändert bleibt. Es wird nur k unendlich oft verdoppelt. 

	i = 101, k = 5, n = 10;
	while (i != 0) i = i - 2; //Auch hier liegt eine Endlosschleife vor, da der Wert für i NIE genau 0 erreichen kann. I wird nur 1 bzw -1 oder kleiner. Damit wird die Schleife bis ins unendliche fortgesetzt

	i = 101, k = 5, n = 10;
	while (n != i) //Auch hier liegt eine Endlosschleife vor, da n immer doppelt so groß wie i ist. Somit ist n IMMER ungleich i.
	{
		++i;
		n = 2 * i;	}}