#include<iostream>
#include<string.h>
using namespace std;
int graph[26][26],mark[26],num,flag;
char c1,c2,s[100];
void print(int n)
{
	int i,j;
	if(n == num + 1)
	{
		printf("%c",s[0]);
		for(i = 1;i < num;i++)
			printf("%c",s[i]); 
		printf("\n");
		return;
	}
	for(i = 0;i < 26;i++)
	{
		if(mark[i] == 0)
		{
			flag = 1;
			s[n - 1] = 'a' + i;
			mark[i]--;
			for(j = 0;j < 26;j++)
				if(graph[i][j] == 1) 
					mark[j]--;
			print(n + 1);
			mark[i]++;
			for(j = 0;j < 26;j++)
				if(graph[i][j] == 1) 
					mark[j]++;
		}
	}
	//if(n == 1 && flag == 0) printf("NO\n");
}
int main()
{
	int cas = 0,i,j;
	while(gets(s) != NULL)
	{
		num = 0;
		for(i = 0;i < 26;i++)
		{
			for(j = 0;j < 26;j++)
				graph[i][j] = 0;
			mark[i] = -1;
		}
		for(i = 0;s[i] != '\0';i++)
		{
			if(s[i] >= 'a' &&s[i] <= 'z')
				mark[s[i] - 'a'] = 0,num++;
		}
		gets(s);
		for(i = 0,j = 2;;)
		{
			if(j >= strlen(s)) break;
			if(graph[s[i] - 'a'][s[j] - 'a'] == 0) mark[s[j] - 'a']++;
			graph[s[i] - 'a'][s[j] - 'a'] = 1;
			i = j + 2;j = j + 4; 
		}
		flag = 0;
		if(cas++ > 0)
			printf("\n");
		print(1);
		
	}
	return 0;
}
