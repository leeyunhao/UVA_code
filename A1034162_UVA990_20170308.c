#include<stdio.h>
int v[1000],d[1000],dp[60][1005],trace[40],t,w,n,num;
int mx(int a,int b){
	if(a>b)return a;
	return b;
}
main(){
	int i,j,k,ca=0;
	while(scanf("%d%d",&t,&w)!=EOF){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&d[i],&v[i]);
			d[i]*=3*w;
		}
		for(i=0;i<=n;i++)
			for(j=0;j<=t;j++)
				dp[i][j]=0;
		for(i=d[0];i<=t;i++)
			dp[0][i]=v[0];
		for(i=1;i<n;i++){
			for(j=0;j<=t;j++){
				if(j>=d[i])
					dp[i][j]=mx(dp[i-1][j],dp[i-1][j-d[i]]+v[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		for(j=0,k=t,i=n-1;i>=0;i--)
			if(dp[i][k]!=dp[i-1][k]){
				trace[j++]=i;
				k-=d[i];
			}
		if(ca++!=0)puts("");
		printf("%d\n",dp[n-1][t]);
		printf("%d\n",j);
		for(i=j-1;i>=0;i--)
			printf("%d %d\n",d[trace[i]]/(3*w),v[trace[i]]);
	}
}