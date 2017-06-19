#include<stdio.h>//輸入兩個數，輸出他們的積//
#include<string.h>

main(){
      
       char x[300],y[300];
	   int i,j,k,l1,l2;
       int ans[600];
	   while(scanf("%s %s",x,y)==2){
             
			 l1=strlen(x);
	         l2=strlen(y);
			 if(x[0]=='0'||y[0]=='0'){
			 printf("0\n");
			 continue;
			 }
			 for(i=0;i<600;i++)ans[i]=0;

			 for(i=l1-1;i>=0;i--){
				 for(j=l2-1;j>=0;j--){
				     ans[l1+l2-2-i-j]+=(x[i]-'0')*(y[j]-'0');
					 for(k=0;ans[l1+l2-2-i-j+k]>=10;k++){
					     ans[l1+l2-2-i-j+k+1]+=ans[l1+l2-2-i-j+k]/10;
						 ans[l1+l2-2-i-j+k]=ans[l1+l2-2-i-j+k]%10;
					 }
				 }
			 
			 }

			 for(i=599;ans[i]==0;i--);
			 for(;i>=0;i--)printf("%d",ans[i]);
			 printf("\n");
	   
	   }


}