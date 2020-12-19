#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

vector<int> pre, in, post;
stack<int> s;

void turnToPost(int l, int r, int root) {
	if (l > r)return;
	else if (l < r) {
		int i = l;
		//找到根节点
		while (i <= r && in[i] != pre[root])i++;
		turnToPost(l, i - 1, root + 1);
		turnToPost(i + 1, r, root + i - l + 1);
	}
	//只有一个结点时，或，保存完左右子树后保存根节点
	post.push_back(pre[root]);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	char str[5];
	while (~scanf("%s", str)) {
		if (strlen(str) == 4) {//push 
			int a;
			scanf("%d", &a);
			s.push(a);
			pre.push_back(a);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	
	turnToPost(0,n-1,0);
	
	printf("%d",post[0]);
	for(int i=1;i<n;i++)
	    printf(" %d",post[i]);

	return 0;
}
