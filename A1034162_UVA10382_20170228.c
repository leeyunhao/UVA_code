#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int l,w,n;
double wt[10005][2];
int cmp(const void *a,const void *b){
    return ((double*)a)[0]>((double*)b)[0]?1:-1;
}
main(){
    int i,j,count,o,r,p;
    double temp;
    while(scanf("%d",&n)!=EOF){
         scanf("%d %d",&l,&w);
         for(i=0;i<n;i++){
             scanf("%d %d",&o,&r);
             if(2*r<=w){
                i--;n--;
                continue;
             }
             temp=sqrt((double)r*(double)r-(double)w*(double)w/4);
             wt[i][0]=(double)o-temp;
             wt[i][1]=(double)o+temp;
         }
         qsort(wt,n,sizeof(wt[0]),cmp);
         for(i=0,j=-1;i<n&&wt[i][0]<=0;i++){
                if(j==-1||wt[j][1]<wt[i][1])
                   j=i;                       
         }
         i=j;
         if(i==-1){
            printf("-1\n");
            continue;          
         }
         count=1;
         while(i<n){
               if(wt[i][1]>=l)break;
               for(j=i+1,p=0;j<n&&wt[j][0]<=wt[i][1];j++){
                   if(wt[j][1]>wt[i][1]){
                      if(p==0||wt[j][1]>wt[p][1])
                         p=j;
                   }
               }
               if(p==0)break;
               i=p;
               count++;
         }
         if(wt[i][1]>=l)printf("%d\n",count);
         else printf("-1\n");                                     
    }         
}
