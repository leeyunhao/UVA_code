#include<iostream>
using namespace std;
struct pts
{
	long long int x,y;
};
struct line
{
	pts a,b;
}l[1002];
long long int cross(long long int x1,long long int y1,long long int x2,long long int y2)
{
	return x1*y2 - x2*y1;
}
int main()
{
	int n,i,j,sum;
	long long int nils[1000];
	while(scanf("%d",&n)!=EOF && n != 0)
	{
		for(i = 0;i < n;i++)
		{
			scanf("%lld%lld%lld%lld",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
			nils[i] = 0;
		}
		for(i = 1;i < n;i++)
		{
			for(j = 0;j < i;j++)
			{
				if(cross(l[i].b.x - l[i].a.x,l[i].b.y - l[i].a.y,l[j].a.x - l[i].a.x,l[j].a.y - l[i].a.y)
				*cross(l[i].b.x - l[i].a.x,l[i].b.y - l[i].a.y,l[j].b.x - l[i].a.x,l[j].b.y - l[i].a.y) <= 0
				&& cross(l[j].b.x - l[j].a.x,l[j].b.y - l[j].a.y,l[i].a.x - l[j].a.x,l[i].a.y - l[j].a.y)
				*cross(l[j].b.x - l[j].a.x,l[j].b.y - l[j].a.y,l[i].b.x - l[j].a.x,l[i].b.y - l[j].a.y) <= 0)
				{
					nils[i]++,nils[j]++;
				}
			}
		}
		for(sum = 0,i = 0;i < n;i++)
			if(nils[i] == 0) sum += 4;
			else sum += nils[i];
		printf("%d\n",sum/2);
	}
	return 0;
}
