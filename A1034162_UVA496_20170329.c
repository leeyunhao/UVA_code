#include<stdio.h>
int mark[1000000];
main()
{
	int la,lb,cla,clb,i,j,x;
	char c;
	while(scanf("%d%c",&x,&c)!=EOF)
	{
		for(i=0;i<1000000;i++)mark[i]=0;
		mark[x]++;la=1;
		while(c==' ')
		{
			scanf("%d%c",&x,&c);
			mark[x]++;
			la++;
		}
		c=' ';lb=0;
		while(c==' ')
		{
			scanf("%d%c",&x,&c);
			mark[x]--;
			lb++;
		}
		cla=0;clb=0;
		for(i=0;i<1000000;i++)
		{
			if(mark[i]==1)cla++;
			if(mark[i]==-1)clb++;
		}
		if(cla==0&&clb==0)
			printf("A equals B\n");
		else if(cla==0&&clb>0)
			printf("A is a proper subset of B\n");
		else if(cla>0&&clb==0)
			printf("B is a proper subset of A\n");
		else if(cla==la&&clb==lb)
			printf("A and B are disjoint\n");
		else printf("I'm confused!\n");
	}
}
