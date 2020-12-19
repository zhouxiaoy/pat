#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int inorder[10005], preorder[10005];
int n, m;
//使用无序map优化
unordered_map<int, int> mp;

//找到中序遍历中的最早公共祖先
int lowestCommonAncestor(int root, int begin, int end, int p, int q) {
	if (begin > end)return 0;//在这个区间里没有
	if (preorder[root] == p || preorder[root] == q)return preorder[root];

	int i = mp[preorder[root]];//找到在中序中根节点的下标
	int left = lowestCommonAncestor(root + 1, begin, i - 1, p, q);
	int right = lowestCommonAncestor(root + i-begin+1, i + 1, end, p, q);
	if (!left)return right;
	if (!right) return left;
	return preorder[root];
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inorder[i]);
		mp[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++)   scanf("%d", &preorder[i]);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (mp[a] == 0 && mp[b] == 0)
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if (mp[a] == 0 || mp[b] == 0)
			printf("ERROR: %d is not found.\n", mp[a] == 0 ? a : b);
		
		else {
			int c = lowestCommonAncestor(1, 1, n, a, b);
			if (c == a || c == b)
				printf("%d is an ancestor of %d.\n", c, c == a ? b : a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, c);
		}
	}
	return 0;
}
