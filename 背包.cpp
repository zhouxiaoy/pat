#include <iostream> 
#include <vector>
using namespace std;

typedef struct beibao{
	int wei;
	int val;
	int num;
}bb;
bool cmp(const bb& a,const bb &b){
	return a.val>b.val;
}
int main(){
	bb	a[1005];
	vector<int> v;
	int weight,n;
	for(int i=0;i<n;i++){
		cin>>a[i].wei>>a[i].val>>a[i].num;
		v.push_back(a[i].num);
	}
	for(int )
	return 0;
}
