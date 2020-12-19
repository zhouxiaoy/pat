//拓扑排序 
#include <iostream>
#include <vector>
using namespace std;
int e[1005];//i的入度为多少
 //bool vis[1005];
int main() {
	int n, m,first=1;
	cin >> n >> m;
	vector<int> v[1005];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		e[b]++;
	}

	int u;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int vis[1005] = { 0 }, flag = 1;
		for (int j = 1; j <= n; j++) {
			cin >> u;
			vis[u] += e[u];
			if (vis[u] > 0) {
				flag = 0;
			}
			for (int k = 0; k < v[u].size(); k++)
				vis[v[u][k]]--;
		}
		if (!flag) {
			if (first) {
				cout << i;
				first = 0;
			}
			else cout << ' ' << i;
		}
	}
	return 0;
}

