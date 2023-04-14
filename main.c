#include <stdio.h>
#include <stdlib.h>
#include "Fauza.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	address front, rear, P;
	address1 leafref;
	Link root;
	int i = 0;
	
	rear = NULL;
	front = NULL;
	
	while (i<=5){
		P = (address) malloc (sizeof(frekuensi));
		
		Info(P) = 65+i;
		Freq(P) = 367-i*25;
		Prev(P) = NULL;
		Next(P) = NULL;
		
		if (i == 0){
			front = P;
		} else {
			Prev(P) = rear;
			Next(rear) = P;
		}
		
		rear = P;
		i++;
	}
	
	leafref = CreateListOfLeaf(front);
	
	root = CreateTree (leafref);
	
	printf ("%c %d", Info(root), Freq(root));
	
	return 0;
}
