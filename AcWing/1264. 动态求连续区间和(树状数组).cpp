#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int st,n,m,sum[N];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)) sum[i]+=v;
}

int tot(int x){
    int ans = 0;
    for(int i = x;i>0;i-=lowbit(i)) ans+=sum[i];
    return ans;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&st);
        add(i,st);
    }
    
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a == 0)//ÇóºÍ
            printf("%d\n",tot(c)-tot(b-1));
        else
            add(b,c);
    }
    return 0;
}
