#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];//天平左边硬币
char Right[3][7];//天平右边硬币
char result[3][7];//结果
bool IsFake(char c, bool light);
//light为真表示假设假币为轻，否则表示认为假币为重
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 3; ++i) cin >> Left[i] >> Right[i] >> result[i];
		for(char c = 'A'; c <= 'L'; c++)
		{
			if(IsFake(c, true))
			{
				cout << c << " is the counterfeit coin and it is light.\n";
				break;
			}
			else if(IsFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is weight.\n";
				break;
			}
		}
	}
	return 0;
}
//light为真表示假设假币为轻，否则表示假设假币为重 
bool IsFake(char c, bool light)
{
	for(int i = 0; i < 3; ++i)
	{
		char *pLeft, *pRight;//指向天平两边的字符串
		if(light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{//如果假设假币为重，则把称量结果左右对换 
			pLeft = Right[i];
			pRight = Left[i]; 
		}
		switch(result[i][0])
		{
			case 'u'://右边翘起 
				if(strchr(pRight, c) == NULL)//不在右边 
				    return false;
				break;
			case 'e'://平衡 
				if(strchr(pLeft, c) || strchr(pRight, c))//在左边或者右边 
				    return false;
			    break;
		    case 'd'://右边下沉 
			    if(strchr(pLeft, c) == NULL)//不在左边 
				    return false;
				break; 
		}
	}
	return true;
} 
