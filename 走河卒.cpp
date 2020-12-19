#include <iostream>
using namespace std;

const int dis[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};//��ķ��� 
long long dp[23][23]={0};
bool vis[23][23];

int main(){
	int mx,my,bx,by;
	cin>>bx>>by>>mx>>my;
	//���������������ƶ�һ������ 
	bx++;
	by++;
	mx++;
	my++;
	//�������ߵĵط����Ϊtrue������������ 
	for(int i=0;i<9;i++){
		int xx=dis[0][i]+mx;
		int yy = dis[1][i]+my;
		if(xx>=0&&xx<=bx+1&&yy>=0&&yy<=by+1){
			vis[xx][yy]=true;
		}
	}
	//��ǵ�һ����Ϊ1 
	dp[1][1] = 1;
	vis[1][1] = true;

	for (int i = 1; i <= bx; i++) {
		for (int j = 1; j <= by; j++) {
			if (!vis[i][j])
			//��Ϊ֮ǰ���������±������ƶ��ˣ�
			//����ʵ�����Ǵ�1��1 �±꿪ʼ������
			//���Բ��õ���Խ������� 
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout<<dp[bx][by];
	return 0;
} 
