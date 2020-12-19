#include <iostream>
#include <cmath>
#include <cstdio>
#include <memory.h>

using namespace std;
const int maxn=30;
int n,flag[maxn];//��¼��ĸ����������� 
char s[4][maxn];
bool use[maxn];//��¼�����Ƿ�ʹ�� 
int id(char ch){
	return ch-'A'+1;
} 
//x�����У�y�����У�t�����λ 
void dfs(int x,int y,int t){
	if(x==0){//���ϵ�С�����ҵ���x==0 ��ʾ�����������һ�� 
		if(t==0)//���һ�в����н�λ��û�н�λ��������������
		{
			//��ӡ 
			for(int i=1;i<n;i++){
				printf("%d ",flag[i]);
			}
			printf("%d\n",flag[n]);
		}
		return;
	}
	//��֦ 
	for(int i=x-1;i>=1;i--){
		int w1 = flag[id(s[1][i])];//w1�����һ���ַ������������
		int w2 = flag[id(s[2][i])];//w2�ǵڶ���
		int w3 = flag[id(s[3][i])];//w3�ǵ�����
		if(w1==-1||w2==-1||w3==-1){
			continue;
		}
		if((w1+w2)%n!=w3&&(w1+w2+1)%n!=w3){
			return;//����޷����������������ģ���ʽ�Ǵ�� 
		}
	}
	//������λ���ϻ�û����ֵ���ͽ��и�ֵ
	if(flag[id(s[y][x])] == -1){
		for(int i=n-1;i>=0;i--){
			if(!use[i]){//����������δ��ʹ�� 
				if(y!=3){//�Ҳ������һ�� 
					flag[id(s[y][x])]=i;//�ͽ����λ�ø���ֵ
					use[i] = 1;//���������ֱ��ù� 
					dfs(x,y+1,t);//����������һ�� 
					//���� 
					flag[id(s[y][x])] = -1;
					use[i]=0; 
				}else{//��y==3ʱ 
					int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;//�������������λ֮��
					if(w%n!=i)
						continue;//����������Ѱ����һ������ 
					//�ҵ������ ������ ��ֵ����ǣ� 
					use[i] = 1;flag[id(s[3][x])] = i;
					dfs(x-1,1,w/n);//������һ���λ�ı�
					use[i]=0;flag[id(s[3][x])] = -1;//���� 
				}
			}
		}
	}else{//������λ���Ѿ�����ֵ
		if(y!=3)
			dfs(x,y+1,t); 
		else{
			int w=flag[id(s[1][x])] + flag[id(s[2][x])] + t;
			if(w%n!=flag[id(s[3][x])])
				return;
			dfs(x-1,1,w/n);//������һ�� ����λ��Ҫ�ı� 
		}
	} 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		scanf("%s",s[i]+1);
	} 
	memset(flag,-1,sizeof(flag));
	dfs(n,1,0);
	return 0;
}
