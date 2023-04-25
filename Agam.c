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


infotype Decode(Link root, infotype str){
	int i = 0;
	Link pCur;
	
	infotype kalimat;
	kalimat = (infotype) malloc (30 * sizeof(char));
	kalimat[0] ='\0';
	
	infotype temp;
	temp = (infotype) malloc (2 * sizeof(char));
	temp[0] ='\0';
	
	
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

	return kalimat;
}




