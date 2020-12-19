#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//ֻ��Ҫ�����ÿһ����ȵ������������ٷֱ���������� 
int n, maxdep = -1;
double p, r;
int w[100005],d[100005];//����ÿ���������۶ÿ��������۶� 
vector<vector<int>> v;

void dfs(int node, int depth) {
	//�����Ҷ�ڵ���ı����ȵ�������
	if (v[node].size() == 0) {
		d[depth] += w[node];
		maxdep = max(depth, maxdep);//���������� 
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
			scanf("%d", &w[i]);//�洢������
	}
	dfs(0, 0);
	double ans = 0;
	for (int i = 0; i <= maxdep; i++) {//����ÿ������۶�
		ans += d[i] * p; 
		p=(1+r)*p;//������һ��ĵ��� 
	}
	printf("%.1lf\n", ans);
	return 0;
}
