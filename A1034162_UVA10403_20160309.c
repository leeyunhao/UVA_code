#include<stdio.h>//��Jm�A�p��ΤG�i��P16�i���ܮ�1���Ӽ�//

main()
{
    int n,m,p,q;
	int a,b,i,j;

	scanf("%d",&n);
	for(;n>=1;n--){
	   scanf("%d",&m);
	   a=0;
	   b=0;
	   p=m;
	   for(;p!=0;p/=2){
	       if(p%2==1)a++;
	   }
       p=m;
	   for(;p!=0;p/=10){
	       q=p%10;
		   for(;q!=0;q/=2){
		       if(q%2==1)b++;
		   }
	   }
	   printf("%d %d\n",a,b);
	
	}


}