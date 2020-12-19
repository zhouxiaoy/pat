#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

//找到倒数第k个数 
int find_K(node* root,int k){
	if(root == NULL)return 0;
	node* pre = root->next,* p = root->next;
	int ans = 1;
	while(p && ans < k){
		p = p->next;
		ans++;
	}
	//链表结点没有k个 
	if(ans != k)return 0;
	
	while(p->next != NULL){
		pre = pre->next;
		p = p->next; 
	}
	cout<<pre->data<<endl;
	return 1;
} 

int main() {
	node* root = new node();
	int n;
	cin >> n;


	//数据插入 尾插入
	node* rear = root;//尾结点 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}
	
	int x;
	cin>>x;
	find_K(root,x);
	return 0;
}
