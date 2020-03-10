#include<iostream>
using namespace std;
void Hanoi(int n, char src, char mid, char dest, int src_n)
//将src座上的n个盘子，以mid座为中转，移动到dest座
//src座上最上方盘子编号是 src_n 
{
	if(n == 1)
	{
		cout << src_n << ":" << src << "->" << dest << endl;
		return ;
	}
	Hanoi(n-1, src, dest, mid, src_n);
	cout << src_n + n - 1 << ":" << src << "->" << dest << endl;
	Hanoi(n-1, mid, src, dest, src_n);
	return ; 
} 
int main()
{
	char a, b, c;
	int n;
	cin >> n >> a >> b >> c;
	Hanoi(n, a, b, c, 1);
	return 0;
} 
