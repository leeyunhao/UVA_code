#include<stdio.h>
int graph[20][20][2],square[20],mark[20][20];
int pp[4][2]={0,0,0,0,-1,0,0,-1},d[4]={1,0,1,0},m[4][2]={1,0,0,1,-1,0,0,-1};
void finds(int gl,int ll,int c,int x,int y){
	if(gl==ll){
		if(c==3){
			square[gl]++;
			return;
		}
		c++;ll=0;
		if(graph[x+pp[c][0]][y+pp[c][1]][d[c]]==1)
			finds(gl,ll+1,c,x+m[c][0],y+m[c][1]);
		return;
	}
	if(graph[x+pp[c][0]][y+pp[c][1]][d[c]]==1)
		finds(gl,ll+1,c,x+m[c][0],y+m[c][1]);

}
main(){
	int i,j,l,n,k,x,y;
	int p=1;
	char d[10];
	while(scanf("%d\n",&n)!=EOF){
		scanf("%d\n",&k);
		for(i=0;i<=20;i++){
			square[i]=0;
			for(j=0;j<=20;j++){
				graph[i][j][0]=0;
				graph[i][j][1]=0;
				mark[i][j]=0;
			}
		}
		for(i=0;i<k;i++){
			gets(d);
			x=d[2]-'0';y=d[4]-'0';
			if(d[0]=='H')
				graph[x][y][0]=1;
			if(d[0]=='V')
			 	graph[y][x][1]=1;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(l=1;l<=n;l++){
					if(mark[i][j]>=l)continue;
					mark[i][j]=l;
					finds(l,0,0,i,j);
				}
			}
		}
		if(p>1)
			printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",p++);
		for(i=1;i<=n&&square[i]==0;i++);
		if(n==1){
			printf("%d square (s) of size %d\n",1,1);
			continue;
		}
		if(i==n+1)
			printf("No completed squares can be found.\n");
		for(i=1;i<=n;i++){
			if(square[i]>0)
				printf("%d square (s) of size %d\n",square[i],i);
		} 
	}
} 
