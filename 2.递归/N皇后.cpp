#include<iostream>
#include<cmath>
using namespace std;
int N;
int queenPos[100];//用来存放算好的皇后的位置。最左上角是(0,0)
void NQueen(int k);
int main()
{
	cin >> N;
	NQueen(0);//从第0行开始摆皇后
	return 0; 
}  
void NQueen(int k)//在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后 
{
	int i;
	if(k == N)//N个皇后已经摆好
	{
		for(i = 0; i < N; ++i)
		    cout << queenPos[i] + 1 << " ";
		cout << endl;
		return ;
	} 
	for(i = 0; i < N; ++i)//逐尝试第k个皇后的位置 
	{
		int j;
		for(j = 0; j < k; ++j)
		{
			//和已经摆好的k个皇后的位置比较，看是否冲突
			if(queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))//同一列或者斜着 
			{
				break;//冲突，测试下一个位置 
			} 
		}
		if(j == k)//当前选的位置i不冲突 
		{
			queenPos[k] = i;//将第k个皇后摆放在位置i
			NQueen(k + 1); 
		} 
	}
}









