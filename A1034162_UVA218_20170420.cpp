#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct pts
{
    double x,y;
}p[1000],ch[1000],st;
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
int Graham(struct pts p[],int n)
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
    top = 1,ch[0] = p[0],ch[1] = p[1];
    for(i = 2;i < n;i++)
    {
        for(;top>0;top--)
        {
            x1 = ch[top].x - ch[top-1].x,y1 = ch[top].y - ch[top-1].y;
            x2 = p[i].x - ch[top].x,y2 = p[i].y - ch[top].y;
            c = cross(x1,y1,x2,y2);
            if(c > 0)break;
        }
        top++;
        ch[top] = p[i];
    }
    return top+1;
}
int main()
{
    int n,i,j,l,rg = 1;
    double length;
    while(scanf("%d",&n)&&n != 0)
    {
    	for(i = 0;i < n;i++)
        	scanf("%lf%lf",&p[i].x,&p[i].y);
    	l = Graham(p,n);
    	if(rg>1)puts("");
    	printf("Region #%d:\n",rg++);
    	length = 0;
    	printf("(%.1lf,%.1lf)-",ch[0].x,ch[0].y);
    	for(i = l-1;i >= 0;i--)
		{
			length += sqrt(pow(ch[i].x - ch[(i+1)%l].x,2) + pow(ch[i].y - ch[(i+1)%l].y,2));
			printf("(%.1lf,%.1lf)",ch[i].x,ch[i].y);
			if(i>0)printf("-");
		}
		puts("");
		printf("Perimeter length = %.2lf\n",length);
	}
    return 0;
}
