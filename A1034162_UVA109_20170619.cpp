#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct pts
{
    double x,y;
}poly[20][1000],f[1000],missile,st;
int np,mark[20];
double cross(double x1,double y1,double x2,double y2)
{
    return x1 * y2 - x2 * y1;
}
bool cmp(struct pts a,struct pts b)
{
    double x1 = a.x - st.x,y1 = a.y - st.y;
    double x2 = b.x - st.x,y2 = b.y - st.y;
    double c = cross(x1,y1,x2,y2);
    if(c == 0)
        return x1*x1 + y1*y1 < x2*x2 + y2*y2;
    return c > 0;
}
int check(struct pts p[],int n,struct pts t)
{
    int i,j;
    int x1,y1,x2,y2;
    if(n == 1 && (p[0].x != t.x || p[0].y != t.y)) return 0;
    for(i = 0;i < n;i++)
    {
        j = (i + 1) % n;
        x1 = p[j].x - p[i].x,y1 = p[j].y - p[i].y;
        x2 = t.x - p[i].x,y2 = t.y - p[i].y;
        if(cross(x1,y1,x2,y2) <= 0) return 0;
    }
    if(n == 2)
    {
        x1 = p[1].x - t.x,y1 = p[1].y - t.y;
        x2 = p[0].x - t.x,y2 = p[0].y - t.y;
        if(x1*x2 + y1*y2 > 0) return 0;
    }
    return 1;
}
int Graham(struct pts p[],struct pts poly[],int n)
{
    int i,top;
    double c,x1,y1,x2,y2;
    st = p[0];
    for(i = 1;i < n;i++)
    {
        if(p[i].x < st.x) st = p[i];
        if(p[i].x == st.x && p[i].y < st.y) st = p[i];
    }
    sort(p,p+n,cmp);
    top = 1,poly[0] = p[0],poly[1] = p[1];
    for(i = 2;i < n;i++)
    {
        for(;top>0;top--)
        {
            x1 = poly[top].x - poly[top-1].x,y1 = poly[top].y - poly[top-1].y;
            x2 = p[i].x - poly[top].x,y2 = p[i].y - poly[top].y;
            c = cross(x1,y1,x2,y2);
            if(c > 0)break;
        }
        top++;
        poly[top] = p[i];
    }
    return top+1;
}
double poly_area(struct pts poly[],int n)
{
	double sum = 0;
	for(int i = 0;i < n;i++)
	{
		int j = (i + 1)%n;
		sum += 0.5*(poly[i].x*poly[j].y - poly[i].y*poly[j].x);
	}
	return sum;
}
int main()
{
    int n,i,j,l[20];
    double length,area;
    np = 0;
    while(scanf("%d",&n)&&n != -1)
    {
        for(i = 0;i < n;i++)
            scanf("%lf%lf",&f[i].x,&f[i].y);
        l[np] = Graham(f,poly[np],n);
        mark[np] = 0;
        np++;
    }
    area = 0;
    while(scanf("%lf%lf",&missile.x,&missile.y) != EOF)
    {
    	for(i = 0;i < np;i++)
    	{
    		if(check(poly[i],l[i],missile) == 1 && mark[i] == 0)
    			area += poly_area(poly[i],l[i]),mark[i] = 1;
		}
	}
	printf("%.2lf\n",area);
    return 0;
}
