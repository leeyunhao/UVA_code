#include<stdio.h>
int m[10000],dp[10000],path[10000];
void p(int n){
	if(path[n]!=-1)
		p(path[n]);
	printf("%d\n",m[n]);
}
main(){
	int t,i,j,sum,n,po,max;
	char c[100000];
	scanf("%d\n\n",&t);
	while(t--){
		n=0;
		 while(gets(c)&&c[0]) {
             sscanf(c,"%d",&m[n]);
             n++;
         }
		po=0;
		max=1;
		for(i=0;i<n;i++)
			path[i]=-1;
		for(dp[0]=1,i=1;i<n;i++){
			dp[i]=1;
			for(j=0;j<i;j++){
				if(m[j]<m[i]&&dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					path[i]=j;
				}
			}
			if(dp[i]>max){
				max=dp[i];
				po=i;
			}
		}
		printf("Max hits: %d\n",dp[po]);
		p(po);
		if(t!=0)
			puts("");
	}
}
