/*ݔ����Д�n���씵k���������w�C�ĵ�j�е�����n-1�е��г�
d��a1,a2,..,ad�����1,2��������d����M����aiԪ������ڵ�k�쵽�_n�е���С���M�� 
ex��
input	3 6
		2 130 150�������1��2�� 
		3 75 0 80����1��3�� 
		7 120 110 0 100 110 120 0��2��1�� 
		4 60 70 60 50��2��3�� 
		3 0 135 140��3��1�� 
		2 70 80��3��2�� 

ouput	Scenario #1
		The best flight costs 460.
*/
#include<stdio.h>
int m(int a,int b){
	if(a>b)return b;
	else
		return a;
}
main(){
	int dp[1005][20],v[35][20][20],p[15][15];
	int n,k,i,j,h,key,ca=1;
	while(scanf("%d %d",&n,&k)!=EOF&&n+k!=0){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j)
					continue;
				scanf("%d",&p[i][j]);
				for(h=1;h<=p[i][j];h++){
					scanf("%d",&v[h][i][j]);
					if(v[h][i][j]==0)
						v[h][i][j]=1000000000;
				}
			}
		}
		for(i=0;i<=n+2;i++){
			dp[0][i]=0;
			for(j=0;j<k+2;j++)		    
				dp[j][i]=1000000000;
		}
		for(i=1;i<=k;i++){
			for(j=1;j<=n;j++){
				if(i==1&&j!=1)
					dp[i][j]=v[1][1][j];
				else
					for(h=1;h<=n;h++){
						if(j==h)
							continue;
						if(i%p[h][j]==0)
							key=p[h][j];
						else
							key=i%p[h][j];
						dp[i][j]=m(dp[i][j],dp[i-1][h]+v[key][h][j]);
					}
			}
		}
		if(dp[k][n]<1000000000)
			printf("Scenario #%d\nThe best flight costs %d.\n\n",ca++,dp[k][n]);
		else
			printf("Scenario #%d\nNo flight possible.\n\n",ca++);
	}
}
