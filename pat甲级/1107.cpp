#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> parent, isRoot; // 
int hab[1001];//���ô�1-1000 

bool cmp(int a, int b) {
	return a > b;
}

int find(int i) {
	if (i != parent[i])
		parent[i] = find(parent[i]);
	return parent[i];
}

//��a��b�ϲ�Ϊһ������ 
void add(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa != pb)
		parent[pa] = pb;
}

int main() {
	int n;
	scanf("%d", &n);
	parent.resize(n + 1);
	isRoot.resize(n + 1);

	//��ʼ��
	//ÿ����㶼���Լ��ĸ��ڵ� 
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		int k, a;
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			if (hab[a] == 0)//��һ��ϲ�����ϰ�ߵ��� 
				hab[a] = i;

			//������˼��������������
			add(i, find(hab[a]));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		isRoot[find(i)]++;
	for (int i = 1; i <= n; i++)
		if (isRoot[i] != 0) ans++;
	printf("%d\n", ans);
	sort(isRoot.begin(), isRoot.end(), cmp);
	for (int i = 0; i < ans; i++) {
		printf("%d", isRoot[i]);
		if (i != ans - 1)printf(" ");
	}
	return 0;
}
