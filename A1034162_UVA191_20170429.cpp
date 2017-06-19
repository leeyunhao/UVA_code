#include<iostream>
#include<cstdio>
using namespace std;
struct pts
{
	int  x,y;
};
int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2 - x2*y1;
}
int main()
{
	int cas,i,j,mark,x1,x2,y1,y2;
	pts l[2],r1,r2,r[4];
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d%d%d%d%d%d%d",&l[0].x,&l[0].y,&l[1].x,&l[1].y,&r1.x,&r1.y,&r2.x,&r2.y);
		r[0] = r1,r[1].x = r1.x,r[1].y = r2.y;
		r[2] = r2,r[3].x = r2.x,r[3].y = r1.y;
		mark = 0;
		x1 = min(r1.x,r2.x),x2 = max(r1.x,r2.x);
		y1 = min(r1.y,r2.y),y2 = max(r1.y,r2.y);
		if(l[0].x != l[1].x || l[0].y != l[1].y)
		{
			if(l[0].x == l[1].x)
			{
				if(l[0].x >= x1 && l[0].x <= x2)
				{
					if(max(l[1].y,l[0].y) < min(r1.y,r2.y) || min(l[1].y,l[0].y) > max(r1.y,r2.y))
						printf("F\n");
					else
						printf("T\n");
				}
				else
					printf("F\n");
				continue;
			}
			if(l[0].y == l[1].y)
			{
				if(l[0].y >= y1 && l[0].y <= y2)
				{
					if(max(l[1].x,l[0].x) < min(r1.x,r2.x) || min(l[1].x,l[0].x) > max(r1.x,r2.x))
						printf("F\n");
					else
						printf("T\n");
				}
				else
					printf("F\n");
				continue;
			}
			for(i = 0;i < 4;i++)
			{
				int c1 = cross(l[0].x - l[1].x,l[0].y - l[1].y,r[i].x - l[1].x,r[i].y - l[1].y) 
					* cross(l[0].x - l[1].x,l[0].y - l[1].y,r[(i+1)%4].x - l[1].x,r[(i+1)%4].y - l[1].y);
				int c2 = cross(r[i].x - r[(i+1)%4].x,r[i].y - r[(i+1)%4].y,l[0].x - r[(i+1)%4].x,l[0].y - r[(i+1)%4].y) 
					* cross(r[i].x - r[(i+1)%4].x,r[i].y - r[(i+1)%4].y,l[1].x - r[(i+1)%4].x,l[1].y - r[(i+1)%4].y);
				if(c1 <= 0 && c2 <= 0)
				{
					mark = 1;
					break;
				}
			}
			if(mark == 1)
			{
				printf("T\n");
				continue;
			}
		}
		if(l[0].x < x1 || l[0].x > x2 || l[0].y < y1 || l[0].y > y2)
		{
			printf("F\n");
			continue;
		}
		else printf("T\n");
	}
	return 0;
}
