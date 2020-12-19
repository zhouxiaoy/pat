#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e8 + 10;
int v[N];
int main(){
    int n;
    cin>>n;

    for(int i=0;i*i*2<= n;i++)
        for(int j = i;j*j+i+i <= n;j++)
            if(!v[i*i+j*j])
                v[i*i+j*j] = i+1;
    
    for(int i=0;i*i*4<=n;i++){
        for(int j = i;i*i + j*j<= n/2;j++){
            int t = n - i*i - j*j;
            if(!v[t])continue;
            
            int c = v[t]-1;
            int d = sqrt(t - c*c);
            cout<<i<<' '<<j<<' '<<c<<' '<<d;
            return 0;
            
        }
    }
    return 0;
}
/* 
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a1 = sqrt(n/4);
    for(int i=0;i<=a1;i++){
        int b1 = sqrt((n-i*i)/3);
        for(int j=i;j<=b1;j++){
            int c1 = sqrt((n-i*i-j*j)/2);
            for(int k = j;k<=c1;k++){
                int d = n-i*i-k*k-j*j;
                int d1 = sqrt(d);
                if(d1*d1 != d)continue;
                cout<<i<<' '<<j<<' '<<k<<' '<<d1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
*/ 
