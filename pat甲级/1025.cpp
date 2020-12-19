#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	vector<vector<int>> 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	return 0;
} #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node {
	string Id;
	int score;
	int r, local;
};

bool cmp(node a, node b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.Id < b.Id;
}

int main() {
	int n, m;
	scanf("%d", &n);
	vector<node> tot;
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		vector<node> v1;
		node Node;
		for (int j = 0; j < m; j++) {
			cin >> Node.Id >> Node.score;
			Node.local = i + 1;
			v1.push_back(Node);
		}
		sort(v1.begin(), v1.end(), cmp);
		if (v1.size() != 0) {
			v1[0].r = 1;
			tot.push_back(v1[0]);
			for (int k = 1; k < v1.size(); k++) {
				if (v1[k].score == v1[k - 1].score)
					v1[k].r = v1[k - 1].r;
				else
					v1[k].r = k+1;
				tot.push_back(v1[k]);
			}
		}

	}
	sort(tot.begin(), tot.end(), cmp);
	int rank = 1;
	cout << tot.size() << endl;
	if (tot.size() != 0) {
		cout << tot[0].Id << ' ' << rank << ' ' << tot[0].local << ' ' << tot[0].r << endl;
		for (int i = 1; i < tot.size(); i++) {
			if (tot[i].score != tot[i - 1].score)
				rank = i + 1;
			cout << tot[i].Id << ' ' << rank << ' ' << tot[i].local << ' ' <<tot[i].r << endl;
		}
	}
	return 0;
}
