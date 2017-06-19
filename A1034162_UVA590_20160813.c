/*輸入城市數n，天數k，接下來是飛機從第j市到其他n-1市的行程
d，a1,a2,..,ad代表第1,2，。。，d天的費用是ai元。求出在第k天到達n市的最小花費。 
ex：
input	3 6
		2 130 150（代表從1到2） 
		3 75 0 80（從1到3） 
		7 120 110 0 100 110 120 0（2到1） 
		4 60 70 60 50（2到3） 
		3 0 135 140（3到1） 
		2 70 80（3到2） 

ouput	Scenario #1
		The best flight costs 460.
*/
#include<stdio.h>
int m(int a,int b){
	if(a>b)return b;
	else
		return a;
}
main(){
	int dp[1005][20],v[35][20][20],p[15][15];
	int n,k,i,j,h,key,ca=1;
	while(scanf("%d %d",&n,&k)!=EOF&&n+k!=0){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j)
					continue;
				scanf("%d",&p[i][j]);
				for(h=1;h<=p[i][j];h++){
					scanf("%d",&v[h][i][j]);
					if(v[h][i][j]==0)
						v[h][i][j]=1000000000;
				}
			}
		}
		for(i=0;i<=n+2;i++){
			dp[0][i]=0;
			for(j=0;j<k+2;j++)		    
				dp[j][i]=1000000000;
		}
		for(i=1;i<=k;i++){
			for(j=1;j<=n;j++){
				if(i==1&&j!=1)
					dp[i][j]=v[1][1][j];
				else
					for(h=1;h<=n;h++){
						if(j==h)
							continue;
						if(i%p[h][j]==0)
							key=p[h][j];
						else
							key=i%p[h][j];
						dp[i][j]=m(dp[i][j],dp[i-1][h]+v[key][h][j]);
					}
			}
		}
		if(dp[k][n]<1000000000)
			printf("Scenario #%d\nThe best flight costs %d.\n\n",ca++,dp[k][n]);
		else
			printf("Scenario #%d\nNo flight possible.\n\n",ca++);
	}
}
