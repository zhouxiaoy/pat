#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MaxProfit2(const int *prices, int size, int k) {
	//dev 版本太低不支持vector嵌套 
	vector<vector<int>>dp(k + 1, vector<int>(size, 0));
	int j, i;
	int mx;
	for (j = 1; j <= k; j++) {
		mx = dp[j - 1][0] - prices[0];
		for (i = 1; i < size; i++) {
			dp[j][i] = max(dp[j][i - 1], mx + prices[i]);
			mx = max(mx, dp[j - 1][i] - prices[i]);
		}
	}
	return dp[k][size - 1];
}
int main() {
	int a[] = { 7,1,5,3,6,4 };
	cout << MaxProfit2(a, sizeof(a) / sizeof(int), 3);
	return 0;
}
