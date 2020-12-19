#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int n){
	if(n<2)return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i == 0)
			return false;
	}
	return true;
}

int main(){
	int l,k;
	string str;
	cin>>l>>k>>str;
	
	for(int i=0;i<=l-k;i++){
		string t = str.substr(i,k);
		int num = stoi(t);
		if(isPrime(num)){
			cout<<t;
			return 0;
		}
	}
	puts("404");
	return 0;
}
