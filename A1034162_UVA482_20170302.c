#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int x;
	char s[1000]; 
}nnode[10000];
int cmp(void const *a,void const *b)
{
	return ((struct node*)a)->x-((struct node*)b)->x;
}
main()
{
	int n,i,j,k;
	char c;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;;i++)
		{
			scanf("%d%c",&nnode[i].x,&c);
			if(c=='\n')
				break;
		} 
		k=i+1;
		for(i=0;i<k;i++)
			scanf("%s",nnode[i].s);
		qsort(nnode,k,sizeof(nnode[0]),cmp);
		for(i=0;i<k;i++)
		{
			puts(nnode[i].s);
		}
		if(n>0)
		puts("");
	}
} 
