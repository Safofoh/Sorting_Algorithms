#include <iostream>
#include<conio.h>

using namespace std;

int const MAX = 100;
int A[MAX];
int hold[MAX][10];
int N;

int loop=0;
int space=0;

void RadixSort(int);
void InsertionSort();
void SelectionSort();


int main()
{
	char choice;
	int c = 0;
	int c1 = 1;

while (c1==1)
	{ 
	cout << "\nhow many values you want to sort" << endl;
	cin >> N;
	cout << "\n put " << N << " values..\n";


	for (int i = 0; i < N; i++)
		cin >> A[i];
while (c == 0)
	{

	cout << "For insersion sort, insert I\nFor radix sort, insert R\nFor selection sort, insert S\n";
	cin >> choice;


	
		switch (choice)
		{
		case 'I':
		case 'i':
			loop = 0;
			InsertionSort();
			c = 1;
			space = N;
			break;
		case 'R':
		case 'r':
			loop = 0;
			if (N > 1)
				RadixSort(10);
			space = (N * 2);
			c = 1;
			break;
		case 'S':
		case 's':
			loop = 0;
			SelectionSort();
			space = N;
			c = 1;
			break;

		default:
			cout << "you didn't insert a valid character\n\n";
			break;

		}
	}
	
	
	cout << "space taken is " << space << "\n";
	cout << "maximum loop iteration is (or numver of tries are) " << loop << "\n";


	cout << "\n\n\t\t\t sorted list \n\n";
	for (int i = 0; i < N; i++)
		cout << A[i] << "\t";

	cout << "\n\nif you want another try, insert 1";
	cin >> c1;
	}
	
	cout << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		int m;
		cin >> m;
	}
	return 0;
}


void RadixSort(int r)
{
	int i, j, x, d, flag = 0, p = -1;
	d = r / 10;
	for (i = 0; i < N; i++)
		for (j = 0; j < 10; j++)
		{ 
			hold[i][j] = -1;
			
}
	for (i = 0; i < N; i++)
	{
		x = A[i] % r;
		int m = x / d;
		if (m > 0) flag = 1;
		hold[i][m] = A[i];
	

	}

	for (j = 0;j < 10;j++)
	{
		for (i = 0; i < N; i++)
		{
			if (hold[i][j] != -1)
			{
				p++;
				A[p] = hold[i][j];

			}
			loop++;
		}
		loop++;
	}

	if (flag == 1)
		RadixSort (r*10);
}
void InsertionSort()
{
	int i, k, temp;
	for (k = 1; k< N; k++)
	{
		temp = A[k];
		for (i = k - 1; i >= 0 && temp<A[i]; i--)
		{ 
			A[i + 1] = A[i];
			loop++;
		}
		loop++;
		A[i + 1] = temp;
	}
}

void SelectionSort()
{
	int k, loc, temp, min, j;

	for (k = 0;k < N - 1;k++)
	{
		min = A[k]; 
		loc = k;

		for (j = k + 1;j < N;j++)
		{
			if (min > A[j])
			{
				min = A[j];
				loc = j;
			}
			loop++;
		}
		loop++;
		temp = A[k]; 
		A[k] = A[loc];
		A[loc] = temp;
	}
}



