#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int id, left, right, index, level;
}a[10];
bool vis[10];
vector<node> v;

bool cmp(const node &a, const node &b) {
	if (a.level != b.level) return a.level < b.level;
	else return a.index < b.index;
}

void dfs(int root, int index, int level) {
	if (a[root].left != -1)//有左子树  遍历左子树 
		dfs(a[root].left, index * 2 + 1, level + 1);
	a[root] = { root,a[root].left,a[root].right,index,level };
	v.push_back(a[root]);
	if (a[root].right != -1)//有右子树 遍历右子树
		dfs(a[root].right, index * 2 + 2, level + 1);
}

int main() {
	int n, t;
	scanf("%d", &n);
	char left, right;
	for (int i = 0; i < n; i++) {
		cin >> right >> left;
		if (left != '-') {
			t = left - '0';
			vis[t] = true;
		}
		else
			t = -1;
		a[i].left = t;

		if (right != '-') {
			t = right - '0';
			vis[t] = true;
		}
		else
			t = -1;
		a[i].right = t;
	}
	//找到根节点 
	int root;
	for (int i = 0; i < n; i++)
		if (vis[i] == false)root = i;

	dfs(root, 0, 0);

	//层序遍历 
	sort(a, a + n, cmp);
	printf("%d", a[0].id);
	for (int i = 1; i < n; i++)
		printf(" %d", a[i].id);

	//中序遍历 
	printf("\n%d", v[0].id);
	for (int i = 1; i < v.size(); i++)
		printf(" %d", v[i].id);
	return 0;
}

