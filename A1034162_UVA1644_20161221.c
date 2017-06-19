#include<stdio.h>
int p[1299709];
main(){
	int i,j,n,l,r;
	for(i=0;i<=1299709;i++)p[i]=1;
	for(i=2;i*i<=1299709;i++){
		if(p[i]==1){
			for(j=2;i*j<1299709;j++)
				p[i*j]=0;
		}
	}
	while(scanf("%d",&n)!=EOF&&n!=0){
		l=n;r=n;
		if(p[n]==1){
			printf("0\n");
			continue;	 
		}
		for(;p[l]==0;l--);
		for(;p[r]==0;r++);
		printf("%d\n",r-l);
	} 
}
