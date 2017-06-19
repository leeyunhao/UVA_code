#include<stdio.h>
#include<stdlib.h>
int max (int a,int b){
	if(a>b)return a;
	return b;
}
int cmp(void const *a,void const *b){
	return *(int*)a-*(int*)b;	
}
main(){
	int n,t,a[2000],i,j,sum;
	int l,r,ca=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		l=0,r=n-1;sum=a[r]-a[l];
		while(l<r){
			if(r-l==2)
				sum+=max(a[r]-a[l+1],a[r-1]-a[l]);
			else{
				sum+=a[r-1]-a[l];
				sum+=a[r]-a[l+1];
			}
			r--;l++;
		}
		printf("Case %d: %d\n",ca++,sum);
	}
}
