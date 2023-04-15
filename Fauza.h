#ifndef Fauza_H
#define Fauza_H
#include <stdio.h>
#include <stdlib.h>
#include "Nisrina.h"
#define Info(P) (P)->info
#define Freq(P) (P)->freq
#define LeftSon(P) (P)->leftson
#define RightSon(P) (P)->rightson
#define Parent(P) (P)->parent
#define Prev(P) (P)->prev
#define Next(P) (P)->next

typedef struct NodeTree *Link;
typedef struct NodeTree {
	char info;
	int freq;
	Link leftson, rightson, parent;
} nodeTree;

typedef struct LeafRef *address1;
typedef struct LeafRef {
	address1 prev, next;
	Link info;
} leafref;


Link CreateNodeTree(char huruf, int freq);

address1 CreateLeafRef(Link leaf);

void InsLastLeaf (address1* head, address1* tail, address1 Q);

void InsFirstLeaf (address1* head, address1 Q);

void InsBetweenLeaf (address1* Pcur, address1 Q);

Link Pop (address1* tail);

address1 CreateListOfLeaf (address head);

Link CreateTree (address1 front);

#endif
