#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n,maxx = -1;
vector<int> v;
bool check(int x){
    int t = x;
    for(int i=0;i<n;i++){
        t += t-v[i];
        if(t<0)return false;
        if(t>maxx)return true;
    }
    return true;
}

int main(){
    scanf("%d",&n);
    v.resize(n);

    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]>maxx)
            maxx = v[i];
    }
    int l = 0,r = maxx;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}
