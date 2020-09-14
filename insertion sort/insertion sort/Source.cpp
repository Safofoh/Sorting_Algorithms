#include<iostream>
//#include<conio.h>

using namespace std;
const int SIZE = 10;
void InsertionSort(int A[], int);


int main(void)
{
	int i; int n;
	int           A[SIZE];
	cout << "\nINPUT " << SIZE << " values:\n";
	for (i = 0; i< SIZE; i++) cin >> A[i];
	InsertionSort(A, SIZE); //  function call
	cout << "\nSORTED ARRAY\n";
	for (i = 0; i < SIZE; i++) 
		cout << A[i] << '\t';
	cin >> n;
	return 0;
}
void InsertionSort(int A[SIZE], int n)
{
	int i, k, temp;
	for (k = 1; k< n; k++)
	{
		temp = A[k];
		for (i = k - 1; i >= 0 && temp<A[i]; i--)
			A[i + 1] = A[i];
		A[i + 1] = temp;
	}
}
