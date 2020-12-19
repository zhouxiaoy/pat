//判断是否能够被划分的b，c整除 
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void f(string s,int n){
	int t = s.size()/2;
	long a = stoi(s);
	string str = s.substr(0,t);
	s = s.substr(t,t);
	long b = stoi(str);
	long c = stoi(s);
    
    if(b == 0 || c == 0){//浮点错误，分母为0 
        puts("No");
        return;
    }
    
	if(1.0*a/(b*c) == a/(b*c))
		puts("Yes");
	else
		puts("No");
} 

int main(){
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		f(s,n); 
	}
	return 0;
} 
