//for循环中出现重大问题 
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
	if(a[root].l != -1)//左子树不为空
		dfs(a[root].l,index*2+1);
	a[root].index = index;
	if(a[root].r != -1)//右子树不为空
		dfs(a[root].r,index*2+2); 
}

int main(){
	int n;
	scanf("%d",&n);
	string left,right;
	for(int i=0;i<n;i++){
		a[i].id = i;//保存该节点的下标 
		cin>>left>>right;
		if(left != "-"){//左子树不为空 
			//a[i].l = (left-'0'); 这里的left可能是两位数的，要用string 
			a[i].l = stoi(left);
			vis[ a[i].l ] = true;
		}else
			a[i].l = -1;
		if(right != "-"){//右子树不为空 
			a[i].r = stoi(right);
			vis[ a[i].r ] = true;
		}else
			a[i].r = -1;
	} 
	
	//找出根节点 
	int root=0;
    while(vis[root]) root++;
	
	dfs(root,0);
	sort(a,a+n,cmp);//按index排序 
	
	if(a[n-1].index == n-1){
		printf("YES %d\n",a[n-1].id);
	}else
		printf("NO %d\n",root);
	return 0;
} 
