#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cstdio>

using namespace std;

struct node {
	int score;
	int sum;
	string school;
};

unordered_map<string, int> sum;
unordered_map<string, double> s;

bool cmp(node a, node b) {
	if (a.score != b.score)
		return a.score > b.score;
	else if(a.sum != b.sum)
		return a.sum < b.sum;
	else
	    return a.school < b.school;

}

int main() {
	int n;
	cin >> n;
	double score;
	string id, name;
	for (int i = 0; i < n; i++) {
		cin >> id ;
		scanf("%lf",&score);
		cin >> name;
		for (int j = 0; j < name.size(); j++)
			name[j] = tolower(name[j]);
		if (id[0] == 'B')score /= 1.5;
		else if (id[0] == 'T') score *= 1.5;
		sum[name]++;
			s[name] += score;
	}
	vector<node> ve;
	for (auto it = sum.begin(); it != sum.end(); it++)
		ve.push_back(node{(int)s[it->first],sum[it->first],it->first});
	sort(ve.begin(), ve.end(), cmp);
	printf("%d\n",ve.size());
	int ans = 1;
	for (int i = 0; i < ve.size(); i++) {
		if (i == 0)
			cout << "1 " << ve[0].school << ' ' << (int)ve[0].score <<' '<< ve[0].sum << endl;
		else if (ve[i].score == ve[i - 1].score)
			cout << ans << ' ' << ve[i].school << ' ' << (int)ve[i].score <<' '<< ve[i].sum << endl;
		else {
		    ans = i + 1;
			cout << ans << ' ' << ve[i].school << ' ' << (int)ve[i].score <<' '<< ve[i].sum << endl;
		}
	}
	return 0;
}

