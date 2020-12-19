#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int dp[1010][1010];//代表从i到j的字符串是否为回文子串 
int main(){
	int ans=1;
	string str;
	getline(cin,str);
	for(int i=0;i<str.size();i++){
		dp[i][i]=1;
		if(i<str.size()-1&&str[i]==str[i+1]){
			dp[i][i+1]=1;
			ans = 2;
		}
	}
	
	for(int L=3;L<=str.size();L++){
		for(int i=0;i+L-1<str.size();i++){
			if(str[i]==str[i+L-1]&&dp[i+1][i+L-2]==1){
				dp[i][i+L-1] = 1;
				ans=L;
			}
		}
	}
	printf("%d",ans);
	return 0; 
} 
//这个 马拉车算法时间更短 但是不理解 
/*
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Manacher(string s) {
	// Insert '#'
	string t = "$#";
	for (int i = 0; i < s.size(); ++i) {
		t += s[i];
		t += "#";
	}
	// Process t
	vector<int> p(t.size(), 0);
	int mx = 0, id = 0, resLen = 0, resCenter = 0;
	for (int i = 1; i < t.size(); ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (t[i + p[i]] == t[i - p[i]]) ++p[i];
		if (mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		if (resLen < p[i]) {
			resLen = p[i];
			resCenter = i;
		}
	}
	return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
	string str;
	getline(cin, str);
	cout << Manacher(str).size() << endl;
	return 0;
}
*/
