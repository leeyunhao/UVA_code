/*輸入一串數列，求最長非嚴格遞減子序列
    ex:
            input
                    2 5 5 3 4 1 -1
                    3 4 5 6 4 4 2 1 -1
                    -1
            ouput   
                    Test #1
                     maximum possible interceptions: 4
 
                    Test ＃2
                      maximum possible interceptions: 5
 */
#include<stdio.h>
int lds(int arry[],int n){
    int dp[10001];
    int i,j,lg;
    for(i=0,lg=1;i<n;i++){
        dp[i]=1;
        for(j=0;j<i;j++)
            if(arry[j]>=arry[i]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        if(lg<dp[i])
            lg=dp[i];
    }
    return lg;
}

main(){
    int num[10001],n,ca;
    int i;
    for(ca=1;;ca++){
        scanf("%d",&num[0]);
        if(num[0]==-1)break;
        for(n=1;;n++){
            scanf("%d",&num[n]);
            if(num[n]==-1)
                break;
        }
        if(ca>1)
            puts("");
        printf("Test #%d:\n",ca);
        printf("  maximum possible interceptions: %d\n",lds(num,n));
    }
}
