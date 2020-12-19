#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// ���򣬺���תǰ��ǰ������ת����������Ҫ��Ϥ
/* 
 * ǰ��ĵ�һ�����������ĸ�
 * ��������һ�����������ĸ�
 * ���������б����������Ļ���
 * ǰ�����������������ֵĵ�һ���ڵ����������ĸ��ڵ�
 * ǰ�����������������ֵĵ�һ���ڵ����������ĸ��ڵ� 
 
 * ǰ�� ����  ת ����
 * 0.if(l > r) return ; 
 * 1.in�д�l��r�ҵ����ڵ�
 * 2.dfs(root+1,l,i-1);������  ��l��i-1����������
 * 3.dfs(root+1-(i-l)(�������ĳ���),i+1,r);//�ҵ��������ĸ��ڵ�  ��ǰ���ڵ�+1������������ 
 * 
 * ���� ����  ת ǰ��
 * 0.ͬ�� 
 * 1.ͬ�� 
 * 2.dfs(root-1-(r-i)(����������),l,i-1); 
 * 3.dfs(root-1,i+1,r);
 */ 
//1004  ������� bfs  dfs 
/*
 * ���ﲻ��ʹ��bfs ��Ϊ��� �� 1  2 �����ӽڵ㣬����1���ʱ�Ὣ1���ӽڵ���룬��Ӱ�����ķֽ�
 * ���� ����bfsֻ��Ҫÿ�μ�¼�µ�ǰ�����½��ĸ��� ��1004 ���������� 
 * ��ֻ��Ҫ���Լ��Ƿ���Ҷ��� ���� ������Ҫ���ӽڵ㣬�ӽڵ�ͨ��forѭ���ݹ� 
*/ 

/* 
int maxlevel = 0;
vector<int> v[105];
int sum[105];
void dfs(int node,int level){
    if(level>maxlevel)maxlevel = level;
    if(v[node].size() == 0) {
        sum[level]++;
        return;//�ýڵ�û�к���
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
 * ����Ҫ������ô�����������ķ�Χ ���������ķ�Χ 
 * �Լ����鷳����ʵ����Ҫpost�ķ�Χ��ֻҪ�Ѹ��ڵ��ֵ���������ͳ��� 
 * root�Ǻ�׺�ĸ��ڵ㣬root-1 �����������ĸ��ڵ㣬root - �������ĳ��ȣ�end-i��-1 �����������ĸ��ڵ� 
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
	//�ҵ�in�еĸ����
	int x = post[pr];//�������һ��Ϊ���ڵ�
	for(int i=il;i<=ir;i++){
		if(x == in[i]){//�ҵ����ڵ� 
			//length = ir - i;//�������ĳ���
			//length = i - il;//�������ĳ���
			v[dep].push_back(x);
			dfs(pl,pr-ir+i-1,il,i-1,dep+1);//����������
			dfs(pr-ir+i,pr-1,i+1,ir,dep+1);
			//������ ȥ����׺�ķ�Χ��ֻ��������ķ�Χ �Ѹ��ڵ㴫���� 
			//dfs(root-1-r+i,l,i-1,dep+1);//����������
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

//1043 BST���������
/*
 * ����Ҫ�����ӡ ֻҪ�ȴ��� ���������������������Ѹ��ڵ����
 * Ѱ�ҷ�Χ Ҫ��ȷ �����ҵ����ڵ�ȥ
 * BST��һ������ȫ�������������ڣ���Щ���е��ڣ����ڵ��Ϊ��������С�ڵ�Ϊ������ 
*/ 

/* 
int node[1005];//���
int isMir = false;//�Ƿ�Ϊ��BST
vector<int> v;
void toPost(int l,int r){
	if(l>r)return;
	int i = l+1,j = r;
	if(!isMir){
		while(i<=r && node[i]<node[l]) i++;
		while(j>l && node[j]>=node[l]) j--; //j>l������벻����ȣ�lΪ���ڵ㣬���ܻ�Ϊ�������� 
	}else{
		while(i<=r && node[i]>=node[l]) i++;
		while(j>l && node[j]<node[l]) j--; //ͬ�� 
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

//1053  ���ı���
/*
 * ��Ϊ�Ӹ���㵽Ҷ����·��Ψһ ����һ��ʼ��ֱ�Ӽ����Ȩ��֮�� ��������Ҫ��ӡ
 * ·�������������������
 * ���Բ���dfs�����������߹���·������������ϻ��ݣ�ɾ�����һ��·������������ӡ 
*/
/* 
int w[105];//����Ȩ��
vector<int> path;
vector<int> v[105];//�ڽӱ�����ýڵ��µ��ӽ�� 

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
 
//1066 AVLģ���� �� AVL 


//1079  dfs  bfs ���ı��� 
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

//1086 ���ı���
//Ҫ��� ��ջģ�����ı�������
//��һ�������stack��������������ǿ��Եõ�����ǰ������������
//����ĺ���Ҫ
//���һ��Ҫע����ǣ���Ŀû���� ������ͬ���������ǿ������±���棨��Ȼ��ͬʱ����rootʱ����� 
/* 
//��һ��vector<int> val;int key=0;ÿ�����±���������������ͬ���ֵ����� 
vector<int> pre, in, post;
stack<int> s;

void turnToPost(int l, int r, int root) {
	if (l > r)return;
	else if (l < r) {
		int i = l;
		//�ҵ����ڵ�
		while (i <= r && in[i] != pre[root])i++;
		turnToPost(l, i - 1, root + 1);
		turnToPost(i + 1, r, root + i - l + 1);
	}
	//ֻ��һ�����ʱ���򣬱��������������󱣴���ڵ�
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

//1090 ��ı���
//�뵱Ȼ�ˣ���ǰ����ȴ��������ȣ����ǵ�ǰ����ȵ��������ȵķ�����

/* 
vector<int> v[100005];
 
int maxDep = -1,maxSum= 0;
void dfs(int root,int dep){
	if(v[root].size() == 0){
		if(maxDep == dep)
			maxSum++;
		//else{//֮ǰ������ 
		else if(maxDep<dep){//�������ʱmaxDep<dep  ֮ǰ�õ���ֱ��else �����һ������� 
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

//1094  ���Ĳ������ ûʲô�ѵ������ 

//1099 ���Ĳ������ BST   û�뵽 ������ 
/*
	������index����ȫ���������±꣩��label��������
	������ͬһ���ǰ��˳�� 
	��dfs��������ݣ���dfsʵ�������������BST�����Խ�ϣ������data�Ǵ�С����ģ� 
*/ 

//1102  ���Ĳ������ �� �������  д���� 1099���ƣ�������dfs�еõ����������
//1106  ������� ��dfs��bfsʵ�� ��bfsҪ�趨һ����������Ҫ�� 
//1110  ���ı��� д����1102 1099 ����
//������һ���ش�ʧ��  ��Ϊ�����Ľ����<20�ģ�����char����
//���³��ֶδ���  Ӧ����string ����stoi ת��Ϊ����

//1115 BST ģ��BST�Ĺ��� û̫�����⣬BST�ı��� 
//1143 LCA �����������   1151��LCA + preorder + inorder 
/*
 *����������BST�������ǹ������ȵĻ�(��������֮��)���ض����������ĸ��ڵ�(a)����������(LCA)���������ĸ��ڵ�(b) 
 *��һ��������� a��b������һ������(LCA)
 *��һ��map���Ը��ĸ�����һ�£������Ժ�鿴�Ƿ�ýڵ��Ƿ������У������������� 
*/
/*
//��ȷ�汾�ɿ�1143 
//���Ϊ��ʱ�汾������BST������ʹ��LCA�����ҳ��� 
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
	if (x < root->data)//����������
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
