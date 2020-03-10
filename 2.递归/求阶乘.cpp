#include<iostream>
using namespace std;
int Factorial(int n); 
int main()
{
	cout << Factorial(3) << endl; 
	return 0;
} 
int Factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * Factorial(n-1);
}
