#include<iostream>
using namespace std;

const int N = 22;
const int inf = 1000000000;
int dp[N*2][N][N];
bool IsValid(int step,int x1,int x2,int n){
	int v1 = step- x1, y2 = step - x2;
	return ((x1>=0)&&(x1<n) && (x2>=0) &&(x2<n)&&(y1>=0)&&(y1<n)&&(y2>=0)&&(y2<n));
}

int GetValue(int step, int x1,int x2, int n){
	return IsValid(stop,x1,x2,n) ? dp[step][x1][x2]:(-inf);
} 

int minPathSum(int a[N][N],int n){
	int P = n*2 -2;//最终的步数
	int i,j,step;
	
	//不能到达的位置 设置为负无穷大
	for(i =0; i< n;i++){
		for(j=i;j<n;j++){
			dp[0][i][j] = -inf;
		}
	} 
	dp[0][0][0] = a[0][0];
	for(step=1;step<=P;step++){
		for(j=i;j<n;j++){
			dp[step][i][j] = -inf;
			if(!IsValid(step,i,j,n))
				continue;
			if(i!=j){
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i-1,j-1,n));
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i-1,j,n));
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i,j-1,n));
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i,j,n));
				dp[step][i][j] += a[i][step-i] + a[j][step-j];//不在同一个格子，加两个数 
			}
			else{
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i-1,j-1,n));
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i-1,j,n));
				dp[step][i][j] = max(dp[step][i][j],GetValue(step-1,i,j,n));
				dp[step][i][j] += a[i][step-i];//在同一个格子，加一次 
			}
		}
	}
	return dp[P][n-1][n-1]; 
}

int main(){
	
	return 0;
} 
