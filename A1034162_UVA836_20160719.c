/*輸入矩陣，找出其中以由“1“組成最大的矩形面積
 ex:    input   
                100110
                001111
                101110
                101011
                100110
                101011
        ouput   
                6
 */
#include<stdio.h>
#include<string.h>
int m(int a,int b){
    if(a>b)return a;
    else
        return b;
}
main(){
    int ca,i,j,k,l,pmax,gmax,sum=0;
    char box[50][50];
    int map[50][50],dp[50];
    scanf("%d\n",&ca);
    while(ca--){
        i=0;
        while(gets(box[i])&&strlen(box[i]))
            i++;
        l=strlen(box[0]);
        for(i=0;i<l;i++){
            map[i][0]=0;
            for(j=1;j<=l;j++){
                if(box[i][j-1]=='0')map[i][j]=-10000;
                else
                    map[i][j]=1;
                map[i][j]+=map[i][j-1];
            }
        }
        for(gmax=0,i=1;i<=l;i++){
            for(j=i;j<=l;j++){
                pmax=0;
                for(k=0;k<l;k++)
                    dp[k]=map[k][j]-map[k][i-1];
                for(sum=0,k=0;k<l;k++){
                    sum+=dp[k];
                    pmax=m(pmax,sum);
                    sum=m(0,sum);
                }
                gmax=m(gmax,pmax);
            }
        }
        printf("%d\n",gmax);
        if(ca>0)printf("\n");
    }
}

