#include<stdio.h>


int max(int a,int b){
    if(a>b)return a;
    else
        return b;
}

main(){
    int box[105][105],dp[105],gmax,sum,n;
    int i,j,k;
    
    while(scanf("%d",&n)!=EOF){
        
        for(i=1;i<=n;i++){
            for(j=0;j<=n;j++){
                if(j==0)box[i][j]=0;
                else{
                    scanf("%d",&box[i][j]);
                    box[i][j]+=box[i][j-1];
                }
            }
        }
        
        gmax=0;
        
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                
                for(k=1;k<=n;k++){
                    dp[k]=box[k][j]-box[k][i-1];
                }
                
                sum=0;
                
                for(k=1;k<=n;k++){
                    sum=max(dp[k],sum+dp[k]);
                    gmax=max(sum,gmax);
                }
            }
        }
        printf("%d\n",gmax);
    }
}