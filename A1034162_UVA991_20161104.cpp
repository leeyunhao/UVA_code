#include<iostream>
using namespace std;
int main()
{
	int n,i,j,ca=1;
	long long int dp[21][21];
	for(i=0;i<21;i++)
	{
		dp[i][0]=1;
		dp[0][i]=1;
		dp[i][i]=1;
	}
	for(i=1;i<21;i++)
	{
		for(j=1;j<i;j++)
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
	}
	while(cin>>n)
	{
		if(ca++>1)
			cout<<endl;
		cout<<dp[2*n][n]/(n+1)<<endl;
	}
	return 0;
}
