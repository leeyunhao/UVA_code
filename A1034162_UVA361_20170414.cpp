#include<iostream>
#include<cstdio>
using namespace std;
struct point
{
	int x,y;	
}cop[220],cch[220],rob[220],rch[220],c[220];
int cmp(struct point p1,struct point p2)
{
	if(p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}
int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2 - x2*y1;
}
void ch(struct point p[],int n,struct point ch[],int& l)
{
	int start,i,j,ns;
	for(start = 0,i = 1;i < n;i++)
		if(cmp(p[i],p[start]))
			start = i;
	ch[0] = p[start];
	for(ns = start,i = 1;;i++)
	{
		int temp = 0;
		for(j = 0;j < n;j++)
		{
			int x1 = p[temp].x - p[ns].x,y1 = p[temp].y - p[ns].y;
			int x2 = p[j].x - p[ns].x,y2 = p[j].y - p[ns].y;
			int c = cross(x1,y1,x2,y2);
			if(c < 0)temp = j;
			if(c == 0 && x1*x1 + y1*y1 < x2*x2 + y2*y2)temp = j;
		}
		if(temp == start)
		{
			l = i;
			break;
		}
		ch[i] = p[temp];
		ns = temp;
	}
}
int check(struct point p[],int n,struct point t)
{
	int i,j;
	int x1,y1,x2,y2;
	if(n == 1 && (p[0].x != t.x || p[0].y != t.y)) return 0;
	for(i = 0;i < n;i++)
	{
		j = (i + 1) % n;
		x1 = p[j].x - p[i].x,y1 = p[j].y - p[i].y;
		x2 = t.x - p[i].x,y2 = t.y - p[i].y;
		if(cross(x1,y1,x2,y2) < 0) return 0;
	}
	if(n == 2)
	{
		x1 = p[1].x - t.x,y1 = p[1].y - t.y;
		x2 = p[0].x - t.x,y2 = p[0].y - t.y;
		if(x1*x2 + y1*y2 > 0) return 0;
	}
	return 1;
}
int main()
{
	int lr,lc,m,n,q,i,j,cas = 1;
	while(scanf("%d%d%d",&m,&n,&q) && (m != 0 || n != 0 || q != 0))
	{
		for(i = 0;i < m;i++)
			scanf("%d%d",&cop[i].x,&cop[i].y);	
		ch(cop,m,cch,lc);
		for(i = 0;i < n;i++)
			scanf("%d%d",&rob[i].x,&rob[i].y);
		ch(rob,n,rch,lr);
		for(i = 0;i < q;i++)
			scanf("%d%d",&c[i].x,&c[i].y);
		printf("Data set %d:\n",cas++);
		for(i = 0;i < q;i++)
		{
			if(m >= 3 && check(cch,lc,c[i]) == 1)
				printf("     Citizen at (%d,%d) is safe.\n",c[i].x,c[i].y);
			else if(n >= 3 && check(rch,lr,c[i]) == 1)
				printf("     Citizen at (%d,%d) is robbed.\n",c[i].x,c[i].y);
			else
				printf("     Citizen at (%d,%d) is neither.\n",c[i].x,c[i].y);
		}
		puts("");
	}	
} 
