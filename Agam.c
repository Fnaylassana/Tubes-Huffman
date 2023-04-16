#include "header.h"
#include "Nisrina.h"
#include "Fauza.h"
#include "Agam.h"

infotype InputCodeBinary(infotype deskripsi)
{
	infotype str;
	
	str = (infotype) malloc (10 * sizeof(char));
	
	printf("%s", deskripsi);
	scanf("%s", str);
	
	return str;
}


infotype Decode(Link root){
	int i = 0;
	Link pCur;
	infotype str;
	
	str = (infotype) malloc (10 * sizeof(char));
	infotype kalimat;
	kalimat = (infotype) malloc (30 * sizeof(char));
	kalimat[0] ='\0';
	infotype temp;
	temp = (infotype) malloc (2 * sizeof(char));
	temp[0] ='\0';
	

	str = InputCodeBinary("\n--> Masukkan code:");
	printf("\nCode yang Anda inputkan %s", str);
	
	
	pCur = root;
	
	
	while(str[i] != '\0'){
		while(RightSon(pCur) != Nil && LeftSon(pCur) != Nil){
			if(str[i] == '1'){
				pCur = RightSon(pCur);
			}else if(str[i] == '0'){
				pCur = LeftSon(pCur);
			}
			i++;
		} 
		temp[0] = Info(pCur);
		temp[1] = '\0';
		strcat(kalimat,temp);
		pCur = root;	
	}

	
	printf("\nKata tersebut adalah %s", kalimat);	
}




