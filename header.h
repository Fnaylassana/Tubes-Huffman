#ifndef header_H
#define header_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define Nil NULL
#define Info(P) (P)->info
#define Freq(P) (P)->freq
#define LeftSon(P) (P)->leftson
#define RightSon(P) (P)->rightson
#define Parent(P) (P)->parent
#define Prev(P) (P)->prev
#define Next(P) (P)->next
#define infotype char*

typedef struct node *address;
struct node {

	char info;
	int freq;
	address prev;
	address next;
}Node;

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

#endif
