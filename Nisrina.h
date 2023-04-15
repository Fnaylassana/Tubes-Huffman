#ifndef Nisrina_H
#define Nisrina_H

#include "header.h" 

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
