//普通算法 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    vector<int> v;
    if(a.size()>b.size()){
        b.insert(0,a.size()-b.size(),'0');
    }else{
        a.insert(0,b.size()-a.size(),'0');
    }
    int c=0;
    for(register int i=a.size()-1;i>=0;i--){
        v.push_back((c + a[i]-'0' + b[i]-'0')%10);
        c = (c+a[i]-'0' + b[i]-'0')/10;
    }
    if(c)v.push_back(c);
    for(register int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
    return 0;
}

/* 
//压9位算法
#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % base);
        t /= base;
    }

    if (t) C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (a[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)//因为int的最大长度为9位  
        {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (b[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add(A, B);

    cout << C.back();
    for (int i = C.size() - 2; i >= 0; i -- ) printf("%09d", C[i]);
    cout << endl;

    return 0;
}
*/ 
