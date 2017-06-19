/*輸入一個矩陣，每個元素代表相應位置山的高度，並且只有相鄰的山之間有滑雪軌道，滑雪者只能從較高的山滑向
 較低的山，求最長滑雪路線
    ex：
            input
                    1
                    3   4
                    1 2 3 4
                    10 11 12 5
                    9 8 7 6
            ouput
                    12
 */

#include<stdio.h>
int x[4]={-1,0,1,0},y[4]={0,1,0,-1};
int dp[105][105],map[105][105],lg,r,c;
int max(int a,int b){
    if(a>b)return a;
    else
        return b;
}
int  travel(int i,int j){
    if(i*(r-1-i)<0||j*(c-1-j)<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int p,temp=0;
    for(p=0;p<4;p++){
        if(map[i][j]<=map[i+x[p]][j+y[p]])continue;
        else
            temp=max(temp,travel(i+x[p],j+y[p]));
    }
    dp[i][j]=temp+1;
    lg=max(temp+1,lg);
    return dp[i][j];
}

main(){
    char name[20];
    int i,j,ca;
    scanf("%d\n",&ca);
    while(ca--){
        scanf("%s %d %d\n",name,&r,&c);
        lg=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d",&map[i][j]);
                dp[i][j]=-1;
            }
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                dp[i][j]=travel(i,j);
            }
        }
        printf("%s: %d\n",name,lg);
    }
}
