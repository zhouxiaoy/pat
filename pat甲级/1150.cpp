#include <iostream>
#include <cstdio>
using namespace std;

int e[205][205];//i��j�ľ��� 
int main(){
	int n,m;//n�����������m����·����
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a][b]=e[b][a]=c;
	}
	
	int k,tot=1,v = -1,minn = 0x3f3f3f;
	cin>>k;//Ҫ�ж�·������Ŀ 
	for(int i=0;i<k;i++){
		int u,flag = 1,sum = 0;
		cin>>u;//·�������ĳ��еĸ��� 
		int next[205],vis[205]={0};//�жϸý���Ƿ��߹� 
		cin>>next[0];
		for(int j=1;j<u;j++){
			cin>>next[j];
			//�ýڵ��������ȥ 
			if(e[next[j-1]][next[j]]!=0){
				sum+=e[next[j-1]][next[j]];
				vis[next[j]]++;
			}else{
				flag = -2;//����ýڵ��߲��� 
			}
		}
		if(flag != -2){
			for(int j=1;j<=n;j++){
					if(vis[j]>1&&flag == 1)
						flag = 0;//������ ���ʾ������� 
					else if(vis[j]<1)
						flag = -1;//û�߹����е�city 
			}
			if(next[0]!=next[u-1])flag = -1;
			if(flag >=0&&minn>sum) {
				minn = sum;
				v = tot;
			}
		}
		if(flag == 1)
			printf("Path %d: %d (TS simple cycle)\n",tot++,sum);
		else if(flag == 0)
			printf("Path %d: %d (TS cycle)\n",tot++,sum);
		else if(flag == -2)
			printf("Path %d: NA (Not a TS cycle)\n",tot++);
		else
			printf("Path %d: %d (Not a TS cycle)\n",tot++,sum);
	}
	printf("Shortest Dist(%d) = %d\n",v,minn);
	return 0;
}
