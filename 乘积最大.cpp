#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	long long a[100005],b[100005];
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	int l = 1, r = n, t = 1;
	while (l < r && t <= k) {
		if (a[l] * a[l + 1] > a[r] * a[r - 1] && t + 1 <= k) {
			b[t++] = a[l];
			b[t++] = a[l + 1];
			l += 2;
		}
		else {
			b[t++] = a[r];
			r++;
		}
	}
	long long sum = b[1];
	cout << "选取的数字为：\n";
	for (int i = 1; i <= k; i++) {
		cout << b[i] << ' ';
		if (i != 1) {
			sum = sum * b[i];
			if (sum < 0)
				sum = 0 - ((0 - sum) % 1000000009);
			else
				sum = sum % 1000000009;
		}
	}
	cout << endl;
	cout << sum;
	return 0;
}
