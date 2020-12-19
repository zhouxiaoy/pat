#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < m; i++) {
		int k, flag = 1, num;
		int vec[100005] = { 0 };
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> num;
			if (vec[num] == -1)flag = 0;
			if (flag == 0)continue;
			for(auto u:v[num])
				vec[u] = -1;
		}
		if (!flag)puts("No");
		else	puts("Yes");
	}
	return 0;
}
