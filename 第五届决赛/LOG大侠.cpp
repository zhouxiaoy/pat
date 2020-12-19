#include <iostream>
#include <cmath>
using namespace std;
int arr[100005];
int modify(int x) {
	int n = log(x) /log(2);
	return n+1;
}
int main() {
	int n, m;
	int a, b;
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//cout<<sum;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			int t = modify(arr[j]);
			sum = sum - arr[j] + t;
			arr[j] = t;
		}
		for(int i=1;i<=n;i++)
			cout<<arr[i]<<' ';
		cout <<"sum:"<< sum << endl;
	}
	return 0;
}

