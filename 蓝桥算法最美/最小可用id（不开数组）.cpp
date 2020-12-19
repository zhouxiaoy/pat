#include <iostream>
using namespace std;
int partition(int *a, int p, int r) {
	if (p > r)
		return -1;
	int t = a[p];
	int begin = p, end = r;
	while (begin < end) {
		while (begin<end&&a[end]>t)end--;
		a[begin] = a[end];
		while (begin < end&&a[begin] <= t) begin++;
		a[end] = a[begin];
	}
	a[begin] = t;
	return begin;
}

int selectK(int *a, int p, int r, int k) {
	int q = partition(a, p, r);//主元的下标
	if (q != -1) {
		int qK = q - p + 1;//主元是第几个元素 
		if (qK == k) return a[q];
		else if (qK > k) return selectK(a, p, q - 1, k);
		else return selectK(a, q + 1, r, k - qK);
	}
	return -1;
}

int find(int a[], int l, int r) {
	if (l > r)
		return l + 1;
	int midIndex = 1 + ((r - l) >> 1);//中间下标
	int q = selectK(a, l, r, midIndex - l + 1);//实际在中间位置的值
	int t = midIndex + 1;
	if (q == t) {
		return find(a, midIndex + 1, r);
	}
	else {
		return find(a, l, midIndex - 1);
	}
}
int main() {
	int a[10] = { 1,2,3,4,6,7,8,9,10,11 };
	cout << find(a, 0, 9);
	return 0;
}
