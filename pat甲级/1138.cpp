#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 50005;
int pre[maxn], in[maxn];
vector<int> post;

void dfs(int root, int l, int r) {
	if (l >= r) {
	    if(l == r)
		post.push_back(in[l]);//���ڵ�
		return;
	}
	//�ҵ�in�еĸ��ڵ�
	int i = l;
	while (i < r && in[i] != pre[root])i++;
	cout<<"������Ϊ��" << root + 1 << ' ' << l << ' ' << i - 1 << endl;
	cout <<"������Ϊ:"<< root + i - l + 1 << ' ' << i+1 << ' ' << r << endl;

	dfs(root + 1, l, i - 1);//������
	dfs(root + i - l + 1, i + 1, r);//������
	post.push_back(pre[root]);//���ڵ�
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)scanf("%d", &in[i]);
	dfs(0, 0, n - 1);
	for (int i = 0; i < post.size(); i++)
		cout << post[i] << ' ';
	return 0;
}
