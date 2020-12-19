//习惯了减1 所以出错了，是我傻逼了 
//我还特判空格，有点蠢 
#include <iostream>
#include <string>
using namespace std;

bool vis[300];

int main(){
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	for(int i=0;i<str2.size();i++){ 
		vis[str2[i]] = true;
	}
	for(int i=0;i<str1.size();i++)
		if(!vis[str1[i]])
			cout<<str1[i];
	return 0;
} 
