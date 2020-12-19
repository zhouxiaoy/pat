#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int e[505][505], cost[505], dis[505], load[505][505], spend[505][505];
bool vis[505];
int pre[505];

int main() {
	memset(dis, 0x3f, sizeof dis);
	memset(cost, 0x3f, sizeof cost);
	memset(e, 0x3f, sizeof e);

	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for (int i = 0; i < m; i++) {
		int a, b, c, d1;
		cin >> a >> b >> c >> d1;
		e[a][b] = e[b][a] = 1;
		load[a][b] = load[b][a] = c;
		spend[a][b] = spend[b][a] = d1;
	}

	dis[s] = 0;
	cost[s] = 0;

	for (int i = 0; i < n; i++) {
		//找到能到达的最小的结点 
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}

		if (u == -1)break;

		vis[u] = true;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && e[u][j] != inf) {
				if (dis[j] > dis[u] + load[u][j]) {
					dis[j] = dis[u] + load[u][j];
					cost[j] = cost[u] + spend[u][j];
					pre[j] = u;
				}
				else if (dis[j] == dis[u] + load[u][j]) {
					//如果相同的话就选花费更小的路 
					if (cost[j] > cost[u] + spend[u][j]) {
						cost[j] = cost[u] + spend[u][j];
						pre[j] = u;
					}
				}
			}
		}
	}
	vector<int> v(1,d);
	int i = d;
	while (pre[i] != 0) {
		v.push_back(pre[i]);
		i = pre[i];
	}
	v.push_back(s);
	for (int i = v.size() - 1; i >= 0; i--)
		printf("%d ", v[i]);
	printf("%d %d", dis[d], cost[d]);
	return 0;
}
