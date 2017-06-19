#include<iostream>
using namespace std;
int main()
{
	int t,i,j,n;
	int c[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < 10;i++) c[i] = 0;
		for(i = 1;i <= n;i++)
		{
			j = i;
			while(j != 0)
			{
				c[j%10]++;
				j/=10;	
			}	
		} 
		printf("%d",c[0]);
		for(i = 1;i < 10;i++) printf(" %d",c[i]);
		puts("");
	}
	return 0;	
} 
