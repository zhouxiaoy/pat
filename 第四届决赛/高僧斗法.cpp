#include<iostream>
#include<stdio.h> 
#include<string>
#define N 100
using namespace std;
int main()
{
	int i, j, k;
	int count = 0;

	int monk[N] = { 0 };
	string str;
	getline(cin, str);
	int len = str.length();
	for (j = 0, i = 0; i < len; )
	{
		if (str[i]<'0' || str[i]>'9')
		{
			i++;
		}
		else {
			int n = 0;
			for (; i < len; ++i)
			{
				if (str[i] >= '0'&&str[i] <= '9')
				{
					n = n * 10 + str[i] - '0';
				}
				else break;
			}
			monk[j++] = n;
		}
	}
	count = j;
	int a[1005];
	for (i = 0, j = 0; j <= (count+1) / 2; j += 2, i++)
	{
		a[i] = monk[j + 1] - monk[j] - 1;
	}
	k = i;
	cout << "K:" << k << endl;
	cout << "count:" << count << endl;
	int sum = a[0];
	for (i = 1; i < k; i++)
	{
		sum ^= a[i];
	}
	if (sum == 0) cout << "-1";
	else {
		for (i = 0; i < k; i++)
		{
			if ((a[i] ^ sum) <= a[i])   j = a[i] ^ sum;
			break;
		}
		cout << monk[2 * i] << " " << monk[2 * i] + a[i] - j;
	}
	return 0;

}
