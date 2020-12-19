//单链表版的
/* 
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	int freq = 0;
};

node* Locate(node* root,int x){
	if(root == NULL)return NULL;
	node* q = root;
	//找到值为x的结点 
	while(q->next != NULL && q->next->data != x)
		q = q->next;
	node*p = q->next;//暂存为x的结点 
	q->next = p->next;//将p结点从链表中脱离出来 
	int t = p->freq++;
	
	//链表中没有data为x的节点 
	if(q->next == NULL)return NULL;
	
	//找到第一个freq《= t的结点，将其插入在其前面 
	q = root;
	while(q->next != NULL && q->next->freq > t)
		q = q->next;
	p->next = q->next;
	q->next =  p;
	return p;
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
	while(1){
		cout<<"请输入要操作的数据x:";
		cin>>x;
		node* t = Locate(root,x);
		
		//打印
		cout<<"操作后的链表为:";
		node* p = root->next;
		while (p != NULL) {
			cout << p->data << ' '<<p->freq<<endl;
			p = p->next;
		}
	} 
	return 0;
}
*/ 
//双链表版
//双链表版
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next, *pred;
	int freq = 0;
};

node* Locate(node* root, int x) {
	if (root == NULL)return NULL;
	node* q = root->next;
	//找到值为x的结点 
	while (q && q->data != x)
		q = q->next;

	//链表中没有data为x的节点 
	if (q == NULL)return NULL;

	q->pred->next = q->next;//将p结点从链表中脱离出来 
	if (q->next != NULL)
		q->next->pred = q->pred;
	q->freq++;

	node*p = q->pred;//暂存为x的结点 

	//找到第一个freq <q.freq 的结点，将其插入在其前面 
	while (p != root && p->freq <= q->freq)
		p = p->pred;

	q->next = p->next;
	p->next->pred = q;
	q->pred = p;
	p->next = q;
	return q;
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
		q->pred = rear;
		rear->next = q;
		rear = q;
	}
	int x;
	while (1) {
		cout << "请输入要操作的数据x:";
		cin >> x;
		node* t = Locate(root, x);

		//打印
		cout << "操作后的链表为:";
		node* p = root->next;
		while (p != NULL) {
			cout << p->data << ' ' << p->freq << endl;
			p = p->next;
		}
	}
	return 0;
}
