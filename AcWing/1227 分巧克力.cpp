#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int dx[N],dy[N];//第i块巧克力的长和宽
int n,k,maxx = 0;

bool check(int x){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += (dx[i]/x) * (dy[i]/x);
        if(ans >= k)return true;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&dx[i],&dy[i]);
        maxx = max(maxx,max(dx[i],dy[i]));
    }    
    int l = 1, r = maxx;
    while(l<r){
        int mid = l + r + 1 >> 1;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    cout<<l;
    return 0;
}
