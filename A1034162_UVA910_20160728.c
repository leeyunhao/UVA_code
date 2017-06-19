#include<stdio.h>
main(){
	int map[26][2],i,j;
	int n,step,tg;
	char node[10];
	while(scanf("%d\n",&n)!=EOF){
		for(i=0;i<n;i++)
			for(j=0;j<2;j++)
				map[i][j]=0;
		for(i=0;i<n;i++){
			gets(node);
			map[node[0]-'A'][0]=node[2]-'A';
			map[node[0]-'A'][1]=node[4]-'A';
			if(node[6]-'x'==0)
				tg=node[6]-'A';
		}
		scanf("%d\n",%step);
	}
}
