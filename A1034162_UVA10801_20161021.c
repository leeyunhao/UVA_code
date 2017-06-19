#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int lft[100][1000],t[100],d[1000],node[1000],ml[1000],mk;
int m(int a,int b){
	if(a<b){
		mk=0;
		return a;
	}
	mk=1;
	return b;
}
int dijkstra(int n,int k){
	int i,j,min,nn,s;
	d[0]=0;ml[0]=0;
	for(s=1;;s++){
		for(min=INT_MAX,nn=-1,i=0;i<=99;i++){
			if(node[i]==0&&min>d[i]){
				min=d[i];
				nn=i;
			}
		}
		if(nn==-1||nn==k)break;
		node[nn]=1;
		for(i=0;i<n;i++){
			if(lft[i][nn]==1){
				for(j=0;j<=99;j++){
					if(lft[i][j]==1&&node[j]==0){
						if(ml[nn]==i||s==1){
							d[j]=m(d[j],d[nn]+abs(j-nn)*t[i]);
						}
						else{
							d[j]=m(d[j],d[nn]+abs(j-nn)*t[i]+60);
						}
						if(mk==1)
							ml[j]=i;
					}
	  			}			
	  		}
	 	}
	}
	return d[k];
}
main(){
	int n,k,i,j;
	int x,ans;
	char c;
	while(scanf("%d %d",&n,&k)!=EOF){
		for(i=0;i<n;i++)
			for(j=0;j<100;j++)
				lft[i][j]=0;
		for(i=0;i<=99;i++){
			d[i]=INT_MAX;
			node[i]=0;
		}
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		for(i=0;i<n;i++)
			while(scanf("%d",&x)){
				lft[i][x]=1;
				scanf("%c",&c);
				if(c=='\n')break;
			}
		ans=dijkstra(n,k);
		if(ans<INT_MAX)
			printf("%d\n",ans);
		else
			printf("IMPOSSIBLE\n");
	}
}
