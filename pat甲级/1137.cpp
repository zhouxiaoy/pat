//出现了一个问题 ，没参加期末考的也算进去了，要小心 
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

struct node {
	string id;
	int p, mid = -1, final, G;//积分，期中，期末,平均分
};

int ans = 1, n, m, p;
unordered_map<string, int> mp;
node nod[10005];
vector<node> v;

bool cmp(node a, node b) {
	if (a.G != b.G)
		return a.G > b.G;
	else
		return a.id < b.id;
}

//网上测试分数
int main() {
	scanf("%d%d%d", &p, &m, &n);
	string id;
	int score,t;
	for (int i = 0; i < p; i++) {
		cin >> id >> score;
		if (score >= 200) {
			nod[ans].id = id;
			nod[ans].p = score;
			mp[id] = ans;
			ans++;
		}
	}

//其中考试
	for (int i = 0; i < m; i++) {
		cin >> id >> score;
		t = mp[id];
		if (t > 0)//该节点已经存在 
			nod[t].mid = score;
		//不存在代表p不满200分，舍弃该节点
	}

	//期末
	for (int i = 0; i < n; i++) {
		cin >> id >> score;
		t = mp[id];
		if (t > 0) {
			nod[t].final = score;
			nod[t].G = score;
			if (nod[t].mid > nod[t].final)
				nod[t].G = (int)(0.5 + nod[t].mid * 0.4 + nod[t].final * 0.6);
			if (nod[t].G < 60)  mp[id] = -1;//分数不达标，舍弃结点，标记为-1
		}
	}
	//整合，存入V
	for (auto it = mp.begin(); it != mp.end(); it++) {
		t = it->second;
		//这里有可能，有人没参加期末考试，要去掉
		if (t > 0 && nod[t].final > 0)
			v.push_back(nod[t]);
	}

	sort(v.begin(), v.end(), cmp);
	for (auto v1 : v)
		printf("%s %d %d %d %d\n", v1.id.c_str(), v1.p, v1.mid, v1.final, v1.G);
	return 0;
}
