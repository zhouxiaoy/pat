#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.12 
//���� ���ǰ��ʱ ��Ԫ�ش���50%ʱ
//�� 2 2 3 3 4 4 4 5 5�Ͳ���
 /* 
int findE(){
	int times = 0,idx;//times��ʾ��Ԫ�صĸ�����idx��ʾ��Ԫ�ص��±� 
	for(int i=0;i<n;i++){
		if(times == 0){
			idx = i;
			times = 1;
		}else if(num[idx] == num[i]){//�����ǰԪ����idx��ͬ 
			times++; 
		}
		else{
			time--;//�����idx��ͬ������Ԫ�ظ�����һ 
		}
	}
	if(times > 0)//˵����Ԫ��> 50% 
		return idx;
	else 
		return -1;
}
*/ 
//������Ż���ֻҪtimes������0�Ϳ���ʱ��Ԫ�أ���֮����û����Ԫ��
//����֤idx�Ƿ�Ϊ��Ԫ�� 
int findE(){
	int times = 0,idx;//times��ʾ��Ԫ�صĸ�����idx��ʾ��Ԫ�ص��±� 
	for(int i=0;i<n;i++){
		if(times == 0){
			idx = i;
			times = 1;
		}else if(num[idx] == num[i]){//�����ǰԪ����idx��ͬ 
			times++; 
		}
		else{
			times--;//�����idx��ͬ������Ԫ�ظ�����һ 
		}
	}
	if(times > 0){//˵����Ԫ��> 50%
	times = 0; 	
		for(int i=0;i<n;i++){
			if(num[idx] == num[i])times++;	
		}
	}
	if(times > n/2) return idx;
	else return -1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	int t = findE();
	if(t!=-1)
		printf("��Ԫ��Ϊ:%d\n",num[t]);
	else
		puts("û����Ԫ��");
	return 0;
}
