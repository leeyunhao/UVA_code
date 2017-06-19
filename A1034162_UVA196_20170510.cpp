#include<iostream>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;
struct pts
{
	int row,col;
};
vector<pts> sheet[1010][1010];
int value[1010][1010];
int dfs(int r,int c)
{
	if(value[r][c] != -1) return value[r][c];
	int ans = 0,l = sheet[r][c].size();
	for(int i = l - 1;i >= 0;i--)
	{
		ans += dfs(sheet[r][c][i].col,sheet[r][c][i].row);
		sheet[r][c].pop_back();
	}
	return value[r][c] = ans;
}
void input(int i,int j)
{
	char s[5000];
	int k;
	pts p;
	scanf("%s",s);
	if(s[0] >= '0' && s[0] <= '9')
	{
		value[i][j] = 0;
		for(k = 0;s[k] != '\0';k++)
			value[i][j] = value[i][j]*10 + s[k] - '0';
	}
	else
	{
		p.row = 0,p.col = 0;
		for(k = 1;k <= strlen(s);k++)
		{
			if(s[k] >= 'A' && s[k] <= 'Z')
				p.row = p.row*26 + s[k] - 'A' + 1;
			else if(s[k] >= '0' && s[k] <= '9')
				p.col = p.col*10 + s[k] - '0';
			else
			{
				sheet[i][j].push_back(p);
				value[i][j] = -1,p.col = p.row = 0;
			}
		}
	}	
}
int main()
{
	int n,r,c,i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&c,&r);
		for(i = 1;i <= r;i++)
			for(j = 1;j <= c;j++)
				input(i,j);
		for(i = 1;i <= r;i ++)
			for(j = 1;j <= c;j++)
				dfs(i,j);
		for(i = 1;i <= r;i++)
		{
			printf("%d",value[i][1]);
			for(j = 2;j <= c;j++)
				printf(" %d",value[i][j]);
			puts("");
		}
	}
	return 0;
}
