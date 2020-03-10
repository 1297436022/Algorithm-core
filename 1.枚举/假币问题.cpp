#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];//��ƽ���Ӳ��
char Right[3][7];//��ƽ�ұ�Ӳ��
char result[3][7];//���
bool IsFake(char c, bool light);
//lightΪ���ʾ����ٱ�Ϊ�ᣬ�����ʾ��Ϊ�ٱ�Ϊ��
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
//lightΪ���ʾ����ٱ�Ϊ�ᣬ�����ʾ����ٱ�Ϊ�� 
bool IsFake(char c, bool light)
{
	for(int i = 0; i < 3; ++i)
	{
		char *pLeft, *pRight;//ָ����ƽ���ߵ��ַ���
		if(light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{//�������ٱ�Ϊ�أ���ѳ���������ҶԻ� 
			pLeft = Right[i];
			pRight = Left[i]; 
		}
		switch(result[i][0])
		{
			case 'u'://�ұ����� 
				if(strchr(pRight, c) == NULL)//�����ұ� 
				    return false;
				break;
			case 'e'://ƽ�� 
				if(strchr(pLeft, c) || strchr(pRight, c))//����߻����ұ� 
				    return false;
			    break;
		    case 'd'://�ұ��³� 
			    if(strchr(pLeft, c) == NULL)//������� 
				    return false;
				break; 
		}
	}
	return true;
} 
