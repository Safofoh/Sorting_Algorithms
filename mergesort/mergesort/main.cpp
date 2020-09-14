#include <iostream>
#include <vector>
using namespace std;


void mergesort(vector<int>& A,  int  n);
void merge(vector<int>& A, vector<int>& L,  int n1, vector<int>& R,  int n2);
int main()
{



	int  size = 6;
	vector<int> A(size);
	cout << "enter 10 numbers" << endl;

	for (int i = 0;i < size;i++)
		cin >> A[i];

	cout << "your array is" << endl;
	for (int i = 0;i < size;i++)
		cout << A[i] << "\t\t";
	cout << endl;
	
	
	mergesort(A, size);


	cout << "your sorted array is" << endl;
	for (int i = 0;i < size;i++)
		cout << A[i] << "\t\t";

	for (int i = 0; i < 10; i++)
		cin >> A[i];
	return 0;
}
void mergesort( vector<int>& A,  int  n)
{

	if (n == 1)
	{
	//	cout << "n1=" << n << "\t\t" << endl;
	//	cout << "return";
		return;
	}
	else
	{
		 int  n1 = (n / 2);
		//cout << "n1=" << n1 <<  "\t\t" << endl;
		 int  n2 = (n - n1);
		// cout << "n2=" << n2 << "\t\t" << endl;
		vector<int> L(n1);
		vector<int> R(n2);
		//	int L[n1]; int R[n2];
		for (int i = 0; i < n1 ; i++)
		{ 
			L[i] = A[i];
	//		cout << "L["<<i<<"]=" << L[i] << "\t\t";
		}
		//cout << endl;
		for (int j = 0; j < n2 ; j++)
			
		{
			R[j] = A[n1 + j];
		//	cout << "R["<<j<<"]=" << R[j] << "\t\t";
		}
		//cout << endl;
		mergesort(L, n1);
	//	cout << endl;
		mergesort(R, n2);
	//	cout << endl;
		merge(A, L, n1, R, n2);
	//	cout << endl;

	}
	return;
}

void merge(vector<int>& A, vector<int>& L, int n1, vector<int>& R, int n2)
{

	int i = 0; int j = 0;
	int s = n1 + n2 - 1;
	for (int k = 0; k <= s; k++)
	{

		//if (j < n2)
		//cout << "R["<<j<<"] in =" << R[j] << "\t\t";
	//	if (i < n1)
	//	cout << "L["<<i<<"] in =" << L[i] << "\t\t";

		if (i <= n1)
		{
			if (i<n1)
			{ 
			if ((j == n2) || (L[i] <= R[j]))
			{
				//		cout << "L["<<i<<"] in in =" << L[i] << "\t\t";
				A[k] = L[i];
				i = i + 1;

				//	cout << "A["<<k<<"]=" << A[k] << "\t\t" << endl;
			}}
			else
			{
				if (j < n2)
				{
					//	cout << "R["<<j<<"]in in =" << R[j] << "\t\t";
					A[k] = R[j];
					j = j + 1;


					//		cout << "A[" << k << "]=" << A[k] << "\t\t" << endl;
				}
			}

			//	cout << "A["<<k<<"] in=" << A[k] << "\t\t" << endl;
		}

	}


	return;

}