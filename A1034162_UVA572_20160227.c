#include<stdio.h>
char map[200][200];
int mark[200][200],od,m,n;
void dfs(int x,int y){
	int i,j;
	mark[x][y]=1;
	
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if(x+i<0||x+i>=m||y+j<0||y+j>=n)
				continue;
			if(mark[x+i][y+j]==1)
				continue;
			dfs(x+i,y+j);
		}
	}
}
main(){
		int i,j,i1,j1;
		
		while(scanf("%d %d\n",&m,&n)&&m!=0&&n!=0){
			for(i=0;i<m;i++)
				gets(map[i]);
				
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					if(map[i][j]=='*')
						mark[i][j]=1;
					else
						mark[i][j]=0;
				}
			}
					
			od=0;
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					if(mark[i][j]!=1){
						od++;
						dfs(i,j); 
					}
				}
			}
			printf("%d\n",od);
		}
} 
