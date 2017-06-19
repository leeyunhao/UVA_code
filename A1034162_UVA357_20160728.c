/*輸入錢數。輸出有幾種方法可以湊出輸入的錢數*/
#include<stdio.h>
int coin[5]={1,5,10,25,50};
main(){
	int cent,i,j,k;
	long long int dp[30005];
	for(i=0;i<30005;i++)
		dp[i]=0;
	for(dp[0]=1,i=0;i<5;i++)
		for(j=0;j<=30000-coin[i];j++)
			if(dp[j]!=0)
				dp[j+coin[i]]+=dp[j];
	while(scanf("%d",&cent)!=EOF){
		if(dp[cent]==1)
			printf("There is only %lld way to produce %d cents change.\n",dp[cent],cent);
		else
			printf("There are %lld ways to produce %d cents change.\n",dp[cent],cent);
	}
}
