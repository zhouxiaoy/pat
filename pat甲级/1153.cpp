#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector> 
using namespace std;

struct node {
	string ID;
	int score;
};

bool cmp(node a,node b){
	return a.value != b.value ? a.score > b.score : a.ID < b.ID;
}

node a[1005];
int num[1000];
bool vis[1000];
unordered_map<string,int> mp;
int main(){
	int m,n,t,tot = 1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin>>a[i].ID>>a[i].score;
	
	//sort(a,a+n,cmp);
	/*
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].ID<<' '<<a[i].score<<endl;
	}
	*/
for (int i = 1; i <= k; i++) {
	cin >> num >> s;
	printf("Case %d: %d %s\n", i, num, s.c_str());
	vector<node> ans;
	int cnt = 0, sum = 0;
	if (num == 1) {
		for (int j = 0; j < n; j++)
			if (v[j].t[0] == s[0]) ans.push_back(v[j]);
	}
	else if (num == 2) {
		for (int j = 0; j < n; j++) {
			if (v[j].t.substr(1, 3) == s) {
				cnt++;
				sum += v[j].value;
			}
		}
		if (cnt != 0) printf("%d %d\n", cnt, sum);
	}
	else if (num == 3) {
		unordered_map<string, int> m;
		for (int j = 0; j < n; j++)
			if (v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
		for (auto it : m) ans.push_back({ it.first, it.second });
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int j = 0; j < ans.size(); j++)
		printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
	if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt ==
		0)) printf("NA\n");
}
	return 0;
} 
