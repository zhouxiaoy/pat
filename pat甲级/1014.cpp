#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<int> que[25];//ģ�ⴰ�ڶ��� 
int done_time[1005], win_done_time[25], win_do_time[25];//�����ʱ�䣬���ڶ��ж���ɺ��ʱ�䣬���ڶ��п�ʼǰ��ʱ�� 
int peo[1005];//�洢ÿ�������ʱ�� 

int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++)
		cin >> peo[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			que[i].push(peo[i + j * n]);
			win_done_time[i] += peo[i + j * n];
			done_time[i + j * n] = win_done_time[i];
		}

	for (int i = n * m; i < k; i++) {
		//�ҳ�������������ɵĶ��� 
		int u = -1, minn = 0x3f3f3f3f;
		for (int j = 0; j < n; j++) {
			if (que[j].front() + win_do_time[j] < minn) {
				minn = que[j].front() + win_do_time[j];
				u = j;
			}
		}
		//���´���ʱ�� 
		win_do_time[u] = minn;
		win_done_time[u] += peo[i];
		done_time[i] = win_done_time[u];
		que[u].pop();
		que[u].push(peo[i]);
	}

	for (int i = 0; i < q; i++) {
		int c;
		cin >> c;
		//17��00֮ǰ����������17��00 
		if (done_time[c - 1] - peo[c - 1] < 540)
			printf("%02d:%02d\n", (done_time[c - 1] + 480) / 60, (done_time[c - 1] + 480) % 60);
		else
			puts("Sorry");
	}
	return 0;
}
