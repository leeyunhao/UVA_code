#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int a,b;
	double l;
}e[250003];
bool cmp(edge a,edge b)
{
	return a.l<b.l;
}
int f[600];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool Union(int x,int y)
{
	int f1=find(x);
	int f2=find(y);
	if(f1==f2)return false;
	f[f2]=f1;
	return true;
}
double kruskal(int v,int ne,int s)
{
	int i,j;
	for(i=0;i<v;i++)
		f[i]=i;
	sort(e,e+ne,cmp);
	for(i=0,j=0;i<ne&&j<v-1;i++)
	{
		if(Union(e[i].a,e[i].b))
		{
			j++;
			if(j==v-s)
				return e[i].l;
		}
	}
}
int main()
{
	int cas,s,v,ne;
	double ans;
	int i,j,p[600][2]; 
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&s,&v);
		for(i=0;i<v;i++)
			scanf("%d%d",&p[i][0],&p[i][1]);
		
		for(ne=0,i=0;i<v-1;i++)
			for(j=i+1;j<v;j++)
			{
				e[ne].a=i;e[ne].b=j;
				e[ne].l=sqrt((double)((p[i][0]-p[j][0])*(p[i][0]-p[j][0])
						+(p[i][1]-p[j][1])*(p[i][1]-p[j][1])));
				ne++;
			}
		ans=kruskal(v,ne,s);
		printf("%.2lf\n",ans);
	}
	return 0;	
}
