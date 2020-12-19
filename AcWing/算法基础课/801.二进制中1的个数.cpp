#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int res = 0,t;
        cin>>t;
        for(int j=t;j;j-= j& -j) res++;
        cout<<res<<' ';
    }
    return 0;
}

