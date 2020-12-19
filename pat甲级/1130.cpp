#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

bool vis[25];
int v[25][2];
string da[25];

string dfs(int root){
    //Ҷ�ӽ�㣬ֱ�ӷ���
    if(v[root][0] == -1 && v[root][1] == -1)
        return da[root];
    
    //����������
    string str = "(";
    if(v[root][0] != -1)
        str += dfs(v[root][0]);
    
    //�������ڵ�
    str += da[root];
    
    //����������
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
	
	//���ֻ��һ���ַ�����ֱ�Ӵ�ӡ
	if(n == 1){
	    cout<<da[1];
	    return 0;
	}
	
	//�ҵ����ڵ�
	int root;
	for(int i=1;i<=n;i++)
	    if(vis[i] ==  false){
	        root = i;
	        break;
	    }
	
	string final = dfs(root);
	//���������һ������
	for(int i=1;i<final.size()-1;i++)
	    printf("%c",final[i]);
	return 0;
} 
