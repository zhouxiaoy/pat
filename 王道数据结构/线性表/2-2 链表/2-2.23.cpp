#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* next;
};

int x;//表示|data|的最大值
vector<bool> v;

void del(node* root){
	if(root == NULL) return;
	node* p = root;
	while(p->next){
		if(v[abs(p->next->data)] == false){
			v[abs(p->next->data)] = true;
			p = p->next;
		}
		else
			p->next = p->next->next;
	}
}

int main() {
	node* root = new node();
	int n;
	cin >> n>>x;

	//数据插入 尾插入
	node* rear = root;//尾结点 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}
	
	v.resize(x+1);
	
	del(root);
	
	node* p = root->next;
	while (p != NULL) {
		cout << p->data <<' ';
		p = p->next;
	}
	return 0;
}
