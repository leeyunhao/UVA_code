#include<stdio.h>
struct node
{
	int x;
	struct node *l,*r;
}tree[300],queue[300];
int nt,mark;
void push(char s[])
{
	int n,i,j;
	struct node *p;
	p=&tree[0];
	for(n=0,i=1;s[i]!=',';i++)n=10*n+s[i]-'0';
	i++;
	for(;s[i]!=')';i++)
	{
		if(s[i]=='L')
		{
			if(p->l==NULL)p->l=&tree[nt++];
			p=p->l;
		}
		if(s[i]=='R')
		{
			if(p->r==NULL)p->r=&tree[nt++];
			p=p->r;
		}
	}
	if(p->x!=-1)mark=1;
	p->x=n;
}
int main()
{
	char s[1000];
	int i,j,lf,rt;
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;i<300;i++)
		{
			tree[i].l=NULL;tree[i].r=NULL;
			tree[i].x=-1;
		}
		nt=1;mark=0;
		push(s);
		while(scanf("%s",s)!=EOF)
		{
			if(s[0]=='('&&s[1]==')')break;
			push(s);
		}
		if(mark==1)
		{
			printf("not complete\n");
			continue;
		}
		queue[0]=tree[0];
		lf=0;rt=1;
		while(lf<rt)
		{
			if(queue[lf].l!=NULL)
				queue[rt++]=*queue[lf].l;
			if(queue[lf].r!=NULL)
				queue[rt++]=*queue[lf].r;
			lf++;
		}
		for(i=0;i<rt&&queue[i].x!=-1;i++);
		if(i<rt)
		{
			printf("not complete\n");
			continue;
		}
		for(i=0;i<rt;i++)
		{
			printf("%d",queue[i].x);
			if(i<rt-1)printf(" ");
		}
		puts("");
	}
	return 0;
}
