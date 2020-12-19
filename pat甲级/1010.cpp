//自己版本的会超时 不想优化了 代码在1010里面24分的那个 
/*
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto it = n.rbegin(); it != n.rend(); it++) {
		temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}

long long find_radix(string n, long long num) {
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
	long long high = max(num, low);
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long t = convert(n, mid);
		if (t < 0 || t > num) high = mid - 1;
		else if (t == num) return mid;
		else low = mid + 1;
		}
	return -1;
}
int main() {
		string n1, n2;
		long long tag = 0, radix = 0, result_radix;
		cin >> n1 >> n2 >> tag >> radix;
		result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) :
	find_radix(n1, convert(n2, radix));
		if (result_radix != -1) {
			printf("%lld", result_radix);
		} else {
			printf("Impossible");
		}
	return 0;
}
*/
//自己版本的会超时 不想优化了 代码在1010里面24分的那个 

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int num[10005];

long long convert(string n, long long radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto it = n.rbegin(); it != n.rend(); it++) {
		temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}

int main() {
	string str[3];
	long long tag, radix;
	cin >> str[1] >> str[2] >> tag >> radix;
	//将已知的转化为10进制
	long long sum = convert(str[tag], radix);

	//找出最小的进制
	tag = tag == 1 ? 2 : 1;
	char it = *max_element(str[tag].begin(), str[tag].end());
	long long begin = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	
	//因为 longlong可能会越界变成负数 所以要max(sum,minn)
	long long end = max(sum, begin);
	while (begin <= end) {
		long long mid = (begin + end) / 2;
		long long tot = convert(str[tag], mid);
		if (tot<0 || tot>sum)
			end = mid - 1;
		else if (tot == sum) {
			printf("%lld", mid);
			return 0;
		}
		else begin = mid + 1;
	}
	puts("Impossible");
	return 0;
}
