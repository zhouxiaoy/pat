#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	int n, m;//人数，课程数
	scanf("%d %d", &n, &m);
	vector<vector<string>> v(m+1);
	string str;
	int sum, num;
	for (int i = 0; i < n; i++) {
		cin >> str;
		scanf("%d", &sum);
		for (int j = 0; j < sum; j++) {
			scanf("%d", &num);
			v[num].push_back(str);
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
			printf("%s\n",v[i][j].c_str());
	}
	return 0;
}
