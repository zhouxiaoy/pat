//���� ���S�� ��״���� ���ǳ�����
//��������˼�����õģ�ֵ��ѧϰ 
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int cnt[100005];//ֵΪ�±��Ԫ�ظ��� 
int count = 0, median = 0;//<=median��Ԫ�ظ�������λ��
vector<int> s;//ģ��ջ 

int getPosition(int x){
	return (x+1)/2;
} 

int main(){
	int n,a;
	scanf("%d",&n);
	char ch[15];
	for(int i=0;i<n;i++){
		scanf("%s",&ch);
		if(ch[1] == 'u'){//��ջ 
			scanf("%d",&a);
			cnt[a]++;
			s.push_back(a);//��ջ 
			if(median <a){//a��median�ұ� 
				if(count < getPosition(s.size())){//median��Ҫ���� 
					while(cnt[++median] == 0);//�ҵ���һ������median���� 
					count += cnt[median];//����count 
				} 
			}else{//����� 
				count++;
				//����Ԫ�غ��median������median����� 
				if(count - cnt[median] >= getPosition(s.size())){
					count -= cnt[median]; 
					while(cnt[--median] == 0);//�ҵ���һ��С��median����
				} 
			}
		}else if(ch[1] == 'o'){
			if(s.empty()){
				puts("Invalid");
				continue;
			}
			a = s.back();//��ջ
			s.pop_back();
			cnt[a]--;
			if(median < a){//a��median�ұ� 
				 if(count - cnt[median]>= getPosition(s.size())){//median��λ���б仯 
				 	count -= cnt[median]; 
					while(cnt[--median] == 0); 
				 }
			}else{
				count--;
				if(count < getPosition(s.size())){//median�仯 
					while(cnt[++median] == 0);
					count += cnt[median];
				}
			}
			printf("%d\n",a);
		}else if(ch[1] == 'e'){
			if(s.empty()){
				puts("Invalid");
				continue;
			}
			printf("%d\n",median);
		}
	} 
	return 0;
} 
