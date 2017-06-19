/*輸入總時間t，cd個數n，以及每個cd時間，輸出cd的組合使總時間與t最接近
    ex: input
                5 3 1 3 4 

        ouput
                1 4 sum：5
*/

#include<stdio.h>

main(){
    int t,n,cd[22],dp[2001];
    int i,j;
    
    while(scanf("%d %d",&t,&n)!=EOF){
        for(i=0;i<n;i++)
           scanf("%d",&cd[i]);
        for(i=0;i<=t;i++)
            dp[i]=-1;
        for(i=n-1;i>=0;i--){
            for(j=t;j>cd[i];j--){
                if(dp[j-cd[i]]!=-1&&dp[j]==-1){
                    dp[j]=cd[i];
                }
            }
            dp[cd[i]]=cd[i];
        }
        for(;dp[t]==-1;t--);
        for(i=t;dp[i]!=-1;){
            printf("%d ",dp[i]);
            i-=dp[i];
        }
        printf("sum:%d\n",t);
    }
 
}
