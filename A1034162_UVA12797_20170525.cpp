#include<iostream>
#define MAX 1000000
using namespace std;
struct node 
{
	int x,y,d;
}queue[10005];
int mo[4][2] = {-1,0,0,1,1,0,0,-1};
int graph[105][105],mark[105][105];
int check(int x,int y) 
{
	if(y > 0) 
	{
		if((x & 1 << (y-1)) == 0)
			return 0;
		return 1;
	}
	if((x & 1 << (-y-1)) == 0)
		return 1;
	return 0;
}
int bfs(int k,int n) 
{
	for(int i = 0;i < n;i++) 
		for(int j = 0;j < n;j++)
			mark[i][j] = 0;
	int l = 0,r = 1;
	queue[0].x = 0,queue[0].y = 0;
	queue[0].d = 1,mark[0][0] = 1;
	while(l < r) 
	{
		if(queue[l].x == n - 1 && queue[l].y == n - 1) 
			return queue[l].d; 
		for(int i = 0;i < 4;i++) 
		{
			int xx = queue[l].x + mo[i][0],yy = queue[l].y + mo[i][1];
			if(xx < 0 || xx >= n || yy < 0 || yy >= n) 
				continue;
			if(mark[xx][yy] == 1)
				continue;
			if(check(k,graph[xx][yy]) == 0)	
			 	continue;
			queue[r].x = xx,queue[r].y = yy;
			queue[r].d = queue[l].d + 1,mark[xx][yy] = 1;
			r++;
		}
		l++;	
	}
	return MAX;
}
int main() {
	int n;
	char s[105];
	while(scanf("%d\n",&n) != EOF) 
	{
		for(int i = 0;i < n;i++) 
		{
			gets(s);
			for(int j = 0;s[j] != '\0';j++)
			{ 
				if(s[j] >= 'A' && s[j] <= 'Z') 
					graph[i][j] = -(s[j] - 'A' + 1);
				else 
					graph[i][j] = s[j] - 'a' + 1;	
			}
		}
		int slg = MAX;
		for(int i = 0;i <= 1023;i++) 
		{
			if(check(i,graph[0][0]) == 0 || check(i,graph[n-1][n-1]) == 0)
				continue;
			slg = min(slg,bfs(i,n));
		}
		if(slg == MAX) 
			printf("-1\n");
		else
			printf("%d\n",slg);	
	} 
	return 0;
}
