#include<stdio.h>

main(){
	
	int t,n,j[1000];
	int i,k=1,u,d;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	
		for(i=0;i<n;i++){	
			scanf("%d",&j[i]);
		}
		for(u=0,d=0,i=1;i<n;i++){
			if(j[i]>j[i-1])d++;
			if(j[i]<j[i-1])u++;
		}
		printf("Case %d:",k++);
		printf(" %d %d\n",d,u);
	}
	
} 
