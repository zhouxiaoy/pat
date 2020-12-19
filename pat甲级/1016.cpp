#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	string name;
	int status, month, hour, minute, day,time;
};

int rate[25];

bool cmp(node a, node b) {
	if (a.name != b.name)
		return a.name < b.name;
	return a.time<b.time;
}

double CalMoney(node a) {
	int money;
	money = a.minute*rate[a.hour] + a.day*rate[24]  * 60;
	for (int i = 0; i < a.hour; i++) {
		money += rate[i] * 60;
	}
	return money / 100.0;
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	vector<node> v;
	map<string, vector<node>> mp;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		node peo;
		cin >> peo.name;
		scanf("%d:%d:%d:%d", &peo.month, &peo.day, &peo.hour, &peo.minute);
		peo.time = peo.day * 24 * 60 + peo.hour * 60 + peo.minute;
		string status;
		cin >> status;
		peo.status = (status == "on-line") ? 1 : 0;
		v.push_back(peo);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i < n; i++) {
		if (v[i].name == v[i - 1].name&&v[i - 1].status == 1 && v[i].status == 0) {
			mp[v[i - 1].name].push_back(v[i - 1]);
			mp[v[i].name].push_back(v[i]);
		}
	}

	for (auto it : mp) {
		cout << it.first;
		vector<node> t = it.second;
		printf(" %02d\n", t[0].month);
		double total = 0.0;
		for (int i = 1; i < t.size(); i += 2) {
			double money = CalMoney(t[i]) - CalMoney(t[i-1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				t[i - 1].day, t[i - 1].hour, t[i - 1].minute, t[i].day,
				t[i].hour, t[i].minute, t[i].time - t[i - 1].time, money);
			total += money;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
