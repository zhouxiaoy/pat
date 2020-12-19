#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void div(const string & a,const int b, int &r){
	int c=0;
	for(int i=0;i<a.size();i++){
		c = a[i]-'0'+ c*10;
		v.push_back(c/b);
		c=c%b;
	}
	r = c;
}

int main(){
	string a;
	int b;
	cin>>a>>b; 
	
	int r;
	div(a,b,r);
	int i=0;
	while(i<v.size()&&v[i]==0)i++;
	for(;i<v.size();i++)
		cout<<v[i];
	cout<<endl<<r<<endl; 
	return 0;
} 
