//难题 
//这种逻辑 我做的不熟练 容易卡死 
//rank 为 小组数+1（1-小组数代表 前 小组数 名）
//其他的都为小组数+1
//所以我们每次选出 各个小组的冠军保存在temp中
//然后将v（保存的是当前参选老鼠）全部赋值为 小组数+1
//当temp冠军里面只有一只时 就是第一名了，跳出循环 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, temp;
int wei[1005], rk[1005];
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &wei[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}

	//排名 
	int rank;
	while (1) {
		int i = 0;
		while (i < v.size()) {
			int maxx = i;
			for (int j = 0; j < m && i < v.size(); j++, i++) {
				if (wei[v[maxx]] < wei[v[i]])
					maxx = i;
			}
			temp.push_back(v[maxx]);
		} 
		rank = temp.size() + 1;
		for (int j = 0; j < v.size(); j++)
			rk[v[j]] = rank;
		if (temp.size() == 1) {
			rk[temp[0]] = 1;
			break;
		}
		v = temp;
		temp.clear();
	}
	printf("%d", rk[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", rk[i]);
	return 0;
}
