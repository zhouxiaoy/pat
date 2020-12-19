#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 中序，后序转前序，前序中序转后续，划分要熟悉
/* 
 * 前序的第一个是整个树的根
 * 后序的最后一个是整个树的根
 * 中序用来判别左右子树的划分
 * 前序序列中左子树部分的第一个节点是左子树的根节点
 * 前序序列中右子树部分的第一个节点是右子树的根节点 
 
 * 前序 中序  转 后序
 * 0.if(l > r) return ; 
 * 1.in中从l到r找到根节点
 * 2.dfs(root+1,l,i-1);左子树  从l到i-1就是左子树
 * 3.dfs(root+1-(i-l)(左子树的长度),i+1,r);//找到右子树的根节点  当前根节点+1减左子树长度 
 * 
 * 后序 中序  转 前序
 * 0.同上 
 * 1.同上 
 * 2.dfs(root-1-(r-i)(右子树长度),l,i-1); 
 * 3.dfs(root-1,i+1,r);
 */ 
//1004  层序遍历 bfs  dfs 
/*
 * 这里不能使用bfs 因为如果 有 1  2 两个子节点，处理1结点时会将1的子节点加入，会影响层序的分界
 * 更正 可以bfs只需要每次记录下当前层序下结点的个数 看1004 题解里面就有 
 * 你只需要管自己是否是叶结点 就行 ，不需要管子节点，子节点通过for循环递归 
*/ 

/* 
int maxlevel = 0;
vector<int> v[105];
int sum[105];
void dfs(int node,int level){
    if(level>maxlevel)maxlevel = level;
    if(v[node].size() == 0) {
        sum[level]++;
        return;//该节点没有孩子
    }
    for(int i=0;i<v[node].size();i++)
        dfs(v[node][i],level+1);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
	    int id,k;
	    scanf("%d%d",&id,&k);
	    for(int j=0;j<k;j++){
	        int a;
	        scanf("%d",&a);
	        v[id].push_back(a);
	    }
	}
	
	dfs(1,0);
	for(int i=0;i<maxlevel;i++){
	    cout<<sum[i]<<' ';
	}
	cout<<sum[maxlevel];
	return 0;
} 
*/

//1020  postorder and inorder change for level order

/*
 * 最重要的是怎么划分左子树的范围 和右子树的范围 
 * 自己做麻烦了其实不需要post的范围，只要把根节点的值传给参数就成了 
 * root是后缀的根节点，root-1 就是右子树的根节点，root - 右子树的长度（end-i）-1 就是左子树的根节点 
*/  

/* 
int post[30],in[30];
int maxdep = 0;
vector<int> v[30];
void dfs(int pl,int pr,int il,int ir,int dep){
	
	if(pl==pr){
		if(dep>maxdep)
			maxdep = dep;
		v[dep].push_back(post[pl]);
		return;
	}
	//找到in中的根结点
	int x = post[pr];//后序最后一个为根节点
	for(int i=il;i<=ir;i++){
		if(x == in[i]){//找到根节点 
			//length = ir - i;//右子树的长度
			//length = i - il;//左子树的长度
			v[dep].push_back(x);
			dfs(pl,pr-ir+i-1,il,i-1,dep+1);//遍历左子树
			dfs(pr-ir+i,pr-1,i+1,ir,dep+1);
			//改正后： 去掉后缀的范围，只保留中序的范围 把根节点传进来 
			//dfs(root-1-r+i,l,i-1,dep+1);//遍历左子树
			//dfs(root-1,i+1,r,dep+1);
			return;
		}
	} 
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	for(int j=0;j<n;j++)
		scanf("%d",&in[j]);	

dfs(0,n-1,0,n-1,0);
printf("%d",v[0][0]);
for(int i=0;i<=maxdep;i++){
	for(int j=0;j<v[i].size();j++){
		if(i == 0 && j == 0)continue;
		printf(" %d",v[i][j]);
	}
} 
return 0;
} 
*/ 

//1043 BST二叉查找树
/*
 * 这里要后序打印 只要先处理 左子树，再右子树，最后把根节点存入
 * 寻找范围 要明确 不能找到根节点去
 * BST不一定是完全二叉树，但大于（有些题有等于）根节点的为右子树，小于的为左子树 
*/ 

/* 
int node[1005];//结点
int isMir = false;//是否为反BST
vector<int> v;
void toPost(int l,int r){
	if(l>r)return;
	int i = l+1,j = r;
	if(!isMir){
		while(i<=r && node[i]<node[l]) i++;
		while(j>l && node[j]>=node[l]) j--; //j>l这里必须不能想等，l为根节点，不能划为左子树中 
	}else{
		while(i<=r && node[i]>=node[l]) i++;
		while(j>l && node[j]<node[l]) j--; //同上 
	}
	if(i-j != 1){
		return;
	}
	toPost(l+1,j);
	toPost(i,r);
	v.push_back(node[l]);
}

void print(){
	puts("YES");
	printf("%d",v[0]);
	for(int i=1;i<v.size();i++)
		printf(" %d",v[i]);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&node[i]);
		
	toPost(0,n-1);
	if(v.size() == n){
		print();
	}else{
		isMir = true;
		v.clear();
		toPost(0,n-1);
		if(v.size() == n)
			print();
		else
			puts("NO");
	}
	return 0;
} 
*/

//1053  树的遍历
/*
 * 因为从根结点到叶结点的路径唯一 所以一开始想直接计算出权重之和 ，但是需要打印
 * 路径，所以这个方法不行
 * 所以采用dfs来做，保存走过的路径，如果不符合回溯（删掉最后一个路径），搜索打印 
*/
/* 
int w[105];//结点的权重
vector<int> path;
vector<int> v[105];//邻接表，保存该节点下的子结点 

bool cmp(const int& a, const int& b) {
	return w[a] > w[b];
}

void dfs(int root, int wei) {
	if (v[root].size() == 0) {
		if (wei == w[root]) {
			for (int i = 0; i < path.size(); i++)
				printf("%d ", w[path[i]]);
			printf("%d\n", w[root]);
		}
		return;
	}
	else {
		if (wei >= w[root]) {
			for (int i = 0; i < v[root].size(); i++) {
				path.push_back(root);
				dfs(v[root][i], wei - w[root]);
				path.pop_back();
			}
		}
	}
}

int main() {
	int n, m, pathw;
	scanf("%d%d%d", &n, &m, &pathw);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) {
		int k, id;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			int a;
			scanf("%d", &a);
			v[id].push_back(a);
		}
		sort(v[id].begin(), v[id].end(), cmp);
	}
	dfs(0, pathw);
}
*/
 
//1066 AVL模板题 看 AVL 


//1079  dfs  bfs 树的遍历 
/*
int n;
double p,r,ans;
int sum[100005];
vector<vector<int>> v;

void dfs(int root,double price){
	if(v[root].size() == 0){
		ans+=price*sum[root];
		return;
	}

	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i],(1+r)*price);
} 

int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	v.resize(n);
	for(int i=0;i<n;i++){
		int k,a;
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&a);
				vector[i].push_back(a);
			}
		}else{
			scanf("%d",&a);
			sum[i] = a;
		}
	}
	
	dfs(0,p);
	printf("%lf\n",ans);
	return 0;
} 
*/

//1086 树的遍历
//要理解 用栈模拟数的遍历过程
//这一题给的是stack的中序遍历（我们可以得到数的前序和中序遍历）
//上面的很重要
//最后一点要注意的是，题目没给出 不会相同，所以我们可以用下标代替（不然相同时，找root时会出错） 
/* 
//加一个vector<int> val;int key=0;每次用下标来，避免数字相同出现的问题 
vector<int> pre, in, post;
stack<int> s;

void turnToPost(int l, int r, int root) {
	if (l > r)return;
	else if (l < r) {
		int i = l;
		//找到根节点
		while (i <= r && in[i] != pre[root])i++;
		turnToPost(l, i - 1, root + 1);
		turnToPost(i + 1, r, root + i - l + 1);
	}
	//只有一个结点时，或，保存完左右子树后保存根节点
	post.push_back(pre[root]);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	char str[5];
	while (~scanf("%s", str)) {
		if (strlen(str) == 4) {//push 
			int a;
			scanf("%d", &a);
			s.push(a);
			pre.push_back(a);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	
	turnToPost(0,n-1,0);
	
	printf("%d",post[0]);
	for(int i=1;i<n;i++)
	    printf(" %d",post[i]);

	return 0;
}
*/ 

//1090 书的遍历
//想当然了，当前根深度大于最大深度，不是当前根深度等于最大深度的反命题

/* 
vector<int> v[100005];
 
int maxDep = -1,maxSum= 0;
void dfs(int root,int dep){
	if(v[root].size() == 0){
		if(maxDep == dep)
			maxSum++;
		//else{//之前的问题 
		else if(maxDep<dep){//这里必须时maxDep<dep  之前用的是直接else 会出现一个错误点 
			maxDep = dep;
			maxSum = 1;
		} 
		return;
	}
	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i],dep+1); 
}

int main(){
	int n,root;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a != -1)
			v[a].push_back(i);
		else
			root = i;
	}

	dfs(root,0);
	
	for(int i=0;i<maxDep;i++)
		p = p*(100+r)/100;
	
	printf("%.2lf %d\n",p,maxSum);
	return 0;
} 
*/ 

//1094  树的层序遍历 没什么难点和问题 

//1099 树的层序遍历 BST   没想到 不会做 
/*
	里面用index（完全二叉树的下标）和label（层数）
	来区分同一层的前后顺序 
	用dfs来填充数据，用dfs实现中序遍历（和BST的特性结合，中序的data是从小到大的） 
*/ 

//1102  树的层序遍历 和 中序遍历  写法和 1099类似，可以在dfs中得到层序和中序
//1106  层序遍历 用dfs和bfs实现 （bfs要设定一个层数很重要） 
//1110  树的遍历 写法和1102 1099 类似
//出现了一个重大失误  因为给出的结点是<20的，我用char接收
//导致出现段错误  应该用string 再用stoi 转化为数字

//1115 BST 模拟BST的过程 没太多问题，BST的遍历 
//1143 LCA 最近公共祖先   1151是LCA + preorder + inorder 
/*
 *这道题给的是BST，所以是公共祖先的话(升序排序之后)，必定是左子树的根节点(a)，公共祖先(LCA)，右子树的根节点(b) 
 *另一种情况就是 a，b其中有一个就是(LCA)
 *用一个map，对给的给点标记一下，便于以后查看是否该节点是否在树中，并且增序排序 
*/
/*
//正确版本可看1143 
//这个为超时版本，构建BST树，再使用LCA遍历找出， 
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
	int data;
	node* left, *right;
};

unordered_map<int, int> vis;

node* insert(node *root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
		return root;
	}
	if (x < root->data)//在左子树中
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);
	return root;
}

node* LCA(node* root, int a, int b) {
	if (!root || root->data == a || root->data == b) return root;
	auto left = LCA(root->left, a, b);
	auto right = LCA(root->right, a, b);

	if (!left) return right;
	if (!right) return left;
	return root;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	node* root = NULL;
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		root = insert(root, a);
		vis[a]++;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (vis[a] && vis[b]) {
			node* p = LCA(root, a, b);
			int c = p->data;
			if (c == a)
				printf("%d is an ancestor of %d.\n", a, b);
			else if (c == b)
				printf("%d is an ancestor of %d.\n", b, a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, c);
		}
		else {
			if (!vis[a] && !vis[b])
				printf("ERROR: %d and %d are not found.\n", a, b);
			else if (!vis[a])
				printf("ERROR: %d is not found.\n", a);
			else if (!vis[b])
				printf("ERROR: %d is not found.\n", b);
		}
	}
	return 0;
}
*/ 
