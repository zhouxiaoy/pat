#include <iostream>
#include <algorithm>

using namespace std;
int a[100010];
int b[100010];
int main(){
    int n,k,res=0;
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        res+=a[i];
        b[i+1]=res;
    }
    
    res =0;
    for(int i=0;i+k<=n;i++)
        res = max(res,b[k+i]-b[i]);

    cout<<res<<endl;
    return 0;
}
