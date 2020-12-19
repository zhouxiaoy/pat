#include <iostream>
#include <cstdio>
using namespace std;
int k, SIZE;//k表示要取出的topK ，size表示当前的数组个数 
int heap[10000];//存储数据的数组 
void printRs() {
	if (SIZE <= k) {
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", heap[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < k; i++) {
			printf("%d ", heap[i]);
		}
		printf("\n");
	}
}
void MinHeapFixDown(int *a, int i, int n) {
	//找到左右孩子
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	//左孩子已经越界，i就是叶子节点
	if (left >= n) {
		return;
	}
	
	int min = left;//默认是左孩子
	if (right < n) {
		if(a[right] < a[left]) {
			min = left;
		}
		//min指向了左右孩子中较小的那个 
	}
	//如果a[i]比两个孩子都要小，不用调整
	if (a[i] <= a[min]) {
		return;
	}
	//否则，找到两个孩子中较小的，和i交换
	int temp = a[i];
	a[i] = a[min];
	a[min] =temp;

}


void makeMinHeap(int *a, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		MinHeapFixDown(a, i, n);
	}
}
/*
 *如果数据数量小于等于k，直接加入堆中
 *等于k的时候，进行堆化
*/
void deal(int x) {
	if (SIZE < k-1)
		heap[SIZE++] = x;
	else if (SIZE == k-1) {
		//堆化
		heap[SIZE] = x;
		makeMinHeap(heap, k);
		SIZE++;
	}
	else {
		//x和堆顶进行比较，如果x大于堆顶，x将堆顶挤掉并向下调整
		if (heap[0] < x) {
			heap[0] = x;
			MinHeapFixDown(heap, 0, k);
			printRs();
		}
	}
}

int main() {
	int data;
	scanf("%d", &k);
	while (scanf("%d", &data) != EOF) {
		deal(data);
	}
}
