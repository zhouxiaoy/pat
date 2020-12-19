#include <iostream>
#include <cstdio>

using namespace std;

const int N=110;
typedef long long LL;
const LL mod=1000000007;
int n,m;
LL dp[N][N][N];

LL s[N][N];//��άǰ׺�� 
int c[N][N];//c[i][j] ��i��j��X�ĸ��� 

void get_prefix_sum(int i){
	for(int j=1;j<=m;j++)
		for(int k=1;k<=m;k++)
			s[j][k] = (s[j-1][k] + s[j][k-1] - s[j-1][k-1] + dp[i][j][k]) % mod;
} 

int get_sum(int x1,int y1,int x2,int y2){
	return (s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]) % mod;
}

int main(){
	cin>>n>>m;
	char str[N];
	for(int i=n;i>0;i--){
		cin>>str+1;
		for(int j=1;j<=m;j++)
			c[i][j] = c[i][j-1]+(str[j]=='X');
	}
	
	//��ʼ��dp����
	dp[0][1][m]=1;
	get_prefix_sum(0);
	
	int res=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				//��ʾ��i�� ��j��k֮��X�ĸ��� 
				if(c[i][k]-c[i][j-1]==0){
					LL &x = dp[i][j][k];
					x = (x + get_sum(i,k,j,m)) % mod; 
					res = (res + x) % mod;
				}
			}
		}
		get_prefix_sum(i);
	}
	cout<<(res+mod)%mod<<endl;
	return 0;
} 
