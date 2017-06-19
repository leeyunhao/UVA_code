#include<stdio.h>

main(){

       int m,n;
	   int a[200][200],b[200][200],c[200][200];

	   int i,j;
	   int x,y,x1,y1,t,d;

	   while(scanf("%d %d",&m,&n)!=EOF){
		   for(i=0;i<m;i++){
			   for(j=0;j<n;j++){		   
			   scanf("%d",&a[i][j]);
			   }
		   }
		   for(i=0;i<m;i++){
		   b[i][n-1]=a[i][n-1];
		   }

		   for(i=n-2;i>=0;i--){
			    for(j=0;j<m;j++){
			         x=j;
				     y=i+1;
				     x1=j+1;
				     if(x1>=m)x1=0;
				     if(b[x1][y]<b[x][y]||(b[x1][y]==b[x][y]&&x1<x)){
					     x=x1;
					 }
				       x1=j-1;
			           if(x1<0)x1=m-1;
                       if(b[x1][y]<b[x][y]||(b[x1][y]==b[x][y]&&x1<x)){
					        x=x1;
					   }
			           b[j][i]=a[j][i]+b[x][y];
					   c[j][i]=x;
			   }
			   
			   }
                t=b[0][0];
				d=0;
				for(i=1;i<m;i++){
					if(t>b[i][0]){
						t=b[i][0];
						d=i;
					}
				}
				printf("%d",d+1);
				for(i=0;i<n-1;i++){
					d=c[d][i];
					printf(" %d",d+1);
				}
				printf("\n");
				printf("%d\n",t);

		   }
 
 }


