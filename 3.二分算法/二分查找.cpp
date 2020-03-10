#include<iostream>
using namespace std;

int BinarySearch(int a[], int size, int p)
{
	int L = 0;
	int R = size - 1;
	while(L <= R)
	{
		int mid = L + (R - L)/2;//为防止(L+R)过大溢出 
		if(p == a[mid])
		    return mid;
		else if(p > a[mid])
		    L = mid + 1;
		else
		    R = mid - 1;
	}
	return -1;
}

int LowerBound(int a[], int size, int p)
{
	int L = 0;
	int R = size - 1;
	int lastPos = -1;
	while(L <= R)
	{
		int mid = L + (R - L)/2;
		if(a[mid] >= p)
		    R = mid - 1;
	    else
	    {
	    	lastPos = mid;
	    	L = mid + 1;
	    }
	}
	return lastPos;
}

int main()
{
	int a[] = {1,2,3,5,7,10,13};
	cout << BinarySearch(a, 7, 5) + 1 << endl;
	cout << LowerBound(a, 7, 8) + 1<< endl;
	return 0;
}


