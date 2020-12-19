#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N  = 100010,M = 2*N;

// h邻接表的头, e邻接表的边, ne 邻接表头的下一个结点,idx用到的下标
int n,h[N], e[M], ne[M],idx = 0;

int cnt = N;
bool vis[N];

//建图
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

int dfs(int u){
    vis[u] = true;
    
    //ans为当前子树结点的最大数量,sum为当前树的结点数量
    int ans = 0, sum = 1;
    for(int i = h[u];i != -1; i = ne[i]){
        int j = e[i];
        if(vis[j]) continue;
        
        int s = dfs(j);
        ans = max(ans,s);
        sum += s;
    }
    //cout<<u<<"的结点数量为:"<<sum<<endl;
    //比较 u的子树结点最大数量  和   除了u树的结点之外的节点数
    //就是 把u结点去掉后, u的各个连通块 的最大值
    ans = max(ans, n - sum);
    cnt = min(cnt, ans);
    return sum;
}

int main(){
    cin>>n;
    //初始化,链表以-1表示为NULL
    memset(h, -1, sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        //建立有向图
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<< cnt;
    return 0;
}
