#include<stdio.h>
main(){
	int t,n,i,j,sum,dp[22000],a[22000];
	int max,maxp,ca=0,gs,ps;
	scanf("%d",&t);
	while(t--){
		ca++;
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			scanf("%d",&a[i]);
		}
		max=0,maxp=0;sum=0;gs=-1;ps=-1;
		for(i=0;i<n-1;i++){
			dp[i]=sum+a[i];
			if(max==dp[i]){
				if(i-ps>maxp-gs){
					maxp=i;
					gs=ps;
				}
			}
			else if(max<dp[i]){
					maxp=i;
				 	gs=ps;
					max=dp[i];
				}
			if(sum+a[i]<0){
				sum=0;
				ps=i;
			}
			else
				sum+=a[i];
		}
		if(max<=0){
			printf("Route %d has no nice parts\n",ca);
			continue;
		}
		printf("The nicest part of route %d is between stops %d and %d\n",ca,gs+2,maxp+2);
	}
}
