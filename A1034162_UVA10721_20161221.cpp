#include<stdio.h>
main(){
	long long int dp[55][55];
	int n,k,m,i,j,p;
	
	while(scanf("%d %d %d",&n,&k,&m)!=EOF){
		for(i=0;i<=n;i++){
			dp[i][0]=0;
			dp[0][i]=0;
		}
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++){
				if(i<j){dp[i][j]=0;continue;}
				if(i/j>m){dp[i][j]=0;continue;}
				dp[i][j]=0;
				for(p=1;p<=m;p++){
					if(i>=p&&i-p>=j-1)
						dp[i][j]+=dp[i-p][j-1];	
				}
			}
		}
		printf("%lld\n",dp[n][k]);
	}
}
