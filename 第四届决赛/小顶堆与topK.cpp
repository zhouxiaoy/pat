#include <iostream>
#include <cstdio>
using namespace std;
int k, SIZE;//k��ʾҪȡ����topK ��size��ʾ��ǰ��������� 
int heap[10000];//�洢���ݵ����� 
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
	//�ҵ����Һ���
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	//�����Ѿ�Խ�磬i����Ҷ�ӽڵ�
	if (left >= n) {
		return;
	}
	
	int min = left;//Ĭ��������
	if (right < n) {
		if(a[right] < a[left]) {
			min = left;
		}
		//minָ�������Һ����н�С���Ǹ� 
	}
	//���a[i]���������Ӷ�ҪС�����õ���
	if (a[i] <= a[min]) {
		return;
	}
	//�����ҵ����������н�С�ģ���i����
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
 *�����������С�ڵ���k��ֱ�Ӽ������
 *����k��ʱ�򣬽��жѻ�
*/
void deal(int x) {
	if (SIZE < k-1)
		heap[SIZE++] = x;
	else if (SIZE == k-1) {
		//�ѻ�
		heap[SIZE] = x;
		makeMinHeap(heap, k);
		SIZE++;
	}
	else {
		//x�ͶѶ����бȽϣ����x���ڶѶ���x���Ѷ����������µ���
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
