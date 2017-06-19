#include<stdio.h>
main(){
	int dp[200000],mk[200000],i,k,m[6],sum,cas=1;
	for(;;){
		for(i=0,sum=0;i<6;i++){		
			scanf("%d",&m[i]);
			sum+=(i+1)*m[i]; 
		}
		for(i=0;i<6&&m[i]==0;i++);
		if(i==6)break;
		for(i=1,dp[0]=1;i<=sum/2;i++)
			dp[i]=0;
		for(i=0;i<6;i++){
			for(k=0;k<=sum/2;k++)
				mk[k]=0;
			for(k=0;k<=sum/2-i-1;k++)
				if(dp[k]==1&&mk[k]<m[i]&&dp[k+i+1]!=1){
					dp[k+i+1]=1;
					mk[k+i+1]+=mk[k]+1;
			    }
		}
		if(dp[sum/2]==1&&sum%2==0)
			printf("Collection #%d:\nCan be divided.\n\n",cas++);
		else
			printf("Collection #%d:\nCan't be divided.\n\n",cas++);
	}
}
