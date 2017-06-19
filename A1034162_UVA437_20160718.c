/*給定磚塊種數n，每種磚塊的長寬高（Xi,Yi,Zi）,並且磚塊可以旋轉，每個磚塊只能疊在長寬都比它小的磚塊上面
 求能疊成最高的塔的高度
    ex: input
                1
                10 20 30
                2
                6 8 10
                5 5 5 
        ouput
                Case 1: maximum height = 40
                Case 2: maximum height = 21
*/

#include<stdio.h>
#include<stdlib.h>

int cmp1(void const *a,void const *b){
    return *(int*)a-*(int*)b;
}
int cmp2(void const *a,void const *b){
    return ((int*)b)[2]-((int*)a)[2];
}
int check(int a[],int b[]){
    if(a[2]>b[2]&&a[1]>b[1])return 1;
    else
        return 0;
}
int dp[1000];
main(){
    int n,i,j,block[100][3],max;
    int ca=1;
    while(scanf("%d",&n)!=EOF&&n!=0){
        for(i=0;i<3*n;i+=3){
            scanf("%d %d %d",&block[i][0],&block[i][1],&block[i][2]);
            qsort(block[i],3,sizeof(int),cmp1);
            block[i+1][0]=block[i][2];
            block[i+1][1]=block[i][0];
            block[i+1][2]=block[i][1];
            block[i+2][0]=block[i][1];
            block[i+2][1]=block[i][0];
            block[i+2][2]=block[i][2];
        }
        qsort(block,3*n,sizeof(block[0]),cmp2);
        for(max=1,i=0;i<3*n;i++){
            dp[i]=block[i][0];
            for(j=0;j<i;j++){
                if(check(block[j],block[i])&&dp[j]+block[i][0]>dp[i]){
                    dp[i]=dp[j]+block[i][0];
                }
            }
            if(max<dp[i])max=dp[i];
        }
        printf("Case %d: maximum height = %d\n",ca++,max);
    }
}
