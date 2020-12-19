#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int vis[1005][1005];
int num[1005];
//比较丑的代码  分别从斜的4个方向，加竖直方向标记为1
//代表是进攻方向，皇后标记为2，
//如果皇后放在进攻范围内，则返回false 
bool dfs(int i, int n) {
	if (vis[i][num[i]] == 1)
		return false;
	vis[i][num[i]] = 2;
	for (int j = 0; j < n; j++) {	
		if (i + j +1< n) //标记列 
			vis[i + j+1][num[i]] = 1;
		if (i + j + 1 < n && num[i] + j + 1 < n) {
			if (vis[i + j + 1][num[i] + j + 1] == 2)
				return false;
			vis[i + j + 1][num[i] + j + 1] = 1;
		}
		if (i - j - 1 >= 0 && num[i] - j - 1 >= 0) {
			if (vis[i - j - 1][num[i] - j - 1] == 2)
				return false;
			vis[i - j - 1][num[i] - j - 1] = 1;
		}

		if (i + j + 1 < n && num[i] - j - 1 >= 0) {
			if (vis[i + j + 1][num[i] - j - 1] == 2)
				return false;
			vis[i + j + 1][num[i] - j - 1] = 1;
		}
		if (i - j - 1 >= 0 && num[i] + j + 1 < n) {
			if (vis[i - j - 1][num[i] + j + 1] == 2)
				return false;
			vis[i - j - 1][num[i] + j + 1] = 1;
		}
	}
	if (i + 1 < n)
		return dfs(i + 1, n);
	else return true;
}

int main() {
	int n, k;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		fill(vis[0], vis[0] + 1005*1005, 0);
		for (int i = 0; i < k; i++) {
			scanf("%d", &num[i]);
			num[i]--;
		}
		if (dfs(0, k) == false)    puts("NO");
		else  	puts("YES");
	}
	return 0;
}
//比较好的代码
//比较是否在同一列  v[j] == v[t]
//比较是否在对角线中  abs(v[j]-v[t]) == abs(j-t)成比例 
/* 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> v(n);
        bool result = true;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            for (int t = 0; t < j; t++) {
                if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
    cout << (result == true ? "YES\n" : "NO\n");
    }
    return 0;
}
*/ 
