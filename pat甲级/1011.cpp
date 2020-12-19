#include <iostream> 
#include <cstdio>

using namespace std;
int main() {
	char a[3] = { 'W','T','L' }, c[3];
	double b[3] = { 0.0 };
	double sum = 0.65;
	for (int i = 0; i < 3; i++) {
		double t;
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &t);
			if (t > b[i]) {
				c[i] = a[j];
				b[i] = t;
			}
		}
	}
	double t = (sum*b[0] * b[1] * b[2] - 1) * 2;
	for (int i = 0; i < 3; i++)
		printf("%c ", c[i]);
	printf("%.2lf", t);
	return 0;
}
