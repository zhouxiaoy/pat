#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*
struct node{
	char data;
	int next;
}a[100000];

bool b[100000];

int main(){
	int root1,root2,n;
	scanf("%d%d%d",&root1,&root2,&n);
	for(int i=0;i<n;i++){
		int adds;
		scanf("%d",&adds);
		//Ҫ�ѿո�Ե� 
		scanf(" %c %d",&a[adds].data,&a[adds].next);
		//printf("%d %c %d\n",adds,a[adds].data,a[adds].next);
	}
	while(root1 != -1){
		b[root1] = true;
		root1 = a[root1].next;
	}
	
	while(root2 != -1){
		if(b[root2] == true){
			printf("%05d",root2);
		    return 0;
		}
		else
			b[root2] = true;
		root2 = a[root2].next;
	}
	puts("-1");
	return 0;
} 
*/

/* 1052 �������� 
 * һ�������Ѹ��� ��һ������û�뵽
 * ���Ľ����Щ��������  Ҫ�ñ�Ǳ�ʾ�ýڵ㱻���ˣ�����Խ�� 
*/ 
/* 
struct node1{
	int add,next;
	int data;
}a[100005];
bool vis[100005];
vector<node1> v;

bool cmp(const node1& a,const node1& b){
	return a.data < b.data;
}

int main(){
	int n,root,add,sum = 0;
	scanf("%d%d",&n,&root);
	
	for(int i=0;i<n;i++){
		scanf("%d",&add);
		scanf("%d%d",&a[add].data,&a[add].next);
		a[add].add = add;
		vis[add] = true;//�����㱻ʹ���� 
	}
	while(root != -1 && vis[root]){//��Ϊ�գ����Ҹý�㱻ʹ���� 
		v.push_back(a[root]);
		root = a[root].next;
	}
	
	sort(v.begin(),v.end(),cmp);
	//���һ����㶼û�У�������Խ�� 
	if(v.size() == 0)
	{
		puts("0 -1");
		return 0;
	}
	
	printf("%d %05d\n%05d %d",v.size(),v[0].add,v[0].add,v[0].data);
	for(int i=1;i<v.size();i++){
		printf(" %05d\n%05d %d",v[i].add,v[i].add,v[i].data);
	}
	puts(" -1");
	return 0;
}
*/
//pat�Ҽ�1075 ����Ԫ�ط��� 
/*
 *	bool cmp(const node& a,const node& b){
 *	    if((a.data<0 && b.data<0) || (a.data>=0 &&a.data<=k &&b.data>=0 &&b.data<=k)||(a.data>k && b.data>k))
 *	    return false;
 * 	    else return a.data<b.data;
	}
 *  �������� ����Ϊ�����ǲ��ȶ��㷨
 *  ����ֻ��ͨ������vector����Ϊ�����֣�������� 
*/ 


