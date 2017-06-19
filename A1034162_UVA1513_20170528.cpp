#include<iostream>
using namespace std;
int tree[650000],pos[150000];
void build(int l,int r,int i)
{
	tree[i] = 0;
	if(l == r)
		return;
	build(l,(l+r)/2,2*i+1);
	build((l+r)/2+1,r,2*i+2);
}
void insert(int v,int p,int l,int r,int i)
{
	tree[i] += v;
	if(l == r)
		return;
	int mid = (l+r)/2;
	if(mid >= p)
		insert(v,p,l,mid,2*i+1);
	else
		insert(v,p,mid+1,r,2*i+2);
}
int qes(int l1,int r1,int l,int r,int i)
{
	if(l1 > r1) 
		return 0;
	if(l1 == l && r1 == r) 
		return tree[i];
	int mid =(l + r)/2;
	if(mid >= r1)
	 	return qes(l1,r1,l,mid,2*i+1);
	else if(mid + 1 <= l1)
   		return qes(l1,r1,mid+1,r,2*i+2);
	else if(l <= l1 && r >= r1)
		return qes(l1,mid,l,mid,2*i+1) + qes(mid + 1,r1,mid+1,r,2*i+2);	
} 
int main()
{
	int n,m,t,top,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		build(0,m+n+5,0);
		for(int i = 0;i < n;i++)
			pos[i] = n - 1 - i;
		for(int i = 0;i < n;i++)
			insert(1,i,0,m+n+5,0);
		top = n - 1; 
		for(int i = 0;i < m;i++)
		{
			scanf("%d",&q);
			q--;
			if(i > 0) 
				printf(" ");
			printf("%d",qes(pos[q] + 1,top,0,m+n+5,0));
			insert(-1,pos[q],0,m+n+5,0);
			insert(1,top+1,0,m+n+5,0);
			pos[q] = top + 1;
			top++;
		}
		printf("\n");
	}
	return 0;	
} 
