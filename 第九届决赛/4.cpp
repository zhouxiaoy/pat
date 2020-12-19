#include <iostream>
using namespace std;
int main() {
	int a[100005] = { 0 }, n, k;
	int max = 0;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		a[i] = i % k + i / k;
		for (int j = 1; j <a[i]; j++) {
			int temp = (k*j) % n;
			if(i<temp)
				continue;
			if (i - temp + j < a[i])
				a[i] = i - temp + j;
		}
		if (a[i] > max)
			max = a[i];
		//cout << a[i] << ' ';
	}
	cout << max;
	return 0;
}
