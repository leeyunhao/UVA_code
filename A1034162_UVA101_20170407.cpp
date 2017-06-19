#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int pos[40],block[40][40],top[40];
void remove(int a)
{
	int i;
	for(i = top[a];i > 0;i--)
		block[a][i] = block[a][i-1];
	block[a][0] = a;
	top[a]++;pos[a] = a;
}
void put(int ax,int s,int bx)
{
	int i;
	for(i = s;i < top[ax];i++)
	{
		block[bx][top[bx]] = block[ax][i];
		pos[block[ax][i]] = bx;
		top[bx]++;
	}
	top[ax] = s;
}
int main()
{
	int n,i,j,a,b;
	char s1[10],s2[10];
	while(scanf("%d",&n) != EOF)
	{
		for(i = 0;i < n;i++)
			block[i][0] = i,pos[i] = i,top[i] = 1;
		while(scanf("%s",s1) != EOF&&s1[0] != 'q')
		{
			scanf("%d%s%d",&a,s2,&b);
			int ax = pos[a],bx = pos[b];
			if(ax == bx)continue;
			if(s1[0] == 'm')
			{
				if(s2[1] == 'n')
				{
					for(i = top[ax] - 1;block[ax][i] != a;i--)
						remove(block[ax][i]);
					top[ax] = i;
					for(i = top[bx]-1;block[bx][i] != b;i--)
						remove(block[bx][i]);
					top[bx] = i + 1;
					block[bx][top[bx]] = a;top[bx]++;pos[a] = bx;
				}
				else
				{
					for(i = top[ax] - 1;block[ax][i] != a;i--)
						remove(block[ax][i]);
					top[ax] = i;
					block[bx][top[bx]] = a;top[bx]++;pos[a] = bx;
				}	
			}
			if(s1[0] == 'p')
			{
				if(s2[1] == 'n')
				{
					for(i = top[bx] - 1;block[bx][i] != b;i--)
						remove(block[bx][i]);
					top[bx] = i + 1;
					for(i = top[ax] - 1;block[ax][i] != a;i--);
					put(ax,i,bx);
				}
				else
				{
					for(i = top[ax] - 1;block[ax][i] != a;i--);
					put(ax,i,bx);
				}
			}
		}
		for(i = 0;i < n;i++)
		{
			printf("%d:",i);
			for(j = 0;j < top[i];j++)
				printf(" %d",block[i][j]);
			puts("");
		}
	}
	return 0;	
} 
