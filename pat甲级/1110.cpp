//forѭ���г����ش����� 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
	int id,l,r,index; 
}a[20];
bool vis[20];

bool cmp(const node& a,const node& b){
	return a.index < b.index;
}

void dfs(int root,int index){
	if(a[root].l != -1)//��������Ϊ��
		dfs(a[root].l,index*2+1);
	a[root].index = index;
	if(a[root].r != -1)//��������Ϊ��
		dfs(a[root].r,index*2+2); 
}

int main(){
	int n;
	scanf("%d",&n);
	string left,right;
	for(int i=0;i<n;i++){
		a[i].id = i;//����ýڵ���±� 
		cin>>left>>right;
		if(left != "-"){//��������Ϊ�� 
			//a[i].l = (left-'0'); �����left��������λ���ģ�Ҫ��string 
			a[i].l = stoi(left);
			vis[ a[i].l ] = true;
		}else
			a[i].l = -1;
		if(right != "-"){//��������Ϊ�� 
			a[i].r = stoi(right);
			vis[ a[i].r ] = true;
		}else
			a[i].r = -1;
	} 
	
	//�ҳ����ڵ� 
	int root=0;
    while(vis[root]) root++;
	
	dfs(root,0);
	sort(a,a+n,cmp);//��index���� 
	
	if(a[n-1].index == n-1){
		printf("YES %d\n",a[n-1].id);
	}else
		printf("NO %d\n",root);
	return 0;
} 
