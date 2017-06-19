#include<iostream>
using namespace std;
int main()
{
	int mark[101],graph[101][101],m,n;
	int i,j,k,x,y;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		if(m == 0 && n == 0) break;
		for(i = 1;i <= m;i++)
		{
			mark[i] = 0;
			for(j = 1;j <= m;j++)
				graph[i][j] = 0;
		}
		for(i = 0;i < n;i++)
		{
			scanf("%d%d",&x,&y);
			graph[x][y] = 1;
			mark[y]++;
		}
		for(i = 0;i < m;i++)
		{
			for(j = 1;j <= m;j++)
				if(mark[j] == 0) break;
			if(i > 0) printf(" ");
			printf("%d",j);
			mark[j] = -1;
			for(k = 1;k <= m;k++)
				if(graph[j][k] == 1)
					mark[k]--;
		}
		printf("\n");
	}
	return 0;
}
