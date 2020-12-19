#include <iostream>

using namespace std; 
int st[11];
int main(){
	int n;
	long long sum = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		sum+=a;
		st[a]++;
	}
	sum%=10;
	if(sum==0)sum = 10;
	for(int i=1;i<=10;i++){
		if(i == sum-i && st[i]>1){cout<<sum;return 0;}
		if(i != sum-i && sum>i && st[i] && st[sum-i]){cout<<sum;return 0;}
		if(i == sum+10-i && st[i]>1){cout<<sum;return 0;}
		if(i != sum+10-i && st[i] && st[sum+10-i]){cout<<sum;return 0;}
	}
	cout<<0;
	return 0;
}
/*
#include <iostream>

using namespace std;

const int N = 1e6 + 5;
int n;
int st[N];
bool vis[N];
bool dfs1(int x, int k) {
	if (k == 0 && x%10 != 0)
		return false;
	if (k == 0 && x%10  == 0) {//如果找到了两个之和刚好为x
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i] == false && st[i] <= x) {
			vis[i] = true;

			bool flag = dfs1(x + st[i], k - 1);
			if (flag == false)
				vis[i] = false;
			else
				return true;
		}
	}
}

int main() {
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
		sum += st[i];
	}
	
	sum %= 10;
	if(sum == 0)sum = 10;
	
	if (dfs1(sum, 2) == false)sum = 0;
	cout << sum;
	return 0;
}
*/
