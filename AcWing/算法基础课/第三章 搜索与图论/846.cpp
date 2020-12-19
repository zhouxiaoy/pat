#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N  = 100010,M = 2*N;

// h�ڽӱ��ͷ, e�ڽӱ�ı�, ne �ڽӱ�ͷ����һ�����,idx�õ����±�
int n,h[N], e[M], ne[M],idx = 0;

int cnt = N;
bool vis[N];

//��ͼ
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

int dfs(int u){
    vis[u] = true;
    
    //ansΪ��ǰ���������������,sumΪ��ǰ���Ľ������
    int ans = 0, sum = 1;
    for(int i = h[u];i != -1; i = ne[i]){
        int j = e[i];
        if(vis[j]) continue;
        
        int s = dfs(j);
        ans = max(ans,s);
        sum += s;
    }
    //cout<<u<<"�Ľ������Ϊ:"<<sum<<endl;
    //�Ƚ� u����������������  ��   ����u���Ľ��֮��Ľڵ���
    //���� ��u���ȥ����, u�ĸ�����ͨ�� �����ֵ
    ans = max(ans, n - sum);
    cnt = min(cnt, ans);
    return sum;
}

int main(){
    cin>>n;
    //��ʼ��,������-1��ʾΪNULL
    memset(h, -1, sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        //��������ͼ
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<< cnt;
    return 0;
}
