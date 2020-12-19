#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> v;
bool vis[10005];
set<int> s;
vector<int> temp;
int maxheight = 0,n;

void dfs(int node, int height) {
	if (height > maxheight) {
		temp.clear();
		temp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight)
		temp.push_back(node);

	vis[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (vis[v[node][i]] == false)
			dfs(v[node][i], height + 1);
	}
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			dfs(i, 1);
			if (i == 1) {
				if (temp.size() != 0) s1 = temp[0];
				for (int j = 0; j < temp.size(); j++)
					s.insert(temp[j]);
			}
			cnt++;
		}
	}

	if(cnt>=2)
		printf("Error: %d components", cnt);
	else {
		temp.clear();
		maxheight = 0;
		fill(vis, vis + 10005, false);
		dfs(s1, 1);
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}

//自己的错误版本
 
/*
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
int maxlength = 0;
int e[10005][10005], deep[10005];
bool vis[10005];

void bfs(int n) {
	queue<int> q;
	q.push(n);
	while (q.size()) {
		int t = q.front();
		q.pop();
		int size = q.size(), length = 1;
		for (int j = 0; j < size; j++) {
			for (int i = 1; j <= n; i++) {
				if (vis[i] == false && e[t][i] == 1) {
					vis[i] = true;
					deep[i] = length;
					q.push(i);
				}
			}
			length++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			vis[i] = true;
			bfs(i);
			int flag = 1;
			for (int j = 1; j <= n; j++) {
				if (vis[j] == false) {
					flag = 0;
				}
			}
			if (flag == 0)ans++;
		}
	}
	cout << "ans:" << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << deep[i] << ' ';
	}
	return 0;
}
*/
