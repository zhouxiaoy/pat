#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	vector<vector<int>> v;
	int m,n;//n����ѧ������  m�����ѡ��ĸ��� 
	scanf("%d",&n,&m);
	int score[100];
	int fs,xx,zq;
	char xh;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&fs,&xx,&zq);
		for(int j=0;j<zq;j++){
			scanf(" %c",&xh);
			v[i].push_back(xh);
		}
	}
	return 0;
}

