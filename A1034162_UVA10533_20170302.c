#include<stdio.h>
int chart[1000005],t[1000005];
main()
{
	int n,i,j,temp;
	int t1,t2,ans;
	for(i=0;i<=1000000;i++)
	{
		chart[i]=0;
		t[i]=0;
	}
	chart[0]=1;chart[1]=1;chart[2]=0;
	for(i=2;i<=1000;i++)
	{
		if(chart[i]==1)continue;
		for(j=2;i*j<=1000000;j++)
			chart[i*j]=1;	
	}
	for(i=2;i<=1000000;i++)
	{
		if(chart[i]==0)
		{
			for(temp=0,j=i;j!=0;j/=10)
				temp+=j%10;
			if(chart[temp]==0)
			{   
				t[i]+=1;	
			}
		}
		t[i]+=t[i-1];	
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&t1,&t2);
		printf("%d\n",t[t2]-t[t1-1]);
	}
} 
