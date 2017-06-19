/*輸入初始座標，目的座標，輸出馬從初始座標到目的座標所需最少步數
ex：
	input
	 	e8 a1
		e2 e4
	ouput
		To get from e8 to a1 takes 5 knight moves.
		To get from e2 to e4 takes 2 knight moves.	*/
#include<stdio.h>
int queue[1005][2],path[1005],s,e;
int mark[10][10];
int mx[8]={1,1,-1,-1,2,2,-2,-2},my[8]={2,-2,2,-2,1,-1,1,-1};
void init(){
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			mark[i][j]=0;
}
int bfs(int c,int d){
	int i,x,y;
	while(s<e){
		if(queue[s][0]==c&&queue[s][1]==d)
			return path[s];
		for(i=0;i<8;i++){
			x=queue[s][0]+mx[i];
			y=queue[s][1]+my[i];
			if(x>=0&&x<8&&y>=1&&y<=8)
				if(mark[x][y]==0){
					queue[e][0]=x;
					queue[e][1]=y;
					mark[x][y]=1;
					path[e]=path[s]+1;
					e++;
				}
		}	
		s++;
	}
	return -1;
}

int main(){
	char qt[100];
	int a,b,c,d,ans;
	while(gets(qt)!=NULL){
		a=qt[0]-'a';b=qt[1]-'0';
		c=qt[3]-'a';d=qt[4]-'0';
		init();
		queue[0][0]=a;queue[0][1]=b;
		path[0]=0;mark[a][b]=1;
		s=0,e=1;
		ans=bfs(c,d);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",qt[0],qt[1],qt[3],qt[4],ans);
	}
}
