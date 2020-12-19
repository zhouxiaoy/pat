//待优化 VIP只能使用VIP桌子 

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int arr_time, play_time;
	bool isVIP;
	int wait_time;
};

bool cmp(node a, node b) {
	return a.arr_time < b.arr_time;
}

bool cmp1(node a, node b) {
	return a.arr_time + a.wait_time < b.arr_time + b.wait_time;
}

vector<node> peo, vip_peo;
vector<node> all_peo;
int tables[105];//桌子可以空闲的时间 
int tables_sum[105];//桌子服务的数量 
bool tables_isVIP[105];//桌子是否为vip 

int main() {

	int n, k, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, c;
		node a;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &a.play_time, &c);
		a.play_time *= 60;
		a.arr_time = hh * 3600 + mm * 60 + ss;
		if (c == 0) { //如果不是vip
			a.isVIP = false;
			peo.push_back(a);
		}
		else {
			a.isVIP = true;
			vip_peo.push_back(a);
		}
	}

	sort(peo.begin(), peo.end(), cmp);
	sort(vip_peo.begin(), vip_peo.end(), cmp);

	scanf("%d %d", &k, &m);

	for (int i = 0; i < m; i++) {
		int c;
		scanf("%d", &c);
		tables_isVIP[c] = true;
	}

	fill(tables + 1, tables + k + 1, 28800);

	for (int i = 0, j = 0; i + j < n && i < peo.size() && j < vip_peo.size();) {//i是普通人，j是VIP 
		//找到最早空闲的桌子 
		int u = -1, minn = 0x3f3f3f3f;
		for (int v = 1; v <= k; v++) {
			if (tables[v] < minn) {
				minn = tables[v];
				u = v;
			}
		}
		//VIP必须使用VIP桌子
		if (vip_peo[j].arr_time < peo[i].arr_time && !tables_isVIP[u]) {
			u = -1, minn = 0x3f3f3f3f;
			for (int v = 1; v <= k; v++) {
				if (tables_isVIP[v] && tables[v] < minn) {
					minn = tables[v];
					u = v;
				}
			}
		}

		if (u == -1)break;
		//是VIP桌子 
		if (tables_isVIP[u] == true) {
			if (vip_peo[j].arr_time <= tables[u] || vip_peo[j].arr_time < peo[i].arr_time) {
				if (vip_peo[j].arr_time <= tables[u])
					vip_peo[j].wait_time = tables[u] - vip_peo[j].arr_time;
				else
					vip_peo[j].wait_time = 0;
				//不满两小时
				if (vip_peo[j].play_time <= 7200)
					tables[u] += vip_peo[j].play_time;
				else
					tables[u] += 7200;
				all_peo.push_back(vip_peo[j]);
				j++;
			}
			else {
				if (peo[i].arr_time <= tables[u])
					peo[i].wait_time = tables[u] - peo[i].arr_time;
				else
					peo[i].wait_time = 0;
				//不满两小时
				if (peo[i].play_time <= 7200)
					tables[u] += peo[i].play_time;
				else
					tables[u] += 7200;
				all_peo.push_back(peo[i]);
				i++;
			}
			tables_sum[u]++;

		}
		//不是VIP桌子的话，找出最早到达的人 
		else {
			if (vip_peo[j].arr_time < peo[i].arr_time) {
				if (vip_peo[j].arr_time <= tables[u])
					vip_peo[j].wait_time = tables[u] - vip_peo[j].arr_time;
				else
					vip_peo[j].wait_time = 0;
				//不满两小时
				if (vip_peo[j].play_time <= 7200)
					tables[u] += vip_peo[j].play_time;
				else
					tables[u] += 7200;
				all_peo.push_back(vip_peo[j]);
				j++;
			}
			else {
				if (peo[i].arr_time <= tables[u])
					peo[i].wait_time = tables[u] - peo[i].arr_time;
				else
					peo[i].wait_time = 0;
				//不满两小时
				if (peo[i].play_time <= 7200)
					tables[u] += peo[i].play_time;
				else
					tables[u] += 7200;
				all_peo.push_back(peo[i]);
				i++;
			}
			tables_sum[u]++;
		}
	}
	sort(all_peo.begin(), all_peo.end(), cmp1);
	for (int i = 0; i < all_peo.size(); i++) {
		int t = all_peo[i].arr_time + all_peo[i].wait_time;
		printf("%02d:%02d:%02d %02d:%02d:%02d %02d\n", all_peo[i].arr_time / 3600, all_peo[i].arr_time / 60 % 60, all_peo[i].arr_time % 60, t / 3600, t / 60 % 60, t % 60, (all_peo[i].wait_time + 30) / 60);
	}
	return 0;
}
