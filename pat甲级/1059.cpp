//������д���кܶ����Ǹ� �Ż� ����ѧһѧ 
/*//���װ�Ĵ�� 
	vector<int> prime(500000, 1);
	for(int i = 2; i * i < 500000; i++)
		for(int j = 2; j * i < 500000; j++)
			prime[j * i] = 0;
*/ 
#include <iostream>
#include <cstdio> 
using namespace std;

//������bit �������Ż��ռ� 
const int maxx = 500005;
bool vis[maxx];
int prime[maxx]; 

//ŷ��ɸ 
int Prime(){
	int ans = 0;	
	for(long int i=2;i<maxx;i++){
		if(!vis[i]) prime[ans++] = i;
		for(int j=0;j<ans && i*prime[j] <maxx;j++){
			vis[i*prime[j]] = true;
			if(i % prime[j] == false)break;//�ؼ� 
		}
	}
	return ans;
} 

int main(){
	long int a;
	scanf("%ld",&a);
	printf("%ld=",a); 
	//����ҳ��ܱ�x�������������� 
	int ans = Prime();
	//��Ҫ���� 
	if(a == 1){
		printf("1");
		return 0;
	}
	bool state = false;
	for(int i=0;a>=2 && i<=ans;i++){
		int cnt = 0,flag = 0;
		while(a % prime[i] == 0){
			cnt++;
			a /= prime[i];
			flag = 1;
		}
		if(flag){
			if(state)printf("*");
			state = true;
			printf("%d",prime[i]);
		}
		if(cnt>=2) printf("^%d",cnt);
	} 
	return 0;
} 
