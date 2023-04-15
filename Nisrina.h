#ifndef Nisrina_H
#define Nisrina_H

#include "Fauza.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define Nil NULL
#define Prev(P) (P)->prev
#define Info(P) (P)->info
#define Freq(P) (P)->freq
#define Next(P) (P)->next
#define infotype char*

typedef struct node *address;
struct node {

	char info;
	int freq;
	address prev;
	address next;
}Node;


address AlokasiChar(char X);

address Search (address front, char X);

void InsertLastChar (address *front, address *rear, address P);

void InsVLastChar(address *front, address *rear, char X);

void PrintInfoChar (address data);

void sortingFreq(address *front);

address createFrekuensi();

infotype InputCodeChar(infotype deskripsi);

void SearchTree(Link root, char x, Link *temp2);

infotype Incode(Link root, infotype KodeChar);


#endif
