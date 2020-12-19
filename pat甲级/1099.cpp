/*
 * ��ΪBST�������� С�� ���ڵ㣬���ڵ� С�� ������ 
 * ���Խ�value��С�����������С��һ���� ���ڵ����ҵ����������ڵ�
 * Ȼ������� ��ڵ�ĸ��ڵ㣬���� �ҽڵ㣬�� cnt����ʾҪ����data�±ꡢ
 * �� index ������ ͬһ�㣨label��ʾ�������ĸ������ĸ����� 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int data, l, r, index, label;
}a[105];
int b[105];
int cnt=0;//����˳�� 

bool cmp(const node a,const node b){
	if(a.label != b.label) return a.label < b.label;
	else return a.index < b.index;
}

void dfs(int root,int index,int label){
	if(a[root].l == -1 && a[root].r == -1){//ΪҶ�ӽ�� 
		a[root] = {b[cnt++],a[root].l,a[root].r,index,label};
	}else{//����˳���������������Ϊ��b���������ˣ� 
		if(a[root].l != -1)//��������Ϊ�� 
			dfs(a[root].l,index*2+1,label+1);
		a[root] = {b[cnt++],a[root].l,a[root].r,index,label};
		if(a[root].l != -1)//��������Ϊ��
			dfs(a[root].r,index * 2 + 2,label + 1); 
	} 	
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
		
	sort(b,b+n);
	dfs(0,0,0);//��data��䵽��Ӧ�Ľ�� 
	sort(a,a+n,cmp); //���������� 
	
	printf("%d",&a[0].data);
	for(int i=1;i<n;i++)
		printf(" %d",&a[0].data);
	return 0;
} 
