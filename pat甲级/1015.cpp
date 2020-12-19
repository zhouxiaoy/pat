#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
int redix(int n, int d) {
	vector<int> v;
	while (n > 0) {
		v.push_back(n%d);
		n /= d;
	}
	int sum=0,t=1;
	for (int i = v.size() - 1; i >= 0; i--){
		sum += v[i] * t;
		t *= d;
	}
	return sum;
}

bool isPrime(int n) {
	if (n <= 1)return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n, d;
	while (scanf("%d", &n), n > 0) {
		scanf("%d", &d);
		//printf("%d to Dec:%d",n, redix(n, d));
		if (isPrime(n) && isPrime(redix(n, d)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
