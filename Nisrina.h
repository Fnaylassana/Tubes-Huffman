#ifndef Nisrina_H
#define Nisrina_H

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


#endif
