/*給一根l長度的棍子，要在（x1，x2，。。，xn）處切割，每次切割的花費為切割棍子的長度，求最少花費
 ex：input 100
           3
           25 50 75
     ouput
           The minimum cutting is 200.          //200=100+50+50
 */
#include<stdio.h>
main(){
    int l,n,node[200],dp[200][200];
    int i,j,k;
    while(scanf("%d",&l)!=EOF&&l!=0){
        scanf("%d",&n);
        for(node[0]=0,i=1;i<=n;i++)
            scanf("%d",&node[i]);
        node[n+1]=l;
        for(i=2;i<=n+1;i++){
            for(j=0;j<=n+1-i;j++){
                if(i==2)dp[j][i+j]=node[j+i]-node[j];
                else    for(dp[j][j+i]=-1,k=j+1;k<i+j;k++)
                            if((dp[j][j+i]>dp[j][k]+dp[k][j+i]+node[j+i]-node[j])||dp[j][j+i]==-1)
                                dp[j][j+i]=dp[j][k]+dp[k][j+i]+node[j+i]-node[j];
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
}
