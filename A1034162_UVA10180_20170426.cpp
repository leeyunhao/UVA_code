#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct pts
{
	double x,y;
};
double dis(pts a,pts b)
{
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double cross(double x1,double y1,double x2,double y2)
{
	return x1*y2 - x2*y1;
}
int main()
{
	double r,l;
	pts a,b;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&r);
		l = fabs(cross(-a.x,-a.y,b.x - a.x,b.y - a.y)) / dis(a,b);
		if(l >= r || dis(a,b) == 0)
		{
			printf("%.3lf\n",dis(a,b));
			continue;
		}
		pts c;
		c.x = a.y - b.y,c.y = b.x - a.x;
		if(cross(c.x,c.y,a.x,a.y) * cross(c.x,c.y,b.x,b.y) > 0)
		{
			printf("%.3lf\n",dis(a,b));
			continue;
		}
		double t,t3,t4;
		double la,lb,lc;
		la = sqrt(pow(a.x,2) + pow(a.y,2)),lb = sqrt(pow(b.x,2) + pow(b.y,2));
		lc = sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
		t = acos((pow(la,2) + pow(lb,2) - pow(lc,2))/(2*la*lb));
		t3 = acos(r/sqrt(a.x*a.x + a.y*a.y));
		t4 = acos(r/sqrt(b.x*b.x + b.y*b.y));
		printf("%.3lf\n",r*tan(t3) + r*tan(t4) + r*(t - t3 -t4));
	}
	return 0;
}
