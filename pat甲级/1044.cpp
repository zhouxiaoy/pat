#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a[100005];
long long b[100005];
struct iToj{
	int i,j;
};
vector<iToj> v;
int main(){
	int n,m;
	cin>>n>>m;
	long long temp=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		temp+=a[i];
		b[i]=temp; 
	}
	bool flag = false;
	int minn = INT_MAX;
	for(int i=1;i<=n;i++){
		if(a[i] == m){
			cout<<i<<'-'<<i<<endl;
			flag = true;
		}
		//顺序查找会超时 
		/*
		for(int j=i;j<=n;j++){
			if(b[j]-b[i-1]==m){
				
				flag = true;
			}
			else if(b[j]-b[i-1] > m){
				if(b[j]-b[i-1] == minn)
					v.push_back({i,j});
				else if(b[j]-b[i-1] < minn){
					v.clear();
					minn = b[j]-b[i-1];
					v.push_back({i,j});
				}
			} 
		}
		*/
		//二分查找
		int left = i, right = n, mid;
		while (left <= right) {
			mid = (left + right)/2;
			int t = b[mid] - b[i - 1];
			if (t > m) {
				if (t == minn)
					v.push_back({ i,mid });
				else if (t <minn) {
					v.clear();
					minn = t;
					v.push_back({ i,mid });
				}
				//如果是大于m的 
				right = mid - 1;
			}
			else if (t == m) {
				cout << i << '-' << mid << endl;
				flag = true;
				break;
			}
			else
				left = mid + 1;
		}
	}
	
	if(flag == false)
		for(int x=0;x<v.size();x++)
			cout<<v[x].i<<'-'<<v[x].j<<endl;
	return 0;
} 
