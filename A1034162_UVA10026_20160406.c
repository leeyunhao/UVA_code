#include<stdio.h>//��J����ƶqt�A���ȼƶqn�A�H�ΨC�ӥ��Ȫ�O�ɶ�a�A���~��Os�A��X�̨Υ��ȱƦC
#include<math.h>//�Ϸl���̤p

main(){

       int t,i,j,n,k,c=1;
	   double x[1005][2],y[1005];


	   scanf("%d",&t);
	   while(c<=t){
	       scanf("%d",&n);  
		   for(i=0;i<n;i++){
		       scanf("%lf %lf",&x[i][0],&x[i][1]);
		       y[i]=x[i][1]/x[i][0];
		   }
	       
		   for(i=0;i<n;i++){
			   if(i>0)printf(" ");
		       k=0;
			   for(j=0;j<n;j++){
			      if(y[k]<y[j])k=j;
			   }
			   if(y[k]!=0)printf("%d",k+1);
		       y[k]=0;
		   }
		   if(c!=t)printf("\n\n");
		   c++;
	   }
       printf("\n");
}