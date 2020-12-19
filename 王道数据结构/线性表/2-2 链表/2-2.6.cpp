//删除单链表中值为x的结点 
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* del_min(node* root) {
	node* p,*q = root->next,*head = new node();
	node* Pre = head,*Idx = head->next;

	while(q != NULL){
		Pre = head,Idx = head->next;
		while(Idx != NULL && Idx->data <= q->data){
			Pre = Idx;
			Idx = Idx->next;
		}
		p = q->next;//暂存q->next 
		Pre->next = q;
		q->next = Idx;
		
		q = p; 
	}
	return head;
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

	root = del_min(root);

	//打印
	node* p = root->next;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	return 0;
}
