/*��m�����˷���n���΄գ�ÿ������������ֵpi��1=<i<=m,ÿ�����˹������L�U��
pi/ai,ai�������䵽���΄Ք����������������L�U�����й�������С���L�U���l��ÿ��
��������Ļ��M�����������ֵ��ݔ���΄Ք�n�����˔�m��ÿ�����˵�����ֵ��ݔ����
С���L�U����ݔ����С�L�U�µ���С���M
ex��
	input 2 5
			10 8 6 4 1
	ouput
			8 18 

*/
#include<stdio.h>
int ma(int a,int b){
	if(a>b)
		return a;
	return b;
}

int p[1000];
int num,dp[1000][1000],w,sum;

main(){
		int n,m,i,j,max,min,x;
		
		while(scanf("%d %d",&n,&m)!=EOF)
		{
			if(m==0&&n==0)
				break;
			for(sum=0,max=0,i=0;i<m;i++){
				scanf("%d",&p[i]);
				if(p[i]>max)
					max=p[i];
				sum+=p[i];
			}
			
			for(min=0;min!=max;){
				if(max-min==1)
					x=max;
				else
					x=(max+min)/2;
				for(j=0,i=0;i<m;i++){
					if(p[i]/x>=1)
						j+=p[i]/x;
				}
				if(j>=n)
					min=x;
				else
					max=x-1;
			}
			
			if(max==0)	{
				printf("%d %d\n",0,0);
				continue;
			}

			for(num=0,i=0;i<m;i++)
				num+=p[i]/max;
			w=num-n;
			
			for(i=0;i<=m;i++)
				for(j=0;j<=w;j++){	
					if(i==0)
						dp[i][j]=0;
					else
						if(j<p[i-1]/max)
							dp[i][j]=dp[i-1][j];
						else
							dp[i][j]=ma(dp[i-1][j],dp[i-1][j-p[i-1]/max]+p[i-1]);
				}
			printf("%d %d\n",max,sum-dp[m][w]);
			
		}
}
