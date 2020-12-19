#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* next;
};

//找到链表的中间结点 
node* fun(node* root) {
	if (root == NULL) return NULL;
	node* p = root, *q = root;
	//这里要用q->next 不能字节走两步，因为可能最后只剩一个了 
	while (q->next != NULL && q->next->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	if (q->next != NULL)p = p->next;
	return p;
}

void fun2(node *root){
	node* p = fun(root);//前半段的尾结点 
	node* q = p->next;//后半段的首结点 
	node* r,*s; 
	p->next = NULL;
	while(q!=NULL){//将后半段翻转 
		r= q->next;
		r->next = q;
	} 
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

	rear = fun(root);
	cout << rear->data << endl;
	return 0;
}
