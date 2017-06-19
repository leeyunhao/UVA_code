#include<stdio.h>
main(){
	long long dp1[30][30]={0},dp2[30][30]={0};
	int i,j,k,n,m;
	dp1[1][1]=1;
	dp2[1][1]=1;
	for(i=2;i<=22;i++){
		for(j=1;j<=i;j++){
			for(k=1;k<j;k++)
				dp1[i][j]+=dp2[i-1][k];
			for(k=j+1;k<=i;k++)
				dp2[i][j]+=dp1[i-1][k-1];
		}
	}
	while(scanf("%d %d",&n,&m)!=EOF){
		if(m==1&&n==2)
			printf("%lld\n",1);
		else	
			if(m==1&&n>2)
				printf("%lld\n",dp1[n-1][2]);
		else
			printf("%lld\n",dp1[n][m]);
	}
}
