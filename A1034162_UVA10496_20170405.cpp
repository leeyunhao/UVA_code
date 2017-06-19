#include<iostream>
#include<algorithm>
#include<cstdio>
#include<limits.h>
using namespace std;
int g[401][401],pos[400][2],mark[500],n;
int dfs(int l,int node,int num)
{
	int i,mi = INT_MAX;
	if(num == n + 1&&node == 0)return l;
	if(num == n + 1&&node != 0)return INT_MAX;
	for(i = 0;i <= n;i++)
	{
		if(g[node][i] != -1&&i == 0&&num == n+1)
			return l + g[node][i];
		if(g[node][i] != -1&&mark[i] == 0)
		{
			mark[i] = 1;
			mi = min(dfs(l + g[node][i],i,num + 1),mi);
			mark[i] = 0;
		}
	}
	return mi;
}
int main()
{
	int cas,i,j,w,h;
	scanf("%d",&cas);
	
	while(cas--)
	{
		scanf("%d %d",&w,&h);
		scanf("%d%d",&pos[0][0],&pos[0][1]);
		scanf("%d",&n);
		for(i = 1;i <= n;i++)
			scanf("%d%d",&pos[i][0],&pos[i][1]);
		for(i = 0;i <= n;i++)
			for(j = 0;j <= n;j++)
				g[i][j] = -1;
		for(i = 0;i < n;i++)
		{
			for(j = i+1;j <= n;j++)
			{
				g[i][j] = abs(pos[i][0]-pos[j][0]) + abs(pos[i][1]-pos[j][1]);
				g[j][i] = g[i][j];
			}
		}
		for(i = 0;i <= n;i++)
			mark[i] = 0;
		printf("The shortest path has length %d\n",dfs(0,0,0));
	}
	return 0;
}
