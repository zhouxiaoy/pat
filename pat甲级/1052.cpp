#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

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
		vis[add] = true;//这个结点被使用了 
	}
    
	while(root != -1 && vis[root]){//不为空，并且该结点被使用了 
		v.push_back(a[root]);
		root = a[root].next;
	}
	
	sort(v.begin(),v.end(),cmp);
	//如果一个结点都没有，会数组越界 
	if(v.size() == 0)
		printf("0");
	else{
        printf("%d %05d\n%05d %d",v.size(),v[0].add,v[0].add,v[0].data);
        for(int i=1;i<v.size();i++){
            printf(" %05d\n%05d %d",v[i].add,v[i].add,v[i].data);
        }
    } 
	puts(" -1");
	return 0;
}
