#include<stdio.h>
int dp[11][105][105];
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int min(int a,int b){
	if(a<b)return a;
	return b;
}
main(){
	int t,p,i,j,l,m,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&k,&m);
		for(p=1;p<=k;p++)
			for(i=m;i>=1;i--)
				for(j=i-1;j<=m;j++)
					if(j<i)dp[p][i][j]=0;
					else	if(p==1)dp[p][i][j]=dp[p][i][j-1]+j;
					else	if(i==j)dp[p][i][j]=i;
					else	for(dp[p][i][j]=100000000,l=i;l<=j;l++)
								dp[p][i][j]=min(dp[p][i][j],l+max(dp[p-1][i][l-1],dp[p][l+1][j]));
					
		printf("%d\n",dp[k][1][m]);
	}
}
