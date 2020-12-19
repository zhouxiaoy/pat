#include <iostream>
#include <unordered_map>
using namespace std;
map<int,int> mp;
int main(){
	int a,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>0)
			mp[a]++;
	}
	
	for(int i=1;i<INT_MAX;i++){
		if(mp[i]==0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
