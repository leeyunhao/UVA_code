#include<stdio.h>
main(){
	int a[1000],max,min,n;
	int i,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		max=a[0],min=a[0];
		for(i=1;i<n;i++){
			if(max<a[i])max=a[i];
			if(min>a[i])min=a[i];
		}
		printf("%d\n",2*(max-min));
	}
} 
