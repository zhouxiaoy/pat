//这道题太夸张了 我调试了 快两个小时
//需要好好复习 

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int vis[256];
vector<char> v;
bool visit[256];

int main(){
	int k;
	string str;
	cin>>k>>str;
	int ans = 1;
	for(int i=1;i<str.size();i++){
		if(str[i] == str[i-1]){
			ans++;
		}else{
			if(vis[str[i-1]] != 1  && ans >= k && ans % k == 0){
				v.push_back(str[i-1]);
				vis[str[i-1]] = 2;
				//cout<<i-1<<' '<<str[i-1]<<endl;
			} else{//该字符不是重复的 
				vis[str[i-1]] = 1;
			} 
			ans = 1;
		}
	}
	
	int i = str.size()-1;
	if(vis[str[i-1]] != 1  && ans >= k && ans % k == 0){
				v.push_back(str[i-1]);
				vis[str[i-1]] = 2;
				//cout<<i-1<<' '<<str[i-1]<<endl;
			} else{//该字符不是重复的 
				vis[str[i-1]] = 1;
			} 
    
	for(auto v1:v)
		if(vis[v1] == 2 && !visit[v1]){
			printf("%c",v1);
			visit[v1] = true;
        }
	ans = 1;
	printf("\n%c",str[0]);
	for(int i=1;i<str.size();i++){
		if(vis[str[i]] == 2 && str[i] == str[i-1] && ans++ < k)continue; 
		printf("%c",str[i]);
		ans = 1;
	}
	return 0;
} 
