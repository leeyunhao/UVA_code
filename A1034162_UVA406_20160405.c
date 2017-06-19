#include<stdio.h>

int chart[10010];

main(){
	int i,j,k,n,c,l,s,e;
	
	chart[1]=1;chart[2]=2;	
	for(k=3,i=3;i<=1010;i+=2){
	    for(j=2;j*j<=i;j++){
	    	if(i%j==0)break;
		}
		if(j*j>i){
			chart[k++]=i;
		}	
	}
	while(scanf("%d %d",&n,&c)!=EOF){
		for(i=0;chart[i]<n&&i<k;i++);
		l=i;
		if(chart[l]>n)l--;
		
		if(l%2!=0){
			s=(l+1)/2+1-c;
			e=(l+1)/2+c-1;
		}
		else{
		    s=l/2+1-c;
		    e=l/2+c;	
		}
		if(s<1)s=1;
		if(e>l)e=l;
		printf("%d %d:",n,c);
		for(i=s;i<=e;i++){
			printf(" %d",chart[i]);
		}
		printf("\n\n");
		
	}
	
} 
