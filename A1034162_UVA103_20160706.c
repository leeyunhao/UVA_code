/*給盒子的個數及維度，求出最多能套基層盒子，以及給出套法
    ex:
            input
                    5 2
                    3 7
                    8 10
                    5 2
                    9 11
                    21 18
            ouput
                    5
                    3 1 2 4 5
*/
#include<stdio.h>
#include<stdlib.h>
int map[40][40],n;
int cmp1(void const *a,void const *b){
    return *(int*)a-*(int*)b;
}
int cmp2(void const *a,void const *b){
    return ((int*)a)[0]-((int*)b)[0];
}
int cmp3(int* a,int* b){
    int i;
    for(i=0;i<n;i++)
        if(b[i]<=a[i])
            return 0;
    return 1;
}
void ptph(int path[],int gbox){
    if(gbox==-1)return;
    ptph(path,path[gbox]);
    printf("%d ",map[gbox][n]+1);
}
 main(){
     int k,i,j,max,gbox;
     int dp[40],path[40];
     while(scanf("%d %d\n",&k,&n)!=EOF){
         for(i=0;i<k;i++){
             map[i][n]=i;
             for(j=0;j<n;j++)
                 scanf("%d",&map[i][j]);
             qsort(map[i],n,sizeof(int),cmp1);
         }
         qsort(map,k,sizeof(map[0]),cmp2);
         for(i=0;i<k+5;i++)
             path[i]=-1;
        for(max=1,gbox=0,dp[0]=1,i=1;i<k;i++){
            dp[i]=1;
            for(j=0;j<i;j++){
                if(cmp3(map[j],map[i])==1){
                    if(dp[i]<=dp[j]+1){
                        dp[i]=dp[j]+1;
                        path[i]=j;
                    }
                }
            }
            if(max<=dp[i]){
                max=dp[i];
                gbox=i;
            }
        }
        printf("%d\n",max);
        ptph(path,gbox);
        puts("");
    }
}
