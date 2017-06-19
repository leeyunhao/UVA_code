#include<stdio.h>
#include<string.h>
int bign(int x[],int lx,int y[],int ly,int z[])
{
     int i,j,l;
     for(i=0;i<lx+ly;i++)
        z[i]=0;
     for(i=0;i<lx;i++)
     {
        for(j=0;j<ly;j++)
        {
           z[i+j]+=x[i]*y[j];
        }
     }
     for(i=0;i<lx+ly;i++)
     {
         z[i+1]+=z[i]/10;
         z[i]%=10;      
     }
     for(l=lx+ly;z[l]==0;l--);
     return l+1;
}
main()
{
      char s[10000];
      int x[10000],y[10000],z[10000];
      int i,j,l,lx,n,e,ee;
      while(scanf("%s %d",s,&n)!=EOF)
      {    
           l=strlen(s);
           for(i=0;i<l&&s[i]!='.';i++);
           if(i<l)
             e=l-1-i;
           else 
             e=0;
           for(i=0;i<l&&s[i]==0;i++);
           for(j=0;i<l;i++,j++)
           {
              if(s[i]=='.')
              {
                j--;
                continue;
              }
              x[j]=s[i]-'0';
           }
           lx=j;
           for(i=0;i<lx;i++)
           {
              y[i]=x[lx-1-i];
           }
           l=1;
           for(i=0;i<1000;i++)z[i]=0;
           z[0]=1;
           for(i=0;i<n;i++)
           {
              l=bign(y,lx,z,l,x);
              for(j=0;j<l;j++)
                 z[j]=x[j];
           }
           e*=n;
           for(ee=0;z[ee]==0;ee++);
           if(e>=l)
           {
              printf(".");
              for(i=l;i<e;i++)printf("0");
              for(i=l-1;i>=ee;i--)
              printf("%d",z[i]);
              puts("");
           }
           else
           {
              for(i=l-1;i>=e;i--)
                 printf("%d",z[i]);
              if(e>0)
              printf(".");
              for(;i>=ee;i--)
                 printf("%d",z[i]);
              puts(""); 
           }
           for(i=0;i<1000;i++)s[i]=' ';
           for(i=0;i<1000;i++)
           {
              x[i]=0;
              y[i]=0;
           }
      }
}
