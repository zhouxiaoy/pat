//前缀和 优化版 （测试发现自己写的时间差好多 最高位39ms，柳婼的是4ms）
//不知道为什么 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct stu {
	int id, score[4], rank[4];
}stu;

stu p[2005];
//0-3  分别代表平均，C，M，E 
//num[i][j]保存i的分数的为j的个数，tot_num[i][j]保存i的分数100到j为个数，vis[i]保存id为i的结构体数组的下标 
int num[4][101] = { 0 }, tot_num[4][105] = { 0 }, vis[10000000];
int main() {
	int n, m;
	cin >> n >> m;
	memset(vis, -1, sizeof vis);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &p[i].id, &p[i].score[1], &p[i].score[2], &p[i].score[3]);
		p[i].score[0] = (p[i].score[1] + p[i].score[2] + p[i].score[3]) / 3.0 + 0.5;
		//该分数个数+1 
		num[0][p[i].score[0]]++, num[1][p[i].score[1]]++, num[2][p[i].score[2]]++, num[3][p[i].score[3]]++;
		//保存id的结构体下标 
		vis[p[i].id] = i;
	}

	//计算100-j分数的总个数 
	for (int i = 0; i < 4; i++)
		for (int j = 100; j >= 0; j--) {
			tot_num[i][j] = tot_num[i][j + 1] + num[i][j];
		}

	int ch[4] = { 'A','C','M','E' };
	for (int i = 0; i < m; i++) {
		int id;
		cin >> id;
		//不存在 
		if (vis[id] == -1) {
			puts("N/A");
			continue;
		}
		
		//选出当前id的4种排名最好的成绩 
		int flag = 0;
		p[vis[id]].rank[flag] += tot_num[flag][p[vis[id]].score[flag] + 1] + 1;
		for (int i = 1; i < 4; i++) {
			p[vis[id]].rank[i] += tot_num[i][p[vis[id]].score[i] + 1] + 1;
			if (p[vis[id]].rank[i] < p[vis[id]].rank[flag])
				flag = i;
		}
		//打印 
		printf("%d %c\n", p[vis[id]].rank[flag], ch[flag]);
	}
	return 0;
}


//前缀和版本 会超内存 
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//
//typedef struct stu {
//	int score[4] = { -1 }, rank[4] = { 0 };
//}stu;
//
//stu p[10000000];
//int num[4][101] = { 0 }, tot_num[4][105] = { 0 };
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		int id;
//		scanf("%d", &id);
//		scanf("%d %d %d", &p[id].score[1], &p[id].score[2], &p[id].score[3]);
//		p[id].score[0] = (p[id].score[1] + p[id].score[2] + p[id].score[3]) / 3.0 + 0.5;
//		num[0][p[id].score[0]]++, num[1][p[id].score[1]]++, num[2][p[id].score[2]]++, num[3][p[id].score[3]]++;
//	}
//
//	for (int i = 0; i < 4; i++)
//		for (int j = 100; j >= 0; j--) {
//			tot_num[i][j] = tot_num[i][j + 1] + num[i][j];
//		}
//
//	int ch[4] = { 'A','C','M','E' };
//	for (int i = 0; i < m; i++) {
//		int id;
//		cin >> id;
//		if (p[id].score[0] == -1) {
//			puts("N/A");
//			continue;
//		}
//		int flag = 0;
//
//		p[id].rank[flag] += tot_num[flag][p[id].score[flag] + 1] + 1;
//		for (int i = 1; i < 4; i++) {
//			p[id].rank[i] += tot_num[i][p[id].score[i] + 1] + 1;
//			if (p[id].rank[i] < p[id].rank[flag])
//				flag = i;
//		}
//		printf("%d %c\n", p[id].rank[flag], ch[flag]);
//	}
//	return 0;
//}

/*

#include <iostream>
#include <algorithm> 
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct stu {
	int id,score[4],rank[4];
}stu;

stu p[2005];
//表示在当前下标下的分数的个数 
int vis[10000000],flag=-1;

bool cmp(const stu &a,const stu &b){
		return a.score[flag]>b.score[flag];
}

int main() {
	memset(vis,-1,sizeof vis);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d",&p[i].id,&p[i].score[1],&p[i].score[2],&p[i].score[3]);
		p[i].score[0]= (p[i].score[1] + p[i].score[2] + p[i].score[3]) / 3.0 + 0.5;
	}
	
	for(flag = 0; flag <= 3; flag++) {
		sort(p, p + n, cmp);
		p[0].rank[flag] = 1;
		vis[p[0].id] = 0;
		for(int i = 1; i < n; i++) {
			p[i].rank[flag] = i + 1;
			if(p[i].score[flag] == p[i-1].score[flag])
				p[i].rank[flag] = p[i-1].rank[flag];
			
			//保存id所在的位置 
			vis[p[i].id] = i;
		}
	}
	
	int ch[4]={'A','C','M','E'};
	for(int i=0;i<m;i++){
		int Id;
		cin>>Id;
		if(vis[Id]==-1){
			puts("N/A");
			continue;
		}
		flag=0;
		for(int i=1;i<=3;i++)
			 if(p[vis[Id]].rank[i]<p[vis[Id]].rank[flag])
			 	flag=i;
		printf("%d %c\n",p[vis[Id]].rank[flag],ch[flag]);
	}
	//
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %d %d R_A:%d R_C:%d R_M:%d R_E:%d\n",p[i].id,p[i].score[0],p[i].score[1],p[i].score[2],p[i].score[3],p[i].rank[0],p[i].rank[1],p[i].rank[2],p[i].rank[3]);
	}
	//
	return 0;
}

*/
