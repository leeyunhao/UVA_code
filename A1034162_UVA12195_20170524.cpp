#include<iostream>
using namespace std;
int mark[1000];
int main()
{
	char s[1000];
	int i,p,sum;
	mark['W'] = 64,mark['H'] = 32,mark['Q'] = 16,mark['E'] = 8;
	mark['S'] = 4,mark['T'] = 2,mark['X']  = 1;
	while(gets(s))
	{
		if(s[0] == '*') break;
		sum = 0;p = 0;
		for(i = 1;s[i] != '\0';i++)
		{
			if(s[i] == '/')
			{
				if(p == 64) sum++;
				p = 0;
			}
			else p += mark[s[i]];
		}
		printf("%d\n",sum);
	}
	return 0;
}
