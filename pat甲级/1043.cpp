#include <iostream>
#include <limits.h>
#include <cstdio>
#include <vector>
using namespace std;

int node[1005], n;
vector<int> postOrder;
bool isBST(int begin, int end, int minn, int maxx) {
	if (node[begin]<minn || node[begin]>maxx)return false;
	
	if (begin == end){
		postOrder.push_back(node[begin]);
		return true;
	} 
	//找出第一个大于根结点的元素下标 
	int i = begin + 1;
	while (i <= end && node[i] < node[begin])i++;
	//如果左子树和右子树都是BST则为true 
	bool t = isBST(begin + 1, i - 1, minn, node[begin] - 1) && isBST(i, end, node[begin], maxx);
	postOrder.push_back(node[begin]);
	return t;
}

bool isMI_BST(int begin, int end, int minn, int maxx) {
	if (node[begin]<minn || node[begin]>maxx)return false;
	
	if (begin == end){
		postOrder.push_back(node[begin]);
		return true;
	} 
	//找出第一个小于根结点的元素下标 
	int i = begin + 1;
	while (i <= end && node[i] >= node[begin])i++;
	//如果左子树和右子树都是isMI_BST则为true 
	bool t = isMI_BST(begin + 1, i - 1, node[begin], maxx) && isMI_BST(i, end, minn, node[begin] - 1); 
	//每次将头结点（即根节点）压入vector中 
	postOrder.push_back(node[begin]);
	return t;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> node[i];
	//cout<<isMI_BST(0,n-1,INT_MIN,INT_MAX);
	if (isBST(0, n - 1, INT_MIN, INT_MAX)) {
		puts("YES");
		int t = postOrder.size();
		for (int i = 0; i < t - 1; i++)
			cout << postOrder[i] << ' ';
		cout << postOrder[t-1];
		return 0;
	}
	postOrder.clear();
	if (isMI_BST(0, n - 1, INT_MIN, INT_MAX)) {
		puts("YES");
		int t = postOrder.size();
		for (int i = 0; i < t - 1; i++)
			cout << postOrder[i] << ' ';
		cout << postOrder[t-1];
		return 0;
	}
	else
		puts("NO");
	return 0;
}
