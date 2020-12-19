//难题 柳婼用 树状数组 但是超纲了
//这里的这个思想蛮好的，值得学习 
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int cnt[100005];//值为下标的元素个数 
int count = 0, median = 0;//<=median的元素个数，中位数
vector<int> s;//模拟栈 

int getPosition(int x){
	return (x+1)/2;
} 

int main(){
	int n,a;
	scanf("%d",&n);
	char ch[15];
	for(int i=0;i<n;i++){
		scanf("%s",&ch);
		if(ch[1] == 'u'){//入栈 
			scanf("%d",&a);
			cnt[a]++;
			s.push_back(a);//入栈 
			if(median <a){//a在median右边 
				if(count < getPosition(s.size())){//median需要右移 
					while(cnt[++median] == 0);//找到第一个大于median的数 
					count += cnt[median];//更新count 
				} 
			}else{//在左边 
				count++;
				//加入元素后的median在现在median的左边 
				if(count - cnt[median] >= getPosition(s.size())){
					count -= cnt[median]; 
					while(cnt[--median] == 0);//找到第一个小于median的数
				} 
			}
		}else if(ch[1] == 'o'){
			if(s.empty()){
				puts("Invalid");
				continue;
			}
			a = s.back();//出栈
			s.pop_back();
			cnt[a]--;
			if(median < a){//a在median右边 
				 if(count - cnt[median]>= getPosition(s.size())){//median的位置有变化 
				 	count -= cnt[median]; 
					while(cnt[--median] == 0); 
				 }
			}else{
				count--;
				if(count < getPosition(s.size())){//median变化 
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
