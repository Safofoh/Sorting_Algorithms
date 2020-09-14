#include <iostream>
#include <vector>
using namespace std;


void mergesort ( vector<int>& A, const int  n);
void merge(vector<int>& A, vector<int>& L, const int n1, vector<int>& R, const int n2);
int main()
{



	int const size=10;
	vector<int> A(size);
	cout << "enter 10 numbers" << endl;
	
	for (int i = 0;i < size;i++)
		cin >> A[i];

	cout << "your array is" << endl;
	for (int i = 0;i < size;i++)
		cout << "\t\t" << A[i];

	mergesort(A, size);

	cout << "your sorted array is" << endl;
	for (int i = 0;i < size;i++)
		cout << "\t\t" << A[i];

	return 0;
}
void mergesort(vector<int>& A, const int  n)
{

	if (n == 1)
		return;
	else
	{
		const int  n1 =( n/2);
		const int  n2 =(n - n1);
		vector<int> L(n1);
		vector<int> R(n2);
	//	int L[n1]; int R[n2];
		for (int i = 0; i <= (n1 - 1); i++)
			L[i] = A[i];
		for (int j = 0; j <= (n2 - 1); j++)
			R[j] = A[n1+j];

		mergesort(L, n1);
		mergesort(R, n2);
		merge(A, L, n1, R, n2);

	}

}

void merge(vector<int>& A, vector<int>& L, const int n1, vector<int>& R, const int n2)
{

	int i = 0; int j = 0;

	for (int k = 0; k <= (n1 + n2 - 1); k++)
		if (i < n1)
		{
			if (j == n2 || L[i] <= R[j])
				A[k] = L[i];
		}
		else
			if (j < n2)
			{
				A[k] = R[j];
				j = j + 1;
			}



}
