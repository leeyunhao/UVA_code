#include<stdio.h>
main(){
	int stack[10000],top;
	int i,n,mk;
	char c;
	while(scanf("%d%c",&n,&c)!=EOF){
		mk=1;top=0;stack[top]=n;
		if(n>0){
			printf(":-( Try again.\n");
			continue;
		}
		while(c==' '&&scanf("%d%c",&n,&c)){
			if(n>0){
				if(stack[top]<0){
					if(n!=-stack[top])mk=0;
					stack[top]=n;
				}
				else{
					if(n<=stack[top]||n!=-stack[top-1])mk=0;
					stack[--top]=n;
				}
				if(top>0&&stack[top-1]>0){
					stack[--top]+=stack[top+1];
				}
			}
			else
				stack[++top]=n;
			if(c!=' ')
				break;
		}
		if(stack[top]<0)
			mk=0;
		if(mk==1)
			printf(":-) Matrioshka!\n");
		else
			printf(":-( Try again.\n");
	}
}
