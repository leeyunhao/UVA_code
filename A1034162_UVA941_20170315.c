#include<stdio.h>
#include<string.h>
int cmp(void const *a,void const *b)
{
	return *(char*)a-*(char*)b;
}
main()
{
	long long int dp[21],n,p;
	int i,t,l,ll,mk[22],m,k;
	char s[100],sn[100];
	dp[0]=1;
	for(i=1;i<21;i++)
		dp[i]=dp[i-1]*i;
	scanf("%d",&t);
	gets(s);
	while(t--)
	{
		gets(s);
		scanf("%lld",&n);
		l=strlen(s);
		ll=l;
		for(i=0;i<l;i++)
			mk[i]=0;
		qsort(s,l,sizeof(char),cmp);
		for(i=0;i<l;i++)
		{
			p=n/dp[l-1-i];
			sn[i]=s[p];
			for(k=p;k<ll-1;k++)
				s[k]=s[k+1];
			ll--;
			n%=dp[l-1-i];
		}
		for(i=0;i<l;i++)
			printf("%c",sn[i]);
		puts("");
		gets(s);
	}
}
