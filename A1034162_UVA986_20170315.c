#include<stdio.h>
main()
{
	int n,r,k,dp[50][30][30][2];
	int i,j,h;
	while(scanf("%d%d%d",&n,&r,&k)!=EOF)
	{
		for(j=0;j<=n;j++)
			for(h=0;h<r;h++)
			{
				dp[0][j][h][0]=0;
				dp[0][j][h][1]=0;
			
			}	
		dp[0][0][0][0]=1;
		for(i=1;i<=2*n;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(h=0;h<=r;h++)
				{	
					dp[i][j][h][0]=0;dp[i][j][h][1]=0;
					if(j>0)
					{
						dp[i][j][h][0]+=dp[i-1][j-1][h][0];
						if(j==k&&h>0)
							dp[i][j][h][1]+=dp[i-1][j-1][h-1][0];
						else if(j!=k)
							dp[i][j][h][1]+=dp[i-1][j-1][h][0];
					}
					if(j<n)
					{
						dp[i][j][h][1]+=dp[i-1][j+1][h][1];
						dp[i][j][h][0]+=dp[i-1][j+1][h][1];
					}				
				}
			}
		}
		printf("%d\n",dp[2*n][0][r][0]);
	}
}
