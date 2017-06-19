/*有k個工人印刷n本書，每本書有頁數：bk[i],工人印書是連續的 
輸出一種印書的分配，使印最多書的工人工作量最小 
ex： input  2
			9 3
			100 200 300 400 500 600 700 800 900
			5 4		
			100 100 100 100 100
	 ouput   100 200 300 400 500 / 600 700 / 800 900
             100 / 100 / 100 / 100 100
*/
#include<stdio.h>
long long int bk[505],mk[505],up,down,sum,x;
main(){
	int	ca,i,j,n,k;
	scanf("%d\n",&ca);
	while(ca--){
		scanf("%d %d\n",&n,&k);
		for(up=0,down=0,i=0;i<n;i++){
			scanf("%lld",&bk[i]);
			if(bk[i]>down)
			down=bk[i];
			up+=bk[i];
		}
		while(up!=down){
			x=(up+down)/2;
			sum=0;
			j=1;
			for(i=0;i<n;i++){
				if(sum+bk[i]>x){
					j++;
					sum=0;
				}
				sum+=bk[i];
			}
		
			if(j>k)
				down=x+1;
			else
				up=x;
		}
		for(i=0;i<=505;i++)
		mk[i]=-1;
		for(sum=0,i=n-1,j=k;i>=0;i--){
			if(sum+bk[i]<=up&&i>=j-1)
				sum+=bk[i];
			else{
				sum=bk[i];
				mk[j--]=i;
			}
		}
		for(i=0,j=2;i<n;i++){
			printf("%lld",bk[i]);
			if(i!=n-1)
			printf(" ");
			if(i==mk[j]){
				printf("/ ");
				j++;
			}
		}
		puts("");
	}	
	}
