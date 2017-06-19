/*找到最小的n，使得存在1+-2+-3....+-n=k  */

#include<stdio.h>

main(){

       int t,i,j,n;
   
       scanf("%d",&t);
       
	   while(t--){
	      
		   scanf("%d",&n);

		   if(n<0)n=-n;

		   for(i=2;;i++){
			   if((i+1)*i/2>=n){
			      if(((i+1)*i/2)%2==n%2)break;
			   }
		   }
	       
		   printf("%d\n",i);
		   if(t>0)printf("\n");
	   
	   }
 

}