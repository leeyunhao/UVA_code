
#include<stdio.h> 
int count[1000001];
int gcd(int a,int b){
	if(a==0||b==0)return a+b;
	if(a>b)return gcd(a%b,b);
	else
		return gcd(b%a,a);
}
int main(){
	int n,num,p,i,j,k;
	int x,y,z;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<=n;i++){
			count[i]=1;
		}	
		num=0;p=0;
		for(i=1;2*i*i+2*i+1<=n;i++){
			for(j=i+1;i*i+j*j<=n;j++){
				if(gcd(i,j)!=1||(i%2==1&&j%2==1))continue;
				x=j*j-i*i;
				y=2*i*j;
				z=i*i+j*j;
				for(k=1;k*z<=n;k++){
					count[k*x]=0;
					count[k*y]=0;
					count[k*z]=0;
				}
				num++;
			}
		}
		for(i=1;i<=n;i++)
			p+=count[i];
		printf("%d %d\n",num,p);
	}
} 
