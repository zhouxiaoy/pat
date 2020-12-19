#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//只需要计算出每一层深度的总销售量，再分别计算最后相加 
int n, maxdep = -1;
double p, r;
int w[100005],d[100005];//保存每个结点的销售额，每层结点的销售额 
vector<vector<int>> v;

void dfs(int node, int depth) {
	//如果是叶节点则改变该深度的销售量
	if (v[node].size() == 0) {
		d[depth] += w[node];
		maxdep = max(depth, maxdep);//更新最大深度 
		return;
	}
	for (int i = 0; i < v[node].size(); i++) 
		dfs(v[node][i], depth + 1);
}

int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	v.resize(n);
	r = r/100;
	for (int i = 0; i < n; i++) {
		int k,a;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			v[i].push_back(a);
		}
		if (k == 0) 
			scanf("%d", &w[i]);//存储销售量
	}
	dfs(0, 0);
	double ans = 0;
	for (int i = 0; i <= maxdep; i++) {//计算每层的销售额
		ans += d[i] * p; 
		p=(1+r)*p;//计算下一层的单价 
	}
	printf("%.1lf\n", ans);
	return 0;
}
