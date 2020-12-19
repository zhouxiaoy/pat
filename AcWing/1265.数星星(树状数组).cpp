#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 32005;
int n,st[N],level[N];

int lowbit(int x){
    return x & -x;
}

int sum(int x){
    int ans = 0;
    for(int i=x ; i ; i -= lowbit(i)) ans += st[i];
    return ans;
}

void add(int x){
    for(int i=x ; i<N ; i += lowbit(i)) st[i]++;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        x++;
        level[sum(x)]++;
        add(x);
    }
    
    for(int i=0;i<n;i++)cout<<level[i]<<endl;
    return 0;
}
