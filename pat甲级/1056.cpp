//���� 
//�����߼� �����Ĳ����� ���׿��� 
//rank Ϊ С����+1��1-С�������� ǰ С���� ����
//�����Ķ�ΪС����+1
//��������ÿ��ѡ�� ����С��Ĺھ�������temp��
//Ȼ��v��������ǵ�ǰ��ѡ����ȫ����ֵΪ С����+1
//��temp�ھ�����ֻ��һֻʱ ���ǵ�һ���ˣ�����ѭ�� 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, temp;
int wei[1005], rk[1005];
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &wei[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}

	//���� 
	int rank;
	while (1) {
		int i = 0;
		while (i < v.size()) {
			int maxx = i;
			for (int j = 0; j < m && i < v.size(); j++, i++) {
				if (wei[v[maxx]] < wei[v[i]])
					maxx = i;
			}
			temp.push_back(v[maxx]);
		} 
		rank = temp.size() + 1;
		for (int j = 0; j < v.size(); j++)
			rk[v[j]] = rank;
		if (temp.size() == 1) {
			rk[temp[0]] = 1;
			break;
		}
		v = temp;
		temp.clear();
	}
	printf("%d", rk[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", rk[i]);
	return 0;
}
