#include<stdio.h>
long long dp[1000000];
main(){
	long int i,n,p;
	for(dp[3]=0,i=4;i<=1000000;i++){
		p=(i-2)/2;
		if(i%2==0)
			dp[i]=dp[i-1]+p*p;
		else
			dp[i]=dp[i-1]+p*(p+1);
	}
	while(scanf("%d",&n)&&n>=3){
		printf("%lld\n",dp[n]);
	}
} 
