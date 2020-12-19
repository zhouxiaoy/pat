#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0, tot = 0;
	cin>>n;
	char c[100][100];
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++)
		//	scanf("%c", &c[i][j]);
		//scanf("\n");
		cin>>c[i][j];
	}
	for (int i = 0; i < n; i++) {
		tot = 0;
		for (int j = 0; j < n; j++) {
			//printf("%c", c[i][);
			if (c[i][j] == 'c')
				tot++;
		}
		if (tot > 1)
			sum += tot * (tot - 1) / 2;
	}
	for (int i = 0; i < n; i++) {
		tot = 0;
		for (int j = 0; j < n; j++)
		{

			if (c[j][i] == 'c')
				tot++;
		}
		if (tot > 1)
			sum += tot * (tot - 1) / 2;
	}
	return 0;
}
