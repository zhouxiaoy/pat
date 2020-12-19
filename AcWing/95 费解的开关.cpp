#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;

const int N = 6;
char st[N][N],backup[N][N];
int dx[5]={0,1,0,-1,0},dy[5]={1,0,-1,0,0};

void turn(int x,int y){
	for(int i=0;i<5;i++){
		int a = x+dx[i],b = y +dy[i];
		if(a<0||a>=5||b<0||b>=5)continue;
		st[a][b] ^= 1;
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		for(int i = 0;i < 5;i++)cin>>st[i];
		int minn = 0x3f3f3f3f;
		for(int k=0;k<32;k++){
			int res = 0;
			memcpy(backup,st,sizeof st);//保存数组 
			for(int i=0;i<5;i++)
				if(k >> i & 1){//二进制下第i位位1
					res++;
					turn(0,i);
				} 
			
			for(int i = 0;i<4;i++){
				for(int j=0;j<5;j++){
					if(st[i][j]=='0'){//灯是灭的 
					 	turn(i+1,j); 
					 	res++;
					 }
				}
			}
			
			bool dark = false;
			for(int i=0;i<5;i++)
				if(st[4][i]=='0') dark = true;
			if(!dark) minn = min(res,minn);
			memcpy(st,backup,sizeof st);
		}
		if(minn > 6) minn = -1;
		cout<<minn<<endl;
	} 
	return 0;
} 
