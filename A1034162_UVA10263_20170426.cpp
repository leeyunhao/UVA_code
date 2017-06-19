#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct pts
{
	double x,y;
};
struct line
{
	pts a,b;
};
double cross(pts a,pts b)
{
	return a.x * b.y - a.y *b.x;
}
double length(pts a,pts b)
{
	return sqrt(pow(a.x-b.x,2) + pow(a.y - b.y,2));
}
int main()
{
	double ll,gl;
    pts p,pl,pg,a,b;
    line l1;
    int i,n;
	while(scanf("%lf %lf",&p.x,&p.y)!=EOF)
	{
		scanf("%d",&n);
		scanf("%lf%lf",&a.x,&a.y);
		for(i = 0;i < n;i++)
		{
			scanf("%lf%lf",&b.x,&b.y);
			pts u,v,il;
			u.x = b.x - a.x,u.y = b.y - a.y;
			v.x = p.x -a.x,v.y = p.y - a.y;
			ll = fabs(cross(u,v))/length(a,b);
			il = u;
			if(il.x*v.x + il.y*v.y < 0) il.x *= -1,il.y *= -1;
			il.x /= length(a,b),il.y /= length(a,b);
			double l1 = length(a,p),l2;
			l2 = sqrt(pow(l1,2) - pow(ll,2));
			pl.x = a.x + l2 * il.x,pl.y = a.y + l2 * il.y;
			if((a.x - pl.x)*(b.x - pl.x) + (a.y - pl.y)*(b.y - pl.y) > 0)
			{
				if(length(a,p) < length(b,p)) pl = a,ll = length(a,p);
				else pl = b,ll = length(b,p);
			}
			a = b;
			if(ll < gl || i == 0)
			{
				pg = pl;
				gl = ll;
			}
		}
		printf("%.4lf\n%.4lf\n",pg.x,pg.y);
	}
	return 0;
}
