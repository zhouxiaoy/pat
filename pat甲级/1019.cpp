#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> to_b_string(int n,int b){
	vector<int> v;
	while(n>0){
		v.push_back(n%b);
		n/=b;
	}
	return v;
}

bool isPalindromic(vector<int> &v){
	for(int i=0,k=v.size()-1;i<v.size()&&k>=0;i++,k--){
		if(v[i]!=v[k])
			return false;
	}
	return true;
}

int main(){
	int n,b;
	cin>>n>>b;
	vector<int> v = to_b_string(n,b);
	if(isPalindromic(v))
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d",v[v.size()-1]);
	for(int i=v.size()-2;i>=0;i--)
		printf(" %d",v[i]);
	return 0;
}
