#include<iostream>
#include<string.h>
using namespace std;
char s[1000];
int main()
{
	int t,i,j,l;
	int x,c,p,mk1,mk2;
	scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		for(i = 0;s[i] != '=';i++);
		for(;s[i] != '\0';i++)
			if(s[i] == '+') s[i] = '-';
			else if(s[i] == '-') s[i] = '+';
			
		mk1 = 1,mk2 = 0,p = 0;	
		x = 0,c = 0;
		if(s[0] == 'x') p = 1;
		l = strlen(s);
		
		for(i = 0;i <= l;i++)
		{
			if(s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '\0')
			{
				if(mk2 == 1)
				{
					if(p == 0 && s[i - 2] != '0') p = 1;
					x += mk1*p;
					p = 0;mk2 = 0;
				}
				else
				{
					c += mk1*p;
					p = 0; 
				}
				if(s[i] == '+') mk1 = 1;
				else if(s[i] == '-') mk1 = -1;
				else if(s[i] == '=') mk1 = -1;
			}
			if(s[i] == 'x') mk2 = 1;
			if(s[i] <= '9' && s[i] >= '0') p = p*10 + s[i] - '0';
		}
		
		if(x == 0)
		{
			if(c == 0) printf("IDENTITY\n");
			else printf("IMPOSSIBLE\n");
		}
		else if(-c/x >= 0) printf("%d\n",-c/x);
		else printf("%d\n",-c/x - 1);
	}
	return 0;
}
