#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int n, m;
int num[1005];
//�ж���ȫ�������Ƿ�Ϊ �󶥶� 
bool isMaxHeap(int idx, int minn, int maxx) {
	if (num[idx]<minn || num[idx]>maxx)return false;
	if (2 * idx + 1 >= m) return true;//���������������� 
	else if (2 * idx + 1 == m - 1)
		return isMaxHeap(2 * idx + 1, minn, num[idx]);
	return isMaxHeap(2 * idx + 1, minn, num[idx]) && isMaxHeap(2 * idx + 2, minn, num[idx]);
}
//�ж��Ƿ�ʱС���� 
bool isMinHeap(int idx, int minn, int maxx) {
	if (num[idx]<minn || num[idx]>maxx)return false;
	if (2 * idx + 1 >= m)return true;//���������������� 
	if (2 * idx + 1 == m - 1)
		return isMinHeap(2 * idx + 1, num[idx], maxx);
	return isMinHeap(2 * idx + 2, num[idx], maxx) && isMinHeap(2 * idx + 1, num[idx], maxx);
}

void postOrder(int index) {
	if (index >= m) return;
	postOrder(index * 2 + 1);
	postOrder(index * 2 + 2);
	printf("%d%s", num[index], index == 0 ? "\n" : " ");
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> num[j];
		if (isMinHeap(0, INT_MIN, INT_MAX))
			puts("Min Heap");
		else if (isMaxHeap(0, INT_MIN, INT_MAX)) 
			puts("Max Heap");
		else
			puts("Not Heap");
		postOrder(0);
	}
	return 0;
}
