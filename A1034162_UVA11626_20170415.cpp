#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct pts
{
	long long int x,y;
}p[100050],rp;
int start; 
bool cmp(struct pts a,struct pts b)
{
	long long int x1 = a.x - rp.x,y1 = a.y -rp.y;
	long long int x2 = b.x - rp.x,y2 = b.y - rp.y;
	if(x1 * y2 == x2 * y1)
		return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
	return x1 * y2 > x2 * y1;
}
int main()
{
	int n,i,j,l,cas;
	long long int x,y;
	char c;
	scanf("%d\n",&cas);
	while(cas--)
	{
		scanf("%d\n",&n);
		for(l = 0,i = 0;i < n;i++)
		{
			scanf("%lld %lld %c",&x,&y,&c);
			if(c == 'N')continue;
			p[l].x = x,p[l].y = y;
			l++;	
		}
		for(start = 0,i = 1;i < l;i++)
		{
			if(p[start].x > p[i].x) start = i;
			if(p[start].x == p[i].x && p[start].y > p[i].y) start = i;
		}
		rp=p[start];
		printf("%d\n",l);
		sort(p,p + l,cmp);
		for(i = l - 1;p[i].x == p[0].x;i--);
		if(i == l - 1)
			for(i = l - 1;p[i].y == p[0].y;i--);
		for(j = 0;j <= i;j++)
			printf("%lld %lld\n",p[j].x,p[j].y);
		for(j = l - 1;j > i;j--)
			printf("%lld %lld\n",p[j].x,p[j].y);
	}	
} 
