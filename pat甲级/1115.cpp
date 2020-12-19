#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int maxDep = -1;
int DepPeo[1005];

struct node {
	int val;
	node* left, *right;
};

node* insert(node* root, int val,int dep) {
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
		if(dep>maxDep)  maxDep = dep;
		DepPeo[dep]++; 
	}
	else if (val <= root->val) {//ÔÚ×ó×ÓÊ÷ÖÐ 
		root->left = insert(root->left, val,dep+1);
	}
	else {
		root->right = insert(root->right, val,dep+1);
	}
	return root;
}

int main() {
	int n, t;
	node* root = NULL;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		root = insert(root, t,0);
	}
	
	printf("%d + %d = %d\n", DepPeo[maxDep], DepPeo[maxDep -1], DepPeo[maxDep] + DepPeo[maxDep -1]);
	return 0;
}
