#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v; 
	while(n!=0){
		v.push_back(n);
		if(n%2==1)
			n=n-1;
		else
			n=n/2;
	}
	vector<int>::iterator it=v.end();
	for(;it!=v.begin();it--){
		cout<<*(it-1)<<' ';
	}
	return 0;
}
