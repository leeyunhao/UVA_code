#include<stdio.h>
#include<limits.h>
int mi(int a,int b){
	if(a>b)return b;
	return a;
}
int co[6]={1,2,4,10,20,40};
int dp1[1000],dp2[1000],p;
main(){
	int coin[6],i,j,sum,d,ans,k;
	int p1,p2;
		for(i=1;i<=400;i++){
			for(dp1[i]=0,p=i,j=5;j>=0&&p!=0;j--){
				dp1[i]+=p/co[j];
				p%=co[j];
			}
		}
	for(;;){
		for(sum=0,i=0;i<6;i++){
			scanf("%d",&coin[i]);
			sum+=co[i]*coin[i];
		}
		if(sum==0)break;
		scanf("%d.%d",&p1,&p2);
		d=p1*100+p2;
		d/=5;
		for(i=0;i<=sum;i++){
			dp2[i]=-1;
		}
		for(dp2[0]=0,i=5;i>=0;i--){
			for(j=1;j<=coin[i];j++){
				for(k=sum-co[i];k>=0;k--){
					if(dp2[k]>=0&&dp2[k+co[i]]==-1)
						dp2[k+co[i]]=dp2[k]+1;
				}
			}
		}	
		ans=INT_MAX;
		for(i=d;i<=sum;i++){
			if(dp2[i]>=0){
				ans=mi(ans,dp2[i]+dp1[i-d]);
			}
		}
		printf("%3d\n",ans);
	}
}
