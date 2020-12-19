#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;

struct node{
	int add,data,next;
}a[100005];
bool vis[100005];

vector<node> v; 

void deverse(int l,int r){
	int t = r-l+1;
	for(int i=0;i<t/2;i++){
		node nod = v[i+l];
		v[i+l] = v[r-i];
		v[r-i] = nod;
	}
}

int main(){
	int root,n,k;
	scanf("%d%d%d",&root,&n,&k);
	for(int i=0;i<n;i++){
		int add;
		scanf("%d",&add);
		vis[add] = true;
		scanf("%d%d",&a[add].data,&a[add].next);
		a[add].add = add;
	}
	
	while(root != -1 && vis[root]){
		v.push_back(a[root]);
		root = a[root].next;	
	}
	
	if(v.size() != 0){
		for(int i=0;i<v.size()/k;i++)//������v.size��������n��������� Ҫϸ��С�� 
			deverse(i*k,i*k+k-1);
		if(v.size() % k > 1)  //������ȫ��������������k����Ҫ��ת 
			deverse(v.size()/k*k,v.size()-1); 
			
		//���ַ�ת�������巭ת���� 
		deverse(0,v.size()-1); 
		printf("%05d %d",v[0].add,v[0].data);
		for(int i=1;i<v.size();i++)
			printf(" %05d\n%05d %d",v[i].add,v[i].add,v[i].data);
		printf(" ");
	}
	puts("-1");
	return 0;
} 
