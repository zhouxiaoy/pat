#include <iostream>

using namespace std;

struct node {
	char data;
	node* next;
};
int sum1,sum2;//两个链表的长度 
//找出公共节点
node* search(node* str1,node* str2) {
	//让长的字符串先遍历，遍历到两个串一样长 
	node* q = str1,*p = str2;
	while(sum1>sum2 && q != NULL){
		q = q->next;
		sum1--;
	}
	while(sum1<sum2 && p != NULL){
		p = p->next;
		sum2--;
	}
	
	//判断是否为同一个结点
	while(q != NULL && p != NULL && p != q){
		q = q->next;
		p = p->next;
	} 
	if(p == q)
	return p;
	else return NULL;
}
//构造不出来地址一样的，但是大概原理就是这样的 
int main() {
	node* str1 = new node();

	cin >> sum1;

	//数据插入 尾插入
	node* rear = str1;//尾结点 
	for (int i = 0; i < sum1; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}
	node* str2 = new node();
	cin >> sum2;

	//数据插入 尾插入
	rear = str2;//尾结点 
	for (int i = 0; i < sum2; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}	
	
	rear = search(str1,str2)
	cout<<rear->data<<endl;
	return 0;
}
