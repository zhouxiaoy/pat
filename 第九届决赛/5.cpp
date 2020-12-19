#include<iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
 
const LL MOD=1000000007;
const int MAX_N=105;
const int MAX_M=105;
int n,m;
int a[MAX_N][MAX_M];
LL dp[MAX_M][MAX_M];
 
int main()
{
	cin>>n>>m;	
	char ch;
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> ch;
			a[i][j] = a[i][j - 1];
			if (ch == 'X')	++a[i][j];
		}
	LL ans=1;
	for(int l=1;l<=m;++l)
		for(int r=m;r>=l;--r)
			if(a[1][r]-a[1][l-1]==0)
				dp[l][r]=1+dp[l][r+1]+dp[l-1][r]-dp[l-1][r+1],++ans;
	for(int i=2;i<=n;++i)
		for(int l=1;l<=m;++l)
			for(int r=m;r>=l;--r)
				if(a[i][r]-a[i][l-1]==0){
					ans=(ans+dp[l][r])%MOD;
					dp[l][r]+=(dp[l][r+1]+dp[l-1][r]-dp[l-1][r+1])%MOD;
				}else	dp[l][r]=0;
	cout<<ans<<endl;
	
	return 0;
}
