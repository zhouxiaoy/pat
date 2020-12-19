#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);
	string str="0";
	for(int i=0;i<n;i++)
		str=str+v[i];
	int i = 0; 
	while(i<str.size()&&str[i] == '0')i++;
	if(i<str.size())
		for(;i<str.size();i++)cout<<str[i];
	else
		puts("0");
	return 0;
} 
