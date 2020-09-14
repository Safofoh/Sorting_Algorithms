#include <iostream>

using namespace std;

void get_Values(int data[], int N)
{
	cout << "\n\t\t Put " << N << " random values..\n\n";
	for (int i = 0;i<N;i++)
	{
		cin >> data[i];
	}
}


void display(int data[], int N)
{

	for (int i = 0;i<N;i++)
	{
		cout << data[i] << "\t";
	}
}

void Qsort(int data[], int left, int right)
{
	int pivot, i, j;
	i = left;   j = right; pivot = (left + right) / 2;
	do
	{
		while (data[i] < data[pivot]) i++;
		while (data[j] >  data[pivot]) j--;
		if (i <= j)
		{
			int  temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;    j--;
		}
	} while (i <= j);

	if (left < j)  Qsort(data, left, j);
	if (i < right) Qsort(data, i, right);
}
int main()
{
	int A[100];
	int N;
	cout << "\n\n How many values you want to sort --> ";
	cin >> N;
	get_Values(A, N);
	cout << "Before sort:\n\n";
	display(A, N);
	Qsort(A, 0, N - 1);
	cout << "\n\nAfter sort:\n\n";
	display(A, N);
	int k;
	cin >> k;
	return 0;
} // end of main ( ) function

