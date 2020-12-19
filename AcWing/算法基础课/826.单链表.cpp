#include <iostream>
#include <cstring> 
using namespace std;

const int N = 1e5+5;
//�ֱ����  ͷ���  ���value�����next 
int head,e[N],ne[N],idx;

//�����ʼ�� 
void init(){
	head = -1;//-1����Ϊ�� 
	idx = 0;
}
//��ͷ���֮����� 
void insert_to_head(int x){
	e[idx] = x;//����һ���½��valueΪx
	ne[idx] = head;//�½ڵ�ָ��head��ָ��λ�� 
	head = idx++;
}
//�ڵ�k��������� 
void insert_to_knode(int x,int k){
	e[idx] = x;//����һ���½��valueΪx
	ne[idx] = ne[k];//�½ڵ�ָ���k�������ָ��λ��
	ne[k] = idx++;
}
//ɾ����k����� 
void delete_knode(int k){
	ne[k] = ne[ne[k]]; 
} 

//��ӡ����
void print(){
	int t = head;
	while(t!=-1){
		cout<<e[t]<<' ';
		t = ne[t];
	}
} 

int main(){
	int n;
	cin>>n;
	init();
	for(int i=0;i<n;i++){
		char ch;
		int a,b;
		cin>>ch;
		if(ch == 'H'){//ͷ������ 
			cin>>b;
			insert_to_head(b);
		}else if(ch == 'I'){//��k��������� 
			cin>>a>>b;
			insert_to_knode(b,a-1);
		}else{
			cin>>a;
			if(a)
				delete_knode(a-1);
			else//a����0ʱ������ɾ��ͷ��� 
				head = ne[head];//ɾ��ͷ�����һ������ 
		}
	}
	print();	
	return 0;
} 
