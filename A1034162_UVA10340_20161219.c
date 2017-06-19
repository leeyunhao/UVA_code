#include<stdio.h>
#include<string.h>
char a[10000000],b[10000000];
int main(){
	int i,j,l1,l2,mark;
	
	while(scanf("%s %s",a,b)!=EOF){
		l1=strlen(a);
		l2=strlen(b);
		mark=0;
		for(i=0,j=0;i<l1;i++){
			for(;b[j]!=a[i]&&j<l2;j++);
			if(j==l2){
				mark=1;
				break;
			}
			else
				j++;	
		}
		if(mark==0){
			printf("Yes\n");
			continue;
		}
		mark=0;
		for(i=0,j=0;i<l2;i++){
			for(;a[j]!=b[i]&&j<l1;j++);
			if(j==l1){
				mark=1;
				break;
			}
			else
				j++;	
		}
		if(mark==0){
			printf("Yes\n");
			continue;
		}
		else
		    printf("No\n");
	}
}
