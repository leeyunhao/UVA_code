#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int n,k;
	
	while(scanf("%lld%lld",&n,&k))
	{
		if(n == 0 && k == 0)
			break;
		if(n == 1 && k == 1)
		{
			printf("0 1\n");
			continue;
		}
		double a = n,b = k;
		double x,y,h;
		for(h = 1.0;;h += 1.0)
		{
			x = pow(a,1.0/h),y = pow(b,1.0/h);
			if(fabs(x - y - 1) < 0.00000001)
				break;
		}
		long long int hh = (long long int)(h + 0.5),nn = (long long int)(y + 0.5);
		long long int cat,ht,p,q;
		cat = 0,ht = 0;
		p = 1;
		for(int i = 0;i < hh;i++)
			cat += p,p *= nn;
		p = n,q = 1;
		for(int i = 0;i <= hh;i++)
			ht += p*q,p /= (nn + 1),q *= nn;
		printf("%lld %lld\n",cat,ht);
	}
	return 0;	
} 
