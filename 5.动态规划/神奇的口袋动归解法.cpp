#include<iostream>
using namespace std;
int a[30];
int N;
int Ways[50][40];//Ways[i][j]表示从前j种物品里凑出体积i的方法数
int main()
{
	cin >> N;
	memset(Ways, 0, sizeof(Ways));
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		Ways[0][i] = 1;
	}
	Ways[0][0] = 1;
	for (int w = 1; w <= 40; ++w)
	{
		for (int k = 1; k <= N; ++k)
		{
			Ways[w][k] = Ways[w][k - 1];
			if (w - a[k] >= 0)
				Ways[w][k] += Ways[w - a[k]][k - 1];
		}
	}
	cout << Ways[40][N];
	return 0;
}