#include<stdio.h>

char key[]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

main(){
	char code[2000];
	int i,j;
	
	while(gets(code)!=NULL){
		for(i=0;code[i]!='\0';i++){
			if(code[i]=='\\')printf("]");
			for(j=0;j<50;j++){
				if(code[i]==key[j])printf("%c",key[j-1]);
			}
			if(code[i]==' ')printf(" ");
		}
		printf("\n");
		
	}
}
