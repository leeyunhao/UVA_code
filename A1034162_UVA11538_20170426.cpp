#include<iostream>
#include<cstdio>
using namespace std;
long long int dp[1000005];
int main()
{
	long long int i;
	dp[1] = 0,dp[0] = 0,dp[2]=2;
	for(i = 3;i <= 1000000;i++)
		dp[i] = dp[i-1] + i*(i-1);
	long long int m,n,temp;
	while(scanf("%lld%lld",&m,&n) != EOF)
	{
		if(m == 0 || n == 0) break;
		if(n > m)
		{
			temp = n;
			n = m;
			m = temp;
		}
		printf("%lld\n",m*n*(n-1) + n*m*(m-1) + 2*(m - n + 1)*n*(n-1) + 4*dp[n-1]);
	}
	return 0;
}
