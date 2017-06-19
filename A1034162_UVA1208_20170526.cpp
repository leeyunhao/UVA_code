#include<iostream>
#include<algorithm>
using namespace std;
struct edge
{
	int x,y,d;
}e[1000];
bool cmp(edge a,edge b)
{
	if(a.d == b.d)
	{
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.d < b.d;
}
int p[100];
int find(int x)
{
	if(p[x] == x) 
		return x;
	return p[x] = find(p[x]);
}
void ksk(int n,int l)
{
	for(int i = 0;i < n;i++)
		p[i] = i;
	sort(e,e + l,cmp);
	for(int i = 0,j = 0;i < n - 1;i++)
	{
		while(find(e[j].x) == find(e[j].y)) j++;
		p[find(e[j].y)] = find(e[j].x);
		printf("%c-%c %d\n",'A' + e[j].x,'A' + e[j].y,e[j].d);
	}
}
int main()
{
	int t,ca = 1,w;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int l = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(j < n - 1) scanf("%d,",&w);
				else scanf("%d",&w);
				if(w != 0) 
				{
					e[l].x = min(i,j),e[l].y = max(i,j);
					e[l++].d = w;
				}
			}
		}
		printf("Case %d:\n",ca++);
		ksk(n,l);
	}
	return 0;
}
