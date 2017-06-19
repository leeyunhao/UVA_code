/*共有100，50，20，10，5，2，1，0.5，0.2，0.1，0，05這幾種面額的貨幣，求有幾種方案可以湊出x元*/
#include<stdio.h>
long long int dp[60001]={0};
int wt[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
main(){
    double m;
    int p,q,i,j;
    for(i=0,dp[0]=1;i<11;i++)
        for(j=0;j<=60000-wt[i];j++)
            if(dp[j]!=0)
                dp[j+wt[i]]+=dp[j];
    while(scanf("%lf",&m)&&m!=0.00){
        p=(int)(100*m+0.5);/*進位制轉換時需注意浮點數精度的丟失*/
        printf("%6.2lf%17lld\n",m,dp[p]);
    }
    
   
}
