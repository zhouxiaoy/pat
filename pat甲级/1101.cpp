#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
typedef long L;
L a[N], b[N];
vector<L> v;
int main() {
	int n;
	int Lmax = -1;
	scanf("%d", &n);
	for (register int i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && Lmax <= a[i])
			v.push_back(a[i]);
		else if (Lmax < a[i])	Lmax = a[i];

	}
	
	int sum = v.size();
	printf("%d\n", v.size());
	
	for (int i = 0; i < sum - 1; i++) {
		printf("%ld ", v[i]);
	}
	if(v.size()>0) printf("%ld\n",v[sum-1]);
	else puts("");
	return 0;
}
