/*
 * 因为BST是左子树 小于 根节点，根节点 小于 右子树 
 * 所以将value从小到大排序后，最小的一定是 根节点能找到的最左的左节点
 * 然后是这个 左节点的根节点，在是 右节点，用 cnt来表示要填充的data下标、
 * 用 index 来区分 同一层（label表示层数）哪个在左，哪个再右 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int data, l, r, index, label;
}a[105];
int b[105];
int cnt=0;//遍历顺序 

bool cmp(const node a,const node b){
	if(a.label != b.label) return a.label < b.label;
	else return a.index < b.index;
}

void dfs(int root,int index,int label){
	if(a[root].l == -1 && a[root].r == -1){//为叶子结点 
		a[root] = {b[cnt++],a[root].l,a[root].r,index,label};
	}else{//遍历顺序是中序遍历（因为对b数组排序了） 
		if(a[root].l != -1)//左子树不为空 
			dfs(a[root].l,index*2+1,label+1);
		a[root] = {b[cnt++],a[root].l,a[root].r,index,label};
		if(a[root].l != -1)//右子树不为空
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
	dfs(0,0,0);//将data填充到相应的结点 
	sort(a,a+n,cmp); //按层序排序 
	
	printf("%d",&a[0].data);
	for(int i=1;i<n;i++)
		printf(" %d",&a[0].data);
	return 0;
} 
