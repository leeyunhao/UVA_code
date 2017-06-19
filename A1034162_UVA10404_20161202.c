#include<stdio.h>
int mx(int a,int b){
	if(a>b)return a;
	return b;
}
int dp[1000005],c[20];
int main(){
	int n,m;
	int i,j;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&c[i]);
			dp[0]=0;
		for(i=1;i<=n;i++){
			dp[i]=0;
			for(j=0;j<m;j++){
				if(c[j]>i)continue;
				dp[i]=mx(dp[i],1-dp[i-c[j]]);
			}
		}
		if(dp[n]==0)printf("Ollie wins\n");
		else
			printf("Stan wins\n");
	}
}
