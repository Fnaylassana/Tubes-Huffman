#include <stdio.h>
#include <stdlib.h>
#include "Fauza.h"
#include "Nisrina.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	address front, P;
	address1 leafref;
	Link root;
	infotype KodeChar;
	
	infotype KodeBinary;
	KodeBinary = (infotype)malloc(30*sizeof(char));
	
	front = Nil;
	KodeChar = Nil;
	
	front = createFrekuensi();
	sortingFreq(&front);
	PrintInfoChar (front);
	
	leafref = CreateListOfLeaf(front);
	
	root = CreateTree (leafref);
	
	printf ("%c %d", Info(root), Freq(root));
	
	KodeChar = InputCodeChar("input");
	printf("Test %s", KodeChar);
	
	
	KodeBinary = Incode(root, "AB");
	printf("tet %s", KodeBinary);
	
	return 0;
}
