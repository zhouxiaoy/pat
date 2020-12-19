//正确 版本 ，用temp，pa标记这是第几条边
//只要 每条边都出现了，Yes 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    vector<int> pa[n];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        pa[a].push_back(i);
        pa[b].push_back(i);
    }
    
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        vector<bool> temp(m,false);
        while(t--){
            scanf("%d",&a);
            for(auto v1:pa[a])
                temp[v1] = true;
        }
        bool flag = true;
        for(int t =0;t<m;t++){
            if(!temp[t])
                flag = false;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}

//错误版本
//用 vis，temp标记哪些点被边用过
//如果vis，和temp数组一样代表，每个点都被用了
//但是如果有一条边没被用过，但每个结点都可能被用过 
/* 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool vis[1005];
vector<int> pa[1005];

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        vis[a] = vis[b] = true;
        pa[a].push_back(b);
        pa[b].push_back(a);
    }
    
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        bool temp[1005]={0};
        while(t--){
            scanf("%d",&a);
            //cout<<"a.size() = "<<pa[a].size()<<endl;
            for(auto v1:pa[a]){
                temp[a] = true;
                temp[v1] = true;
            }
        }
        bool flag = true;
        for(int t =0;t<n;t++){
            printf("%d %d %d\n",t,temp[t],vis[t]);
            if(vis[t] != temp[t]){
                flag = false;
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
*/ 
