#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct pts
{
    int x,y;
}p[1000],ch[1000],st;
int cross(int x1,int y1,int x2,int y2)
{
    return x1 * y2 - x2 * y1;
}
bool cmp(struct pts a,struct pts b)
{
    int x1 = a.x - st.x,y1 = a.y - st.y;
    int x2 = b.x - st.x,y2 = b.y - st.y;
    int c = cross(x1,y1,x2,y2);
    if(c == 0)
        return x1*x1 + y1*y1 < x2*x2 + y2*y2;
    return c > 0;
}
int Graham(struct pts p[],int n)
{
    int i,top,c,x1,y1,x2,y2;
    st = p[0];
    for(i = 1;i < n;i++)
    {
        if(p[i].y < st.y) st = p[i];
        if(p[i].y == st.y && p[i].x < st.x) st = p[i];
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
            if(c>0)break;
        }
        top++;
        ch[top] = p[i];
    }
    return top+1;
}
using namespace std;
int main()
{
	int cas,n,i,j,x1,x2,y1,y2,c,l;
	while(scanf("%d",&cas) != EOF)
	{
		printf("%d\n",cas);
		while(cas--)
		{
			scanf("%d",&n);
			for(i = 0;i < n;i++)
				scanf("%d%d",&p[i].x,&p[i].y);
			if(cas>0)
				scanf("%d",&i);
			l=Graham(p,n-1);
			printf("%d\n",l + 1);
			for(i = 0;i < l;i++)
				printf("%d %d\n",ch[i].x,ch[i].y);
			printf("%d %d\n",ch[0].x,ch[0].y);
			if(cas > 0)
				printf("-1\n");
		}
	}
	return 0;
}
