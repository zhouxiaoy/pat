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
        sum[i]=(sum[i-1]+a[i])%k;//ǰ׺��ȡģ
        ans+=res[sum[i]];//���´�
        res[sum[i]]++;//������ȵ�ǰ׺�;������һ��k������
    }
    cout<<ans+res[0]<<endl;
    return 0;
}
