#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int,bool> vis; 
int pre[1005];

int main(){
	int n,m,a,v,u;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&a);
		vis[a] = true;
		pre[i] = a;
	}
	
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		
		//因为是preorder，所以pre数组里的第一个满足条件的就是LCA
		//所以，找到了就直接跳出，否则就是没有 
		for(int j=0;j<m;j++){
			a = pre[j]; 
			if((v >= a && u <= a) || (u >= a && v <= a))break;
		}
		if(vis[v] == false && vis[u] == false)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if(vis[v]  == false || vis[u] == false)
			printf("ERROR: %d is not found.\n", vis[u] == false ? u : v);
		else if(v == a || u == a)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
} 


/* 
//超时版本，但是思想值得学习 
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
	int data;
	node* left, *right;
};

unordered_map<int, int> vis;

node* insert(node *root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
		return root;
	}
	if (x < root->data)//在左子树中
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);
	return root;
}

node* LCA(node* root, int a, int b) {
	if (!root || root->data == a || root->data == b) return root;
	auto left = LCA(root->left, a, b);
	auto right = LCA(root->right, a, b);

	if (!left) return right;
	if (!right) return left;
	return root;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	node* root = NULL;
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		root = insert(root, a);
		vis[a]++;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (vis[a] && vis[b]) {
			node* p = LCA(root, a, b);
			int c = p->data;
			if (c == a)
				printf("%d is an ancestor of %d.\n", a, b);
			else if (c == b)
				printf("%d is an ancestor of %d.\n", b, a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, c);
		}
		else {
			if (!vis[a] && !vis[b])
				printf("ERROR: %d and %d are not found.\n", a, b);
			else if (!vis[a])
				printf("ERROR: %d is not found.\n", a);
			else if (!vis[b])
				printf("ERROR: %d is not found.\n", b);
		}
	}
	return 0;
}
*/ 
