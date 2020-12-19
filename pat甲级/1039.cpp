#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn =26 * 26 * 26 * 10 + 10;

int getid(char *name) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = 26 * id + (name[i] - 'A');
	}
	id = id*10 + (name[3] - '0');
	return id;
}
vector<int> v[maxn];
//map<int, vector<int>> pa;
int main() {
	int n, k;
	char ch[5];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int idx, sum;

		scanf("%d %d", &idx, &sum);
		for (int j = 0; j < sum; j++) {
			scanf("%s", &ch);
			int name = getid(ch);
			v[name].push_back(idx);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", &ch);
		int name = getid(ch);
		sort(v[name].begin(), v[name].end());
		printf("%s %lu",ch, v[name].size());
		for (int j = 0; j < v[name].size(); j++)
			printf(" %d", v[name][j]);
		printf("\n");
	}
	return 0;
}
