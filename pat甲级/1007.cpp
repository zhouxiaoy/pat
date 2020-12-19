#include<iostream>
#include <climits>
using namespace std;
const int N = 10010;
int nums[N];
int score[N];
int main() {
	int n, i;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		cin >> nums[i];
	}
	score[0] = nums[0];
	int max = score[0], max_idx=0;
	for (i = 1; i < n; i++) {
		if (score[i - 1] + nums[i] < nums[i]) {
			score[i] = nums[i];
		}
		else {
			score[i] = score[i - 1] + nums[i];
			
		}
		if (score[i] > max) {
			max = score[i];
			max_idx = i;
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << score[i] << ' ';*/
	//cout << endl;
	int min_idx = max_idx;
	i = max_idx-1;
	int flag = 0;
	while (i >= 0 && score[i] >= 0 && nums[i] != score[i]) i--, flag = 1;
	if (flag == 1)min_idx = i;
	if (max < 0)
		cout << 0 << ' ' << nums[0] << ' ' << nums[n - 1];
	else
		cout << max << ' ' << nums[min_idx] << ' ' << nums[max_idx];
	return 0;
}
