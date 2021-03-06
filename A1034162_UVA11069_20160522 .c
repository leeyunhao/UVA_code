/*求{1,..,n}的子集m＝{a1,a2,..,aj}的個數
 其中a2-a1>1,a3-a2>1...
    ex:
            input
                    1
                    2
                    3
                    4
                    5
                    30
            ouput
                    1
                    2
                    2
                    3
                    4
                    4410 
*/
#include<stdio.h>
main(){
    long long int dp[76];
    long long int n,i,step;
    while(scanf("%lld",&n)!=EOF){
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(i=3;i<=n;i++)
            dp[i]=dp[i-2]+dp[i-3];
        step=dp[n]+dp[n-1];
        printf("%lld\n",step);
    }
}
