#include<stdio.h>
struct node
{
	int x,y;
	int t,d;
}queue[30000];
int move[4][2]={0,-1,-1,0,0,1,1,0};
int dgraph[100][100][4],graph[100][100],l,r,m,n;;
int check(int x,int y)
{
	if(x<0||x>=m||y<0||y>=n)return -1;
	if(graph[x][y]==1)return -1;
	if(y<n-1&&graph[x][y+1]==1)return -1;
	if(x<m-1&&graph[x+1][y]==1)return -1;
	if(x<m-1&&y<n-1&&graph[x+1][y+1]==1)return -1;
	return 1;
}
int bfs(struct node s,struct node e)
{
	int i,k,a,b;
	l=0;r=1;
	queue[l]=s;
	while(l<r)
	{
		if(queue[l].x==e.x&&queue[l].y==e.y)
			return queue[l].t; 
		if(queue[l].x==m-1||queue[l].y==n-1)
		{
			l++;
			continue;
		}
		a=queue[l].x;b=queue[l].y;
		k=queue[l].d;
		k+=1;
		if(k>3)k=0;
		if(dgraph[a][b][k]==-1)
		{
			queue[r].x=a;		
			queue[r].y=b;
			queue[r].d=k;
			queue[r].t=queue[l].t+1;
			dgraph[a][b][k]=1;
			r++;
		}
		k=queue[l].d;
		k-=1;
		if(k<0)k=3;
		if(dgraph[a][b][k]==-1)
		{
			queue[r].x=a;		
			queue[r].y=b;
			queue[r].d=k;
			queue[r].t=queue[l].t+1;
			dgraph[a][b][k]=1;
			r++;
		}
		for(i=1;i<=3;i++)
		{
			a=queue[l].x+i*move[queue[l].d][0];
			b=queue[l].y+i*move[queue[l].d][1];
			if(check(a,b)==-1)break;
			if(dgraph[a][b][queue[l].d]==1)continue;
			queue[r].x=a;
			queue[r].y=b;
			queue[r].d=queue[l].d;
			queue[r].t=queue[l].t+1;
			dgraph[queue[r].x][queue[r].y][queue[r].d]=1;
			r++;
		}
		l++;
	}
	return -1;
}
main()
{
	struct node s,e;
	int i,j,k;
	char c[10];
	while(scanf("%d%d",&m,&n)&&(m!=0||n!=0))
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				for(k=0;k<4;k++)
					dgraph[i][j][k]=-1;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&graph[i][j]);
		scanf("%d%d%d%d%s",&s.x,&s.y,&e.x,&e.y,c);
		s.x-=1;s.y-=1;e.x-=1;e.y-=1;
		if(c[0]=='w')s.d=0;
		if(c[0]=='n')s.d=1;
		if(c[0]=='e')s.d=2;
		if(c[0]=='s')s.d=3;
		s.t=0;
		dgraph[s.x][s.y][s.d]=1;
		printf("%d\n",bfs(s,e));
	}
}
