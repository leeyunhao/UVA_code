#include<stdio.h>
int con[35][2],target[35],dp[35][30],way;
void init(){
	int i,j;
	for(i=0;i<30;i++){
		target[i]=0;
		for(j=0;j<30;j++)
			dp[i][j]=0;
	}
	dp[0][0]=1;
	way=0;
}
void budp(int n,int st){
	int i,j;
    for(i=1;i<=st;i++){
    	for(j=0;j<n;j++){
    		if(dp[i-1][j]!=0){
    			dp[i][con[j][0]]+=dp[i-1][j];
    			dp[i][con[j][1]]+=dp[i-1][j];
			}
		}
	}
}
main(){
	int n,i,j,st;
	char pt[10];
	while(scanf("%d\n",&n)!=EOF){
		init();
		for(i=0;i<n;i++){
			gets(pt);
			con[i][0]=pt[2]-'A';
			con[i][1]=pt[4]-'A';
			if(pt[6]=='x')
				target[i]=1;
		}
		scanf("%d",&st);
		budp(n,st);
		for(i=0;i<n;i++){
			way+=target[i]*dp[st][i];
		}
		printf("%d\n",way);
	}
}
