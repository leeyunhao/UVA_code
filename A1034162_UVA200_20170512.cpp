#include<iostream>
using namespace std;
int graph[30][30],mark[30],n;
int main()
{
	char s1[10000],s2[10000];
	int i,j,k;
	while(scanf("%s",s1) != EOF)
	{
		for(i = 0;i < 26;i++)
		{
			mark[i] = -1;
			for(j = 0;j < 26;j++)
				graph[i][j] = 0;
		}
		n = 0;
		while(scanf("%s",s2) != EOF)
		{
			if(s2[0] == '#') break;
			for(i = 0;s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0';i++);
			if(s1[i] != '\0' && s2[i] != '\0')
			{
				
				if(mark[s2[i] - 'A'] == -1) mark[s2[i] - 'A'] = 0,n++;
				if(mark[s1[i] - 'A'] == -1) mark[s1[i] - 'A'] = 0,n++;
				if(graph[s1[i] - 'A'][s2[i] - 'A'] == 0)
					mark[s2[i] - 'A'] ++;	
				graph[s1[i] - 'A'][s2[i] - 'A'] = 1;
			}
			for(i = 0;s2[i] != '\0';i++)
				s1[i] = s2[i];
			s1[i] = s2[i];
		}
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < 26 && mark[j] != 0;j++);
			if(j == 26) break;
			printf("%c",'A' + j);
			for(k = 0;k < 26;k++)
				if(graph[j][k] == 1)
					mark[k]--;
			mark[j] = -1;
		}
		puts("");
	}
	return 0;
}
