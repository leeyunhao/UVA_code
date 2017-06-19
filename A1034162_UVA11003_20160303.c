#include<stdio.h> 
int ma(int a,int b)
{
	if(a>b)return a;
	return b;
}
int mi(int a,int b)
{
	if(a<b)return a;
	return b;
}
int dp[2000][3005];
main(){
	int i,j,k;
	int n,box[1005][2],max,ans;
	while(scanf("%d",&n)&&n!=0)
	{
		for(max=0,i=1;i<=n;i++)
		{
			scanf("%d%d",&box[i][0],&box[i][1]);
			if(max<box[i][1])max=box[i][1];
		}
		for(i=0;i<=n;i++)
			for(j=0;j<=max;j++)
				dp[i][j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=max;j++)
			{
				if(j<box[i][0])
				{
					dp[i][j]=ma(dp[i-1][j],dp[i][j]);
					continue;	
				}
				if(dp[i-1][j]>0)
				{
					k=mi(j-box[i][0],box[i][1]);
					dp[i][k]=ma(dp[i][k],dp[i-1][j]+1);
					dp[i][j]=ma(dp[i-1][j],dp[i][j]);
				}
			}
			if(dp[i][box[i][1]]==0)dp[i][box[i][1]]=1; 
		}
		for(ans=0,i=0;i<=max;i++)
			if(ans<dp[n][i])
				ans=dp[n][i];
		printf("%d\n",ans);
	}
}
