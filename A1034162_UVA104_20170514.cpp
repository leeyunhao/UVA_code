#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double dp[50][30][30],graph[50][30];
int mark[30][30][30],ans[50];
int main()
{
	int n,i,j,k,p,flag1,flag2;
	while(scanf("%d",&n)!=EOF && n!= 0)
	{
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(i == j) graph[i][j] = 1;
				else
				{
					scanf("%lf",&graph[i][j]);
				}
			}
		}
		flag1 = -1,flag2 = -1;
		for(i = 1;i <= n && flag1 == -1;i++)
		{
			for(j = 0;j < n && flag1 == -1;j++)
			{
				for(k = 0;k < n;k++)
				{
					dp[i][j][k] = 0;
					if(i == 1)
					{
						dp[i][j][k] = graph[j][k];
						mark[i][j][k] = j;
						continue;
					}
					for(p = 0;p < n;p++)
					{
						if(dp[i][j][k] < dp[i - 1][j][p]*graph[p][k])
						{
							dp[i][j][k] = dp[i - 1][j][p]*graph[p][k];
							mark[i][j][k] = p;
						}
					}
					if(j == k && dp[i][j][k] >= 1.01)
					{
						flag1 = j;
						flag2 = i;
						break;
					}
				}
			}
		}
		if(flag1 == -1)
		{
			printf("no arbitrage sequence exists\n");
			continue;
		}
		j = flag1;
		for(i = 0;i <= flag2;i++)
		{
			ans[i] = j + 1;
			j = mark[flag2 - i][flag1][j];
		}
		printf("%d",ans[flag2]);
		for(i = flag2 - 1;i >= 0;i--)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
} 
