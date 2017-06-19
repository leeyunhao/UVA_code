/*輸入一張地圖，#代表墻，F代表火，J代表john，火焰
每分鐘向四個方向蔓延，都輸出John的最段逃生時間
ex：	
input	
		2
		4 4
		####
		#JF#
		#..#
		#..#
		3 3
		###
		#J.
		#.F
ouput
		3
		IMPOSSIBLE 
*/
#include<stdio.h>
int	queuej[1000000][2],s,e;
int	queuef[1000000][2],sf,ef;
int	mark[1005][1005],path[1000000],fire[1005][1005];
char maze[1005][1005];
int	move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void init(){
	int	i,j;
	for(i=0;i<1005;i++)
		for(j=0;j<1005;j++){
			mark[i][j]=0;
			fire[i][j]=-1;
		}
	s=0;e=0;
	path[s]=0;
	sf=0;ef=0;
}
void bfsf(int r,int c){
	int i,x,y;
	while(sf<ef){
		for(i=0;i<4;i++){
			x=queuef[sf][0]+move[i][0];y=queuef[sf][1]+move[i][1];
			if(x<0||x>=r||y<0||y>=c)
				continue;
			if(fire[x][y]==-1&&maze[x][y]!='#'){
				queuef[ef][0]=x;queuef[ef][1]=y;
				fire[x][y]=fire[queuef[sf][0]][queuef[sf][1]]+1;
				ef++;
			}
		}
		sf++;
	}
}
int bfsj(int r,int c){
	int i,x,y;
	while(s<e){
		if(queuej[s][0]<0||queuej[s][0]>=r||queuej[s][1]<0||queuej[s][1]>=c)
			return path[s];
		for(i=0;i<4;i++){
			x=queuej[s][0]+move[i][0];y=queuej[s][1]+move[i][1];
			if(x<0||x>=r||y<0||y>=c)
				return path[s]+1;
			if(mark[x][y]==0&&maze[x][y]!='#'&&(fire[x][y]>path[s]+1||fire[x][y]==-1)){
				queuej[e][0]=x;queuej[e][1]=y;
				path[e]=path[s]+1;
				mark[x][y]=1;
				e++;
			}
		}
		s++;
	}
	return -1;
}
main(){
	int t,c,r,ans;
	scanf("%d\n",&t);
	while(t--){
		int i,j;
		scanf("%d %d\n",&r,&c);
		for(i=0;i<r;i++)
			gets(maze[i]);
		init();
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(maze[i][j]=='J'){
					queuej[e][0]=i;
					queuej[e][1]=j;
					mark[i][j]=1;
					e++;
				}
				else	if(maze[i][j]=='F'){
							queuef[ef][0]=i;queuef[ef][1]=j;
							fire[i][j]=0;
							ef++;
						}
			}
		}
		bfsf(r,c);
		ans=bfsj(r,c);
		if(ans==-1)printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ans);
	}
}
