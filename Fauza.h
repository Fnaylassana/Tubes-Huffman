#ifndef Fauza_H
#define Fauza_H

#include "header.h"

Link CreateNodeTree(char huruf, int freq);

address1 CreateLeafRef(Link leaf);

void InsLastLeaf (address1* head, address1* tail, address1 Q);

void InsFirstLeaf (address1* head, address1 Q);

void InsBetweenLeaf (address1* Pcur, address1 Q);

Link Pop (address1* tail);

address1 CreateListOfLeaf (address head);

Link CreateTree (address1 front);

#endif
