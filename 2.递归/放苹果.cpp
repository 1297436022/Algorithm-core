#include<iostream>
using namespace std;

int f(int m, int n)
{
	if(n > m)
	    return f(m, m);
	if(m == 0)
	    return 1;
	if(n <= 0)
	    return 0;
	//有盘子为空的放法+没盘子为空的放法 (每个盘子先放一个) 
	return f(m, n-1) + f(m-n, n); 
} 

int main()
{
	int t, m, n;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
} 
