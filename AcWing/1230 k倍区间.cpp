#include<iostream>
using namespace std;
const int N=100010;
typedef long long ll;
int sum[N],a[N],res[N];
int n,k;
ll ans=0;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i])%k;//前缀和取模
        ans+=res[sum[i]];//更新答案
        res[sum[i]]++;//两个相等的前缀和就能组成一个k倍区间
    }
    cout<<ans+res[0]<<endl;
    return 0;
}
