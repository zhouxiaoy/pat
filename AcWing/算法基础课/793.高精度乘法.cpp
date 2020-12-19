//不要一位一位乘，再进行相加，比较麻烦 
#include <iostream>
#include <vector>
using namespace std;

 vector<int> v;

void mul(const string & a,const int b){
	
	int t=0;//进位 
	for(int i=a.size()-1;i>=0||t;i--){
		if(i>=0)
			t += (a[i]-'0') * b;
		//cout<<"t:"<<t<<endl;
		v.push_back(t%10);
		t /= 10; 
	}
}

int main(){
	string a;
	int b;
	cin>>a>>b;
	
	mul(a,b);
	
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	return 0;
}
