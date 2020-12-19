#include <iostream>
#include <cstdio>
using namespace std;

int tree[1005];
int num[1005];
int n, isMax = 0,isMin = 0;
//有一些是之前全是最小堆，最后一个不满足，所以必须要两个变量判断是否两种堆都出现过
//全部相同时最小堆 
void dfs(int idx, int k) {

	num[k] = tree[idx];
	//遍历到最大深度，打印
	if (idx * 2 + 1 > n && idx * 2 > n) {
		cout << num[0];
		for (int i = 1; i <= k; i++) {
			if (num[i] >= num[i - 1]  && isMin == 0)
				isMin = 1;
			else if (num[i] < num[i - 1] && isMax == 0)
				isMax = 1;
			cout << ' ' << num[i];
		}
		cout << endl;
		return;
	}
	//有右子树 
	if (idx * 2 + 1 <= n) {
		dfs(idx * 2 + 1, k + 1);
	}
	if (idx * 2 <= n) {
		dfs(idx * 2, k + 1);
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> tree[i];

	dfs(1, 0);
	
	if (isMax ==1 && isMin == 0)
		puts("Max Heap");
	else if ((isMax ==0 && isMin == 1)||n==1)
		puts("Min Heap"); 
	else
		puts("Not Heap");
	return 0;
}
