#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int LIS(const int *a, int size, int *pre, int &nidx) {
	int *longest = new int[size];
	int nLis = 1;
	nidx = 0;
	for (int i = 0; i < size; i++)
	{
		longest[i] = 1;
		pre[i] = -1;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i] && (longest[i] < longest[j] + 1)) {
				longest[i] = longest[j] + 1;
				pre[i] = j;
			}
		}
		if (longest[i] > nLis)
		{
			nLis = longest[i];
			nidx = i;
		}
	}
	delete[] longest;
	return nLis;
}
void Print_Pre(int *pre, int idex, const int *a,vector<int> &v)
{
	int t = idex;
	while (t != -1) {
		v.push_back(a[t]);
		t=pre[t];
	}
}
int main()
{
	int a[] = { 1,4,5,6,2,3,8,9,10,11,12,12,1 };
	int size = sizeof(a) / sizeof(int);
	int *pre = new int[size];
	vector<int> v;
	int nIndex;
	int max_a = LIS(a, size, pre, nIndex);
	//vector<int> lis;
	//GetLIS(a,pre,nIndex,lis);
	cout << max_a << ' ' << nIndex << endl;
	//for (int i = 0; i < size; i++)
	//	cout << pre[i] << ' ';
	cout << endl;
	//Print(&lis.front(),(int)lis.size());
	Print_Pre(pre, nIndex, a,v);
	for(vector<int>::iterator it=v.end();it!=v.begin();it--){
		cout<<*(it-1)<<' ';
	}
	delete[] pre;
	return 0;
}
