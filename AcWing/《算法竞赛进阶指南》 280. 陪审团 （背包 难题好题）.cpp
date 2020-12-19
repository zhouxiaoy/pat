#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 210,M = 810, base = 400;
int n,m;
int p[N],d[N];
int f[N][21][M];
int ans[N];

int main(){
	int T = 1;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(int i=1;i<=n;i++)	scanf("%d %d",&p[i],&d[i]);
		
		memset(f,-0x3f,sizeof f);
		f[0][0][base] = 0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				for(int k=0;k<M;k++)
				{
					f[i][j][k] = f[i-1][j][k];
					int t = k - (p[i]-d[i]);
					if(t<0||t>=M)continue;
					if(j<1)continue;
					f[i][j][k] = max(f[i][j][k],f[i-1][j-1][t]+p[i]+d[i]);
				}
			}
		}
		
		int v =0;
		while(f[n][m][base-v]<0&& f[n][m][base+v]<0) v++;
		if(f[n][m][base-v]>f[n][m][base+v]) v = base -v;
		else v = base + v;
		
		int cnt =0;
		int i=n,j=m,k=v;
		while(j)
		{
			if(f[i][j][k] == f[i-1][j][k]) i--;
			else
			{
				ans[cnt++] = i;
				k-=(p[i]-d[i]);
				i--,j--;
			}
		}
		
		int sp = 0,sd=0;
		for(int i=0;i<cnt;i++)
		{
			sp+=p[ans[i]];
			sd+=d[ans[i]];
		}
		
		printf("Jury #%d\n",T++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",sp,sd);
		
		for(int i=0;i < cnt;i++) printf(" %d",ans[i]);
		puts("\n");	
	}
	return 0;
} 


/* 
int dp[25][405][405];//dp[i][j][k][l]表示为在第1-j个物品中选了i个物品，其中控方D总分为k，辩方总分为l
// 状态转移方程：dp[i][j][k][l] = dp[i-1][j-1][k-d[i]][l-p[i]]  //如果|k-l|<|k-d[i]-(l-p[i])|
//               dp[i][j][k][l] = dp[i][j-1][k][l];
// 因为每次都是依赖j-1所以删掉这一个维度 即：dp[i][k][l]
int main(){
    int ans=1,m,n;
    int d[25],p[25];
    while(scanf("%d %d",&n,&m),m|n){
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)    scanf("%d %d",&p[i],&d[i]);
        printf("Jury #%d\n",ans++);
        
        dp[0][0][0]=1;
        int minn=999999,sum_d=0,sum_p=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                for(int k=0;k<=i*20;k++){
                    for(int l=0;l<=i*20;l++){
                            if(k-d[i]>=0&&l-p[i]>=0)
                            dp[i][k][l]=dp[i-1][k-d[i]][l-p[i]];
                            if(i==m&&dp[i][k][l]==1){
                                if(abs(k-l)<minn){
                                    minn=k-l;
                                    sum_d=k;
                                    sum_p=l;
                                }else if(abs(k-l)==minn&&k+l>sum_d+sum_p){
                                    minn=k-l;
                                    sum_d=k;
                                    sum_p=l;
                                }
                            }
                    }
                }
            }
        }
        printf("Best jury has value %d for prosecution and value %d for defence:\n",sum_d,sum_p);
    }
    return 0;
}
*/ 
