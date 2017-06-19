#include<iostream>
#include<cstdio>
using namespace std;
struct pts
{
	int x,y;
};
struct segm
{
	pts a,b;
};
int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2 - x2*y1;
}
segm set[10000];
int main()
{
	int cas,i,j,n,sum,insert;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
			scanf("%d%d%d%d",&set[i].a.x,&set[i].a.y,&set[i].b.x,&set[i].b.y);
		sum = 1;
		for(i = 1;i < n;i++)
		{
			insert = 0;
			for(j = 0;j < i;j++)
			{
				if(cross(set[i].b.x - set[i].a.x,set[i].b.y - set[i].a.y,set[j].a.x - set[i].a.x,set[j].a.y - set[i].a.y) *
					 cross(set[i].b.x - set[i].a.x,set[i].b.y - set[i].a.y,set[j].b.x - set[i].a.x,set[j].b.y - set[i].a.y) < 0&&
					 cross(set[j].b.x - set[j].a.x,set[j].b.y - set[j].a.y,set[i].a.x - set[j].a.x,set[i].a.y - set[j].a.y) *
					 cross(set[j].b.x - set[j].a.x,set[j].b.y - set[j].a.y,set[i].b.x - set[j].a.x,set[i].b.y - set[j].a.y) < 0)
					 insert++;
			}
			sum += 2*insert + 1;
		}
		printf("%d\n",sum);
		if(cas > 0) puts("");
	}
	return 0;
}
