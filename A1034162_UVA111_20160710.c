/*讀入第一個正確的任務順序，之後輸入的是學生安排的順序，求每個學生安排的順序中
 正確順序任務的個數
    ex：
            input
                    10
                    3 1 2 4 9 5 10 6 8 7
                    1 2 3 4 5 6 7 8 9 10
                    4 7 2 3 10 6 9 1 5 8
                    3 1 2 4 9 5 10 6 8 7
                    2 10 1 3 8 4 9 5 7 6
            ouput
                    6
                    5
                    10
                    9
*/

#include<stdio.h>
int dp[200][200];
int lcs(int m,int n,int a[],int b[]){
        int i,j,k;
        for(i=0;i<=m;i++)dp[i][0]=0;
        for(i=0;i<=n;i++)dp[0][i]=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(a[i]==b[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else    if(dp[i][j+1]>=dp[i+1][j])
                        dp[i+1][j+1]=dp[i][j+1];
                else
                    dp[i+1][j+1]=dp[i+1][j];
            }
        }
    return(dp[m][n]);
}
main()
{
    int a[30],b[30];
    int n,i,x;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[x-1]=i+1;
    }
    while(scanf("%d",&x)!=EOF){
        b[x-1]=1;
        for(i=1;i<n;i++){
            scanf("%d",&x);
            b[x-1]=i+1;
        }
        printf("%d\n",lcs(n,n,a,b));
    }
}
