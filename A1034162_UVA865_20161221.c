#include<stdio.h>
#include<string.h>
main(){
	int t,i,j;
	char c[100],uc[100],s[100];
	scanf("%d\n\n",&t);
	while(t--){
		gets(c);gets(uc);
		puts(uc);puts(c);
		while(gets(s)!=NULL&&strlen(s)!=0){
			for(i=0;s[i]!='\0';i++){
				for(j=0;c[j]!=s[i]&&c[j]!='\0';j++);
				if(c[j]!='\0')
					printf("%c",uc[j]);
				else
					printf("%c",s[i]);
			}
			printf("\n");
		} 
		if(t!=0)
		printf("\n");
	}
}
