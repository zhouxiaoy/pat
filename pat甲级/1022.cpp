#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct node {
	string ID, name, author, keywords, publish, pub_time;
};

bool cmp(node a, node b) {
	return a.ID < b.ID;
}
int main() {
	int n,m;
	cin >> n; 
	getchar();
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		getline(cin, v[i].ID);
		getline(cin, v[i].name);
		getline(cin, v[i].author);
		getline(cin, v[i].keywords);
		getline(cin, v[i].publish);
		getline(cin, v[i].pub_time);
	}
	sort(v.begin(), v.end(), cmp);
	/*
	for (int i = 0; i < n; i++) {
		cout << v[i].ID << ' ' << v[i].name << ' ' << v[i].author <<  ' ' << v[i].keywords << ' ' << v[i].publish<<endl;
	}
	*/
	
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++) {
		string str;
		int flag = 0;
		getline(cin, str);
		cout << str << endl;
		str = str.substr(3);
		for (int j = 0; j < n; j++) {
			if (str == v[j].name || str == v[j].author ||
				v[j].keywords.find(str) != -1 || str == v[j].publish || str == v[j].pub_time
				) {
				flag = 1;
				cout << v[j].ID<<endl;
			}
		}
		if (flag == 0)
			cout << "Not Found" << endl;
	}
	return 0;
}
