#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct node{
	int come_time,ser_time;//到来时间，服务时间化为秒 
};

bool cmp(node a,node b){
	return a.come_time<b.come_time;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> wins(k,28800);//28800等于8小时
	vector<node> custom;
	for(int i=0;i<n;i++){
		int hh,mm,ss,ser,come;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&ser);
		come = hh*3600+mm*60+ss;
		if(come > 61200) continue;
		custom.push_back({come,ser*60}); 
	} 
	sort(custom.begin(),custom.end(),cmp);
	
	int wait = 0;
	for(int i=0;i<custom.size();i++){
		//找出最先结束服务的窗口 
		int idx=0;
		for(int j=1;j<k;j++)
			if(wins[j]<wins[idx])
				idx = j;
		
		if(custom[i].come_time<wins[idx]){
			wait += wins[idx]-custom[i].come_time;
			wins[idx] += custom[i].ser_time;
		}else{
			wins[idx] = custom[i].come_time + custom[i].ser_time;
		}
	}
	
	if(custom.size() == 0)
		printf("0.0");
	else
		printf("%.1f",wait / 60.0 / custom.size());
	return 0;
}
