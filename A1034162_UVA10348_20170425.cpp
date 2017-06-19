#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double land[60][25][2];
int np[60];
struct sub
{
	double fx,fy,rx,ry;
}s[105];
bool pointloc(double x,double y,int n)
{
	int i;
	int count = 0;
	for(i = 0;i < np[n];i++)
	{
		int j,k;
		if(land[n][i][1] < land[n][(i+1)%np[n]][1]) j = i,k = (i+1)%np[n];
		else k = i,j = (i+1)%np[n];
		double y1 = land[n][k][1],y2 = land[n][j][1],x1 = land[n][k][0],x2 = land[n][j][0];
		if(y1 >= y && y2 <= y)
		{
			double t = (y - y1)/(y2 - y1);
			double xp = x1 + t*(x2 - x1);
			if(xp >= x)
				count++;
		}
	}
	if(count%2 == 0) return false;
	return true;
}
bool lineploc(double u1,double v1,double u2,double v2,double x1,double y1,double x2,double y2 )
{
	double a = u2 - u1,b = x2 - x1,c = x1 - u1;
	double d = v2 - v1,e = y2 - y1,f = y1 - v1;
	if(a*e == d*b)
		return false;
	double t = (c*e - f*b)/(a*e - d*b);
	double s;
	if(b!=0)
	s = (a*t - c)/b;
	else
	s = (t*d - f)/e;
	if(t < 0 || t > 1|| s < 0 ||s > 1)return false;
	return true;
}
int main()
{
	int nland,nsub,i,j;
	int mark1,mark2,markl,k;
	double x1,y1,x2,y2;
	
	while(scanf("%d",&nsub)!=EOF)
	{
		for(i = 0;i < nsub;i++)
			scanf("%lf%lf%lf%lf",&s[i].fx,&s[i].fy,&s[i].rx,&s[i].ry);
	
		scanf("%d",&nland);
		for(i = 0;i < nland;i++)
		{
			scanf("%d",&np[i]);
			for(j = 0;j < np[i];j++)
				scanf("%lf%lf",&land[i][j][0],&land[i][j][1]);
		}
	
		for(i = 0;i < nsub;i++)
		{
		
			for(j = 0;j < nland;j++)
			{
				markl = 0,mark1 = 0,mark2 = 0;
		    	if(pointloc(s[i].fx,s[i].fy,j))	mark1 = 1;
		    	else mark2 = 1;
				if(pointloc(s[i].rx,s[i].ry,j))	mark1 = 1;
		    	else mark2 = 1;
				for(k = 0;k < np[j];k++)
				{
					if(lineploc(s[i].fx,s[i].fy,s[i].rx,s[i].ry,land[j][k][0],land[j][k][1],land[j][(k+1)%np[j]][0],land[j][(k+1)%np[j]][1]))
					{
			 			markl = 1;
						break;
			 		}
				}
				if(mark1 == 1 && mark2 == 0) break;
				if(markl == 1) break;
			}
			if(markl == 1) printf("Submarine %d is partially on land.\n",i+1);
			else if(mark1 == 1 && mark2 ==0) printf("Submarine %d is completely on land.\n",i+1);
			else printf("Submarine %d is still in water.\n",i+1);
		}
	}
	return 0;
}
