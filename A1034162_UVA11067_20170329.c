#include<stdio.h>
int dp[200][200];
main()
{
	int w,h,n,i,j,x,y;
	while(scanf("%d%d",&w,&h)!=EOF)
	{
		if(w==0&&h==0)break;
		scanf("%d",&n);
		for(i=0;i<=w;i++)
			for(j=0;j<=h;j++)
				dp[i][j]=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			dp[x][y]=0;
		}
		for(dp[0][0]=1,i=0;i<=w;i++)
		{
			for(j=0;j<=h;j++)
			{
				if((i==0&&j==0)||dp[i][j]==0)continue;
				dp[i][j]=0;
				if(i>0)dp[i][j]+=dp[i-1][j];
				if(j>0)dp[i][j]+=dp[i][j-1];	
			}	
		}
		if(dp[w][h]<=0)
			printf("There is no path.\n");
		else if(dp[w][h]==1)
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else
			printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",dp[w][h]);
	}
}
