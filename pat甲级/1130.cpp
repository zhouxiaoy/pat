#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

bool vis[25];
int v[25][2];
string da[25];

string dfs(int root){
    //叶子结点，直接返回
    if(v[root][0] == -1 && v[root][1] == -1)
        return da[root];
    
    //遍历左子树
    string str = "(";
    if(v[root][0] != -1)
        str += dfs(v[root][0]);
    
    //遍历根节点
    str += da[root];
    
    //遍历右子树
    if(v[root][1] != -1)
        str += dfs(v[root][1]);
    str += ")";
    
    return str;
}

int main(){
	int n,l,r;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
	    cin>>da[i];
	    scanf("%d%d",&l,&r);
	    v[i][0] = l;
	    v[i][1] = r;
	    if(l != -1) vis[l] = true;
	    if(r != -1) vis[r] = true;
	}
	
	//如果只有一个字符串，直接打印
	if(n == 1){
	    cout<<da[1];
	    return 0;
	}
	
	//找到根节点
	int root;
	for(int i=1;i<=n;i++)
	    if(vis[i] ==  false){
	        root = i;
	        break;
	    }
	
	string final = dfs(root);
	//最外面多了一个括号
	for(int i=1;i<final.size()-1;i++)
	    printf("%c",final[i]);
	return 0;
} 
