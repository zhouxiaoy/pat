//删除单链表中值为x的结点 
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* del(node* root, int x) {
	node* q, *p;
	if (root == NULL)return NULL;

	/*先删除首结点 失败（也是因为没将root返回回去） 
	//删除首结点为x
	while(root != NULL && root->data == x){
		p = root;
		root = root->next;
		delete(p);
	}
	q = root;
	*/

	//在root前加一个结点
	q = new node();
	q->next = root;
	node* preNode = q;//标记一下 最后记得删除 

	while (q->next != NULL) {
		if (q->next->data == x) {
			p = q->next;
			q->next = q->next->next;
			delete(p);
		}
		else {
			q = q->next;
		}
	}
	root = preNode->next;
	delete(preNode);
	//返回是因为 指针本质是值传递，里面的root和外面的不一样 
	return root;
}

int main() {
	node* root = NULL;
	int n;
	cin >> n;
	/*
	//数据输入 头插入
	for(int i=0;i<n;i++){
		node*q = new node();
		cin>>q->data;
		q->next = root;
		root = q;
	}
	*/

	//数据插入 尾插入
	node* rear = root;//尾结点 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		if (root == NULL) root = q;
		else
			rear->next = q;
		rear = q;
	}

	int x;
	cout << "请输入要删除的数字:";
	cin >> x;
	root = del(root, x);

	//打印
	node* p = root;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	return 0;
}
