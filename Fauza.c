#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"

Link CreateNodeTree(char huruf, int freq)
{
	Link P;
	
	P = (Link) malloc (sizeof(nodeTree));
	
	if (P != NULL){
		Info(P) = huruf;
		Freq(P) = freq;
		LeftSon(P) = NULL;
		RightSon(P) = NULL;
		Parent(P) = NULL;
	}
	
	return P;
}

address1 CreateLeafRef(Link leaf)
{
	address1 P;
	
	P = (address1) malloc (sizeof(leafref));
	
	if (P != NULL){		
		Info(P) = leaf;
		Prev(P) = NULL;
		Next(P) = NULL;
	}
	
	return P;
}

void InsLastLeaf (address1* head, address1* tail, address1 Q)
{
	address1 P;
	
	P = *tail;
	
	if (*head == NULL){
		*head = Q;
	} else{
		Prev(Q) = P;
		Next(P) = Q;
	}
	
	*tail = Q;
}

void InsFirstLeaf (address1* head, address1 Q)
{
	address1 P;
	
	P = *head;
	
	if (*head != NULL){
		Prev(P) = Q;
		Next(Q) = P;
	}
	
	*head = Q;
}

void InsBetweenLeaf (address1* Pcur, address1 Q)
{
	address1 P;
	
	P = *Pcur;
	
	Prev(Next(P)) = Q;
	Next(Q) = Next(P);
	
	Next(P) = Q;
	Prev(Q) = P;
	
	*Pcur = Q;
}

Link Pop (address1* tail)
{
	address1 Pcur, Pdel;
	Link temp;
	
	Pcur = *tail;
	temp = Info(Pcur);
	Pdel = *tail;
	
	if (Prev(Pcur) != NULL){
		Pcur = Prev(Pcur);
		Next(Pcur) = NULL;	
	} else{
		Pcur = NULL;
	}
	
	*tail = Pcur;
	
	free(Pdel);
	
	return temp;
}

address1 CreateListOfLeaf (address head)
{
	address1 front, rear, P;
	
	front = NULL;
	rear = NULL;
	
	while (head != NULL){
		P = CreateLeafRef(CreateNodeTree (Info(head), Freq(head)));
		
		InsLastLeaf (&front, &rear, P);
		
		head = Next(head);
	}
	
	return front;
}

Link CreateTree (address1 front)
{
	Link parent, right, left;
	address1 rear, P, pcur;
	int i;
	
	rear = NULL;
	rear = front;
	
	while (Next(rear) != NULL){
		rear = Next(rear);
	}
	
	while (1){
		right = Pop (&rear);
		left = Pop(&rear);

		parent = CreateNodeTree('*', Freq(right)+Freq(left));
		
		RightSon(parent) = right;
		LeftSon(parent) = left;
		Parent(right) = parent;
		Parent(left) = parent;
		
		if (rear == NULL){
			return parent;
		} else{
			pcur = rear;
			
			P = CreateLeafRef(parent);
		
			if(Freq(parent) > Freq(Info(pcur))){
				while (Freq(parent) > Freq(Info(pcur)) && Prev(pcur) != NULL){
					pcur = Prev(pcur);
				}
				if (Prev(pcur) == NULL) {
					InsFirstLeaf (&front, P);
				} else {
					InsBetweenLeaf (&pcur, P);
				}
			}else {
				InsLastLeaf (&front, &rear, P);
			}
		}	 
	}
}

void CekHarga (Link root)
{
	infotype barang, harga, stok;
	
	barang = InputCodeBinary("\n--> Masukkan kode barang: ");
	
	if (SearchBarang("coba.txt", barang)){
    	FSearchBarang("coba.txt", barang, &harga, &stok);
    	barang = Decode(root, barang);
    	printf ("\nNama barang: %s", barang);
    	harga = Decode(root, harga);
    	printf ("\nHarga: %s", harga);
    	stok = Decode(root, stok);
    	printf ("\nJumlah stok: %s", stok);
	} else{
		printf ("\nKode barang yang anda inputkan salah");
	}
}

bool SearchBarang(infotype NmFile, infotype NmBarang){
	FILE *in;
	bool ketemu = false;
	infotype nama, harga, stok;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(!feof(in) && !ketemu){
			nama = (infotype) malloc (50*sizeof(char));
			harga = (infotype) malloc (50*sizeof(char));
			stok = (infotype) malloc (50*sizeof(char));
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\n]\n", nama, harga, stok);
			fflush(stdin);
        	if (strcmp(NmBarang, nama) == 0){
	          	ketemu = true;
			}
       }
       fclose(in);
    }
    
	return ketemu;
}

void FSearchBarang(infotype NmFile, infotype NmBarang, infotype *Harga, infotype *Stok){
	FILE *in;
	infotype nama;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(1){
			nama = (infotype) malloc (50*sizeof(char));
			*Harga = (infotype) malloc (50*sizeof(char));
			*Stok = (infotype) malloc (50*sizeof(char));
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\n]\n", nama, *Harga, *Stok);
			fflush(stdin);
        	if (strcmp(NmBarang, nama) == 0){
				break;
			}
       }
       fclose(in);
    }
}
