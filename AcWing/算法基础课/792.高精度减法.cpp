//过程 
//如果a大于b，则直接相减a-b 
//如果a<b，计算b-a，结果为-（b-a） 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
string a,b;

bool cmp(const string &a,const string &b){
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])continue;
		else if((a[i]-'0')>(b[i]-'0'))return true;
		else return false;
	}
	//如果都相同 则直接相减 
	return true;
}

void sub(const string &a,const string &b){
	if(!cmp(a,b))  {
		sub(b,a);
		v[b.size()-1] = -v[b.size()-1];
		return;
	}
	int t = 0;//借位 
	for(int i=a.size()-1;i>=0;i--){
		int temp = a[i]-'0' - (b[i]-'0') + t;
		
		if(temp<0) {
			t = -1;
			temp += 10;
		}else
			t = 0;
		v.push_back(temp);
	}
} 

int main(){
    cin>>a>>b;
    if(a.size()>b.size()){
        b.insert(0,a.size()-b.size(),'0');
    }else{
        a.insert(0,b.size()-a.size(),'0');
    }
    sub(a,b);
    int i=v.size()-1;
    while(i>=1 && v[i]==0)i--;//要吃掉前面的0
    for(;i>=0;i--){
        cout<<v[i];
    }
    
    return 0;
}

//y总版本  特色在sub里的减法运算 
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i -- )
        if (A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    vector<int> C;

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << '-';

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}

