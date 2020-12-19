//��������
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
	//�ҵ�ֵΪx�Ľ�� 
	while(q->next != NULL && q->next->data != x)
		q = q->next;
	node*p = q->next;//�ݴ�Ϊx�Ľ�� 
	q->next = p->next;//��p����������������� 
	int t = p->freq++;
	
	//������û��dataΪx�Ľڵ� 
	if(q->next == NULL)return NULL;
	
	//�ҵ���һ��freq��= t�Ľ�㣬�����������ǰ�� 
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
	

	//���ݲ��� β����
	node* rear = root;//β��� 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		
		rear->next = q;
		rear = q;
	}
	int x;
	while(1){
		cout<<"������Ҫ����������x:";
		cin>>x;
		node* t = Locate(root,x);
		
		//��ӡ
		cout<<"�����������Ϊ:";
		node* p = root->next;
		while (p != NULL) {
			cout << p->data << ' '<<p->freq<<endl;
			p = p->next;
		}
	} 
	return 0;
}
*/ 
//˫�����
//˫�����
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
	//�ҵ�ֵΪx�Ľ�� 
	while (q && q->data != x)
		q = q->next;

	//������û��dataΪx�Ľڵ� 
	if (q == NULL)return NULL;

	q->pred->next = q->next;//��p����������������� 
	if (q->next != NULL)
		q->next->pred = q->pred;
	q->freq++;

	node*p = q->pred;//�ݴ�Ϊx�Ľ�� 

	//�ҵ���һ��freq <q.freq �Ľ�㣬�����������ǰ�� 
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


	//���ݲ��� β����
	node* rear = root;//β��� 
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
		cout << "������Ҫ����������x:";
		cin >> x;
		node* t = Locate(root, x);

		//��ӡ
		cout << "�����������Ϊ:";
		node* p = root->next;
		while (p != NULL) {
			cout << p->data << ' ' << p->freq << endl;
			p = p->next;
		}
	}
	return 0;
}
