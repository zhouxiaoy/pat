#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
	int index,value;
};
bool cmp(node a,node b){
	return a.index<b.index;
}
int post[35],in[35];
vector<node> ans;
void pre (int root ,int start,int end,int index){
	if(start>end)return;
	int i=start;
	while(i<end&&in[i]!=post[root])i++;
	//printf("%d ",post[root]);
	ans.push_back({index,post[root]});
	pre(root-(end-i+1),start,i-1,index*2+1);
	pre(root -1,i+1,end,index*2+2);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>post[i];
	for(int i=0;i<n;i++)
		cin>>in[i];
	pre(n-1,0,n-1,0);
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size() != 0){
		cout<<ans[0].value;
		for(int i=1;i<ans.size();i++)
			cout<<' '<<ans[i].value;
	} 
	return 0;
}
