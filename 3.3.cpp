#include <iostream>
#include <cstring>
using namespace std;
char p[101][101];
char a[24][3] = { "°¡","°Å","²Á","´î","¶ê","·¢","¸Á","¹þ","»÷","¿¦","À¬","Âè","ÄÃ","Å¶","Å¾","ÆÚ","È»","Èö","Ëú","ÍÚ","Îô","Ñ¹","ÔÑ" };
char zimu[24] = { 'A','B','C','D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S','T','W','X','Y','Z' };
char temp[3];
void dayin() {
	int i;
	for (i = 0; i < 24; i++)
		if (strcmp( a[i], temp) == 1)
		{
			cout << zimu[i-1];
			break;
		}
	if (i == 24)
		cout << "Z";
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		for (int j = 0; j < strlen(p[i]); j += 2)
		{
			temp[0] = p[i][j];
			temp[1] = p[i][j + 1];
			dayin();
		}
		cout << endl;
	}

}
