#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;

int n,m;
int mp[205];
int num[10005],dp[10005];//代表i之前的最长子序列
 

int main(){
	scanf("%d", &n);//读取题目中出现所有颜色的个数，用不到 
	scanf("%d", &n);
	int maxx = -1;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d", &a);
		mp[a] = i;
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &num[i]);
		if(mp[num[i]]){//i这种颜色存在在喜欢颜色序列中 
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(mp[num[i]]==0)continue;//j这种颜色存在在喜欢颜色序列中
				// i颜色的喜爱顺序大于等于j
				if(mp[num[i]]>=mp[num[j]])
					dp[i]= max(dp[i],dp[j]+1);
			}
		}
		//max的速度会比if更快
		maxx = max(maxx,dp[i]);
	}
	printf("%d", maxx);
	return 0;
} 
