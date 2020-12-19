#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
long int a[200005], b[200005];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%ld", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%ld", &b[i]);
	int i = 1, j = 1, k = 0;
	long int ans = 0;
	while (i <= n && j <= m && k < (n + m + 1) / 2) {
		if (a[i] <= b[j]) {//如果a数组的数字大
			ans = a[i];
			i++;
			k++;
		}
		else {
			ans = b[j];
			j++;
			k++;
		}
	}
	//cout << i << ' ' << j <<' '<<k<< endl;
	if (k == (n + m + 1) / 2) {
		printf("%ld\n", ans);
		return 0;
	}
	while (i != n+1) {
		printf("%ld\n", a[i + (n + m -1) / 2 - k]);
		return 0;
	}
	while (j != m+1) {
		printf("%ld\n" ,b[j + (n + m-1) / 2 - k]);
		return 0;
	}
	return 0;
}
