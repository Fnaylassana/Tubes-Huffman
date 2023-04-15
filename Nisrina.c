#include "Nisrina.h"
#include "Fauza.h"
address AlokasiChar(char X)
{
	 /* Kamus Lokal */
	 address P;
	 
	 /* Algoritma */
	 P = (address) malloc (sizeof (Node));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		Prev(P) = Nil;
		Info(P) = X;
		Freq(P) = 1;
		Next(P) = Nil;
	 }
	 return (P);
}

address Search (address front, char X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 bool found =  false;
	 /* algoritma */
	 P = front;
	 	while ((P != Nil) && (!found))
		{
			 if (Info(P) == X)
			 { 
			 found = true; 	
			 return P;
			 }
			else
			{	
			P = Next(P);
			}
		}
		return NULL;
	
}

void InsertLastChar (address *front, address *rear, address P)
{
	
	if(*front == Nil)
	{
		*front= P;
		*rear = P;
	}
	else
	{
		Next(*rear) = P;
		Prev(P) = *rear;
		*rear = P;
	}
}

void InsVLastChar(address *front, address *rear, char X)
{
	address P;
	P = AlokasiChar(X);
	if (P != Nil)
	{	
	InsertLastChar (front,rear, P);
			}
			
}



void sortingFreq(address *front)
{
	address Pcur;
	address temp, max;
	int tempFreq;
	char tempChar;
	
	Pcur = Nil;
	temp = Nil;
	max = Nil;
	
	if(*front!=NULL)
    {
        Pcur=*front;
        while(Next(Pcur)!=NULL)
        {
            temp=Pcur;
            max=Pcur;
            while(temp!=NULL)
            {
                if(Freq(temp) > Freq(max))
                {
                    max=temp;
                }
                temp = Next(temp);
            }
            if(Freq(Pcur) < Freq(max))
            {
            	tempChar = Info(Pcur);
                tempFreq= Freq(Pcur);
                Info(Pcur) = Info(max);
                Freq(Pcur) = Freq(max);
                Info(max)=tempChar;
                Freq(max)=tempFreq;
            }
            Pcur=Next(Pcur);
        }
    }
	
}

address createFrekuensi()
{
	FILE *in, *out;
    char ch;
    address front, rear;
    address tempAdd;
    address temp;
    
    front = NULL;
    rear = NULL;
 
    in = fopen("panjang.txt", "r");
    if (in == NULL)
    {
        printf("Cannot open source file.\n");
        exit(1);
    }
    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        printf("Cannot open destination file.\n");
        exit(1);
    }
    
    
 
    do {
        ch = getc(in);
        tempAdd = Search (front, ch);
        if(tempAdd == NULL)
        {
        	
        	InsVLastChar(&front, &rear, ch);
		}
		else
		{
			Freq(tempAdd)++;
		}
    }
    while (!feof(in));
 
    // print histogram data in the output file
    fputs("character    frequency    ", out);
    
    temp = front;
    
    while(temp != NULL)
    {
    	fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t", Info(temp), Freq(temp));
		temp = Next(temp);
	}
    

    fclose(out);
    fclose(in);
    
    return front;
}

void PrintInfoChar (address data)
{
	 /* Kamus Lokal */
	address P;
	int i;
	
	 /* Algoritma */
	if (data == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 printf (" %c : %d \n ", Info(P), Freq(P));
				 P = Next(P);
			}
		 }
	}
}

infotype InputCodeChar(infotype deskripsi)
{
	infotype KodeChar;
	
	KodeChar = (infotype)malloc(50*sizeof(char));
	
	printf("%s", deskripsi);
	scanf("%s", KodeChar);
	
	return KodeChar;
}


void SearchTree(Link root, char x, Link *temp2)
{
	Link temp;
	temp=root;
	if(temp != Nil)
	{
		if(Info(temp) == x)
			{
				*temp2 = temp;
			}
		SearchTree(RightSon(temp), x, &(*temp2));
		SearchTree(LeftSon(temp), x, &(*temp2));
	}
	
}

infotype Incode(Link root, infotype KodeChar)
{
	char huruf;
	Link alamat, Pcur;
	infotype KodeBinary;
	
	
	infotype tempBinary;
	tempBinary = (infotype)malloc(30*sizeof(char));
	tempBinary[0] = '\0';
	
	infotype temp;
	temp = (infotype)malloc(2*sizeof(char));
	temp[0] = '\0';
	
	
	alamat = Nil;
	Pcur = Nil;
	
	int i,length,j;
	i=0;
	do{
		KodeBinary = (infotype)malloc(30*sizeof(char));
		KodeBinary[0] = '\0';
		huruf = KodeChar[i];
		SearchTree(root, huruf, &alamat);
		while(alamat != root)
		{
			if(alamat == LeftSon(Parent(alamat)))
			{
				strcat(KodeBinary,"0");
				alamat = Parent(alamat);
			}
			else if(alamat == RightSon(Parent(alamat)))
			{
				strcat(KodeBinary,"1");
				alamat = Parent(alamat);
			}
		}
		length = strlen(KodeBinary);
		for(j=length;j>=0;j--)
		{
			temp[0]= KodeBinary[j];
			temp[1]= '\0';
			strcat(tempBinary,temp);
		}
		i++;
		
	}while(huruf != '\0');
	
	return tempBinary;
}



