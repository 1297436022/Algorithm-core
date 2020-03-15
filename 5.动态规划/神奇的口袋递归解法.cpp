#include<iostream>
using namespace std;
int a[30];
int N;
int Ways(int w, int k)
{
	//从前k种物品中选择一些，凑成体积w的做法数目
	if(w == 0) return 1;
	if(k <= 0) return 0;
	return Ways(w, k-1) + Ways(w-a[k], k-1);
} 

int main()
{
	cin >> N;
	for(int i=1; i<=N; ++i)
	    cin >> a[i];
	cout << Ways(40, N);
	return 0;
}
