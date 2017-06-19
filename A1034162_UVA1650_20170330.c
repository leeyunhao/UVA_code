#include<stdio.h>
#include<string.h>
#define mod 1000000007
long long int dp[1201][1201];
long long int ans[1201][1201];
main()
{
	char s[1005];
	int i,j,k,l;
	
	while(gets(s)!=NULL)
	{	
		l=strlen(s);
		for(i=0;i<=l+2;i++)
			for(j=0;j<=l+2;j++)
				dp[i][j]=0,ans[i][j]=0;
		for(ans[0][1]=1,ans[0][0]=0,ans[0][2]=1,i=1;i<=l;i++)
		{
			for(j=1;j<=i+1;j++)
			{
				if(s[l-i]=='I')
				{
					dp[i][j]=(ans[i-1][i]-ans[i-1][j-1])%mod;
				}
				if(s[l-i]=='D')
				{
					dp[i][j]=ans[i-1][j-1]%mod;
				}
				if(s[l-i]=='?')
				{
					dp[i][j]=ans[i-1][i]%mod;
				}
				ans[i][j]=(ans[i][j-1]+dp[i][j]%mod);
			}
			ans[i][i+2]=ans[i][i+1]%mod;
		}
		printf("%lld\n",ans[l][l+1]%mod);
	}	
} 
