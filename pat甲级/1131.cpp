//自己想不出来
//虽然最短路径用queue会更快
//但是要输出路径比较麻烦，所以用dfs会更契合
//难题dfs 

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 10000;
vector<int> v[N];
int vis[N], minCnt, minTransfer, start, endd;
unordered_map<int, int> line;
vector<int>tempPath, path;

int transfer(const vector<int> &a) {
	int cnt = -1, sum = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i - 1] * N + a[i]] != sum) cnt++;
		sum = line[a[i - 1] * N + a[i]];
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (idx == endd) {
		int t = transfer(tempPath);
		if (cnt < minCnt || (cnt == minCnt && t < minTransfer)) {
			path = tempPath;
			minCnt = cnt;
			minTransfer = t;
		}
		return;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		if (vis[v[idx][i]] == 0) {
			vis[v[idx][i]] = 1;
			tempPath.push_back(v[idx][i]);
			dfs(v[idx][i], cnt + 1);
			tempPath.pop_back();
			vis[v[idx][i]] = 0;
		}
	}
}

int main() {
	int n, k, a, b, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			if (j != 0) {
				v[a].push_back(b);
				v[b].push_back(a);
				line[a*N + b] = line[b*N + a] = i;
			}
			b = a;
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &start, &endd);
		minCnt = 99999, minTransfer = 99999;
		tempPath.clear();
		tempPath.push_back(start);
		vis[start] = 1;
		dfs(start, 0);
		vis[start] = 0;
		printf("%d\n", minCnt);
		int preLine = 0, preTransfer = start;
		for (int j = 1; j < path.size(); j++) {
			if (line[path[j - 1] * N + path[j]] != preLine) {
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
				preLine = line[path[j - 1] * N + path[j]];
				preTransfer = path[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, endd);
	}

	return 0;
}
