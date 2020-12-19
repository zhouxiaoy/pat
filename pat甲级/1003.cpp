#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	vector<int> weight(n, 0),num(n, 0),w(n, 0), dis(n, INT_MAX);
	vector<bool> vis(n, false);
	vector<vector<int>> e(n, vector<int>(n, INT_MAX));
	for (int i = 0; i < n; i++)	cin >> weight[i];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
	}
	//�����c1��c1����С��·����Ŀ
	num[c1] = 1;
	//����c1������еľ�Ԯ�ӵ���Ŀ
	w[c1] = weight[c1];
	//�����c1��c1����С·������
	dis[c1] = 0;
	
	for (int i = 0; i < n; i++) {
		int u = -1, minn = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (vis[j]==false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		//�Ҳ�����ͨ�ģ������
		if (u == -1)break;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false&&e[u][v]!=INT_MAX) {
				if(dis[u] + e[u][v] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					num[v] = num[u] + num[v];
					if (w[v] < w[u] + weight[v]) {
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
	cout << num[c2] <<' '<< w[c2];
	return 0;
}
