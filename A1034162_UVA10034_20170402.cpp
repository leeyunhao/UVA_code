#include<iostream>
#include <cfloat>
#include<cstdio>
#include<cmath>
using namespace std;

double Prim(double g[][105],int n,int r)
{
    int f[105], mark[105] = {0};
    int i, j, u;
    double sum, key[105];
    for (i = 0;i <= n;i++) key[i] =  DBL_MAX;
    key[r] = 0;sum = 0;
     
    for (i = 1;i <= n;i++)
    {
        for (u = 0;u < n && mark[u] == 1;u++);
        for (j = u + 1;j < n;j++) 
            if(mark[j] == 0 && key[j] < key[u]) 
                u = j;
        mark[u] = 1;sum += key[u];
        for (j = 0;j < n;j++) 
            if(mark[j] == 0&&g[u][j] < key[j]) 
                key[j] = g[u][j], f[j] = u; 
    }
    return sum;
}
int main()
{
	double g[105][105],node[105][2];
	int t, i, j,n;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i = 0;i < n;i++)
		{
			scanf("%lf %lf",&node[i][0],&node[i][1]);
		}
		for(i = 0;i < n-1;i++)
		{
			for(j = i + 1;j < n;j++)
			{
				g[i][j] = sqrt(pow(node[i][0] - node[j][0],2.0) + pow(node[i][1] - node[j][1],2.0));
				g[j][i] = g[i][j];
			}
		}
		printf("%.2lf\n",Prim(g,n,0));
		if(t > 0)puts("");
	}
	return 0;	
} 
