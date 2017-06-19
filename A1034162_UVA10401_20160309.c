#include<stdio.h>//輸入x，輸出他用Fibonaccimal Base表示的數字//
int ch[100000000];
main()
{  
	int i,j,n,x,e;

	ch[1]=1;
	ch[2]=2;
	for(i=2;;i++){
	   ch[i+1]=ch[i]+ch[i-1];
	   if(ch[i+1]>100000000)break;
	
	}

    e=i;

	scanf("%d",&n);
    
	for(;n>=1;n--){
	   scanf("%d",&x);
	   printf("%d = ",x);

	   for(i=1;i<=e&&ch[i]<=x;i++);
	   i--;
	   for(;i>0;i--){
		   if(ch[i]<=x){
		      printf("1");
			  x-=ch[i];
			  if(x==0&&i==1)break;
		   }
		   else
			   printf("0");
	   
	   }
	   printf(" (fib)\n");
	}


  
}

