#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int vis[1005][1005];
int num[1005];
//�Ƚϳ�Ĵ���  �ֱ��б��4�����򣬼���ֱ������Ϊ1
//�����ǽ������򣬻ʺ���Ϊ2��
//����ʺ���ڽ�����Χ�ڣ��򷵻�false 
bool dfs(int i, int n) {
	if (vis[i][num[i]] == 1)
		return false;
	vis[i][num[i]] = 2;
	for (int j = 0; j < n; j++) {	
		if (i + j +1< n) //����� 
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
//�ȽϺõĴ���
//�Ƚ��Ƿ���ͬһ��  v[j] == v[t]
//�Ƚ��Ƿ��ڶԽ�����  abs(v[j]-v[t]) == abs(j-t)�ɱ��� 
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
