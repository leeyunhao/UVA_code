#include<iostream>
using namespace std;
int skline[10005];
int main()
{
	int x,y,h,i,max = 0,min = 10005;
	for(i = 0;i <= 10005;i++) skline[i] = 0;
	while(scanf("%d%d%d",&x,&h,&y) != EOF)
	{
		for(i = x+1;i <= y;i++)
			if(skline[i] < h)
				skline[i] = h;
		if(y > max)max = y;
		if(x < min)min = x;
	}
	for(i = min;i <= max;i++)
	{
		if(skline[i] != skline[i + 1]){
			printf("%d %d",i,skline[i + 1]);
			if(i < max) printf(" ");
		}
	}
	printf("\n");
	return 0;
}
