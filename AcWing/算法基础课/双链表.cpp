#include <iostream>

using namespace std;

const int N = 1e5+5;
//�ֱ����һ������  vaule��prev��next 
int e[N],l[N],r[N],idx;

void init(){
	//������0��ʾͷ��㣬1��ʾβ��� 
	//ͷ����ָ��nextβ�ڵ㣬β�ڵ��prevָ��ͷ�ڵ� 
	r[0] = 1,l[1] = 0; 
	idx = 2;//�����±��Ǵ�2��ʼ�ģ����Ե�k�����ʵ���±�Ϊk+1 
}

void add(int k,int x){
	e[idx] = x;
	l[idx] = k, r[idx] = r[k];
	r[k] = idx, l[r[idx]] = idx;
	idx++;
}

void remove(int k){
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

void print(){
	for (int i = r[0]; i != 1; i = r[i]) 
		cout << e[i] << ' ';
}

int main(){
	int n;
	cin>>n;
	init();
	while(n--){
		string str;
		int a,b;
		cin>>str;
		if(str.size()>1){
			cin>>a>>b;
			if(str[1] == 'R')
				add(a+1,b);
			else
				add(l[a+1],b);
		}else{
			cin>>b;
			if(str[0] == 'R')
				add(l[1],b);
			else if(str[0] == 'L')
				add(0,b);
			else
				remove(b+1);
		}
	}
	print();
	return 0;
} 
