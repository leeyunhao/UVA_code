#include<stdio.h>
int mm(int a,int b){
	if(a>b)return a;
	return b;
}
main(){
	int a[200],b[200],dp[200][200];
	int m,n,i,j,t=1;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m==0&&n==0)break;
		for(i=0;i<m;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++)scanf("%d",&b[i]);
		for(i=0;i<=m;i++)dp[i][0]=0;
		for(i=0;i<=n;i++)dp[0][i]=0;
		
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=mm(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("Twin Towers #%d\n",t++);
		printf("Number of Tiles : %d\n\n",dp[m][n]);
	}
}
