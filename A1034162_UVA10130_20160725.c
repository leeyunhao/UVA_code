/*“d°ü†–î}*/
#include<stdio.h>
int m(int a,int b){
	if(a>b)return a;
	return b;
}
main(){
	int t,n,w[1005],v[1005],g,pw;
	int i,j,k,gmax,dp[200];
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&v[i],&w[i]);
		scanf("%d",&g);
		for(gmax=0,k=0;k<g;k++){
			scanf("%d",&pw);
		    for(i=0;i<pw+5;i++)
		    	dp[i]=0;
			for(i=0;i<n;i++)
				for(j=pw;j>=w[i];j--)
					dp[j]=m(dp[j],dp[j-w[i]]+v[i]);
			gmax+=dp[pw];	
			
		}
		printf("%d\n",gmax);
	}
}
