/*輸入營地的個數n，以及停留的夜晚數k，輸出最小的日最長距離
ex
	input 4 3
		  7
		  2
		  6
		  4
		  5
	ouput
		  8 
*/
#include<stdio.h>
main(){
	int i,j,sum,n,k;
	int camp[1000];
	
	while(scanf("%d %d",&n,&k)!=EOF){
		int min=0,max=0;
		for(i=0;i<=n;i++){
			scanf("%d",&camp[i]);
			if(camp[i]>min)
				min=camp[i];
			max+=camp[i];
		}
		int x;
		while(max!=min){
			j=1;
			sum=0;
			x=(max+min)/2;
			for(i=0;i<=n;i++){
				if(sum+camp[i]>x){
					j++;
					sum=0;
				}
				sum+=camp[i];
			}
			if(j>k+1)
				min=x+1;
			else
				max=x;
		}
		printf("%d\n",max);
		
	}
}
