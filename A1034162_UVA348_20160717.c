/*輸入一串矩陣的維度，輸出最佳相乘的順序，使得計算過程中用到的乘法最次數最少
 ex： 
        input
                3
                1 5
                5 20
                20 1
        ouput
                Case 1: (A1 x (A2 x A3))
 */

#include<stdio.h>
int s[200][200];
int p[1000],n;

void print(int i,int j){
    if(i==j)
    {
        printf("A%d",i);
    }
    else{
        printf("(");
        print(i,s[i][j]);
        printf(" x ");
        print(s[i][j]+1,j);
        printf(")");
    }
}

void matrix_multi()
{
    
    int dp[200][200];
    int i,j,k,l;

    for(i=0;i<=n;i++)dp[i][i]=0;
        
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            dp[i][j]=-1;
            for(k=i;k<j;k++)
            {
                int q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(dp[i][j]==-1||dp[i][j]>q)
                {
                    s[i][j]=k;
                    dp[i][j]=q;
                }
            }
        }
            
    }
    print(1,n);
    
}

main(){
    int i,x,ca;
    
    for(ca=1;;ca++)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&p[0]);
        
        for(i=1;i<2*n;i++)
        {
            scanf("%d",&x);
            if(i%2!=0)
            {
                p[(i+1)/2]=x;
            }
        }
        printf("Case %d: ",ca);
        matrix_multi();
        puts("");
    }

}
