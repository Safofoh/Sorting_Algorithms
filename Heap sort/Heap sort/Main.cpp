#include <iostream>
using namespace std;

int const max = 10;

void insheap(int tree[], int n, int item);
void swap(int tree[], int n, int m1, int m2);
void delheap(int tree[], int n, int item);
void heapsort(int A[], int n);

int main()
{
	int A[max];
	cout << "insert 10 items" << endl;
	for (int i = 0; i < max; i++)
		cin >> A[i];

	heapsort(A, max);


	int j;
	cin >> j;
	return 0;

}




void insheap(int tree[], int n, int item)
{
	
	
	int ptr = item;
	

	if (ptr == 0)
		return;

	if (ptr == 1)
	{ 
		int par = 0;
		if (tree[ptr] <= tree[par])
			return;
		else
		swap(tree, n, ptr, par);
		return;
		}

		while (ptr > 1)
		{
			int par = ptr / 2;
			if (tree[ptr] <= tree[par])
				return;
			else
			swap(tree, n, ptr, par);
			ptr = par;
		}

		for (int j = 0; j < item; j++)
		{
			cout  << tree[j] << " \t\t";

		}

		return;

}

void swap(int tree[], int n, int m1, int m2)
{
	int temp;
	temp = tree[m1];
	tree[m1] = tree[m2];
	tree[m2] = temp;

	return;
}

void delheap(int tree[], int n, int pos)
{

	swap(tree, n, 0, pos);
	if (pos == 1)
	{
			return;	
	}
	/*if (pos == 2)
	{
		if (tree[0]>=tree[1])
		return;
		else
		{
			swap(tree, n, 0, 1);
			return;
		}
		return;
	}
	*/
	pos = pos - 1;
	int ptr = 0;
	int left = 1;
	int right = 2;
	while (right <= pos)
	{
		if (tree[ptr] >= tree[left] && tree[ptr] >= tree[right])
			return;
		if (pos == 1 && tree[ptr] < tree[left])
		{
			swap(tree, n, ptr, left);
			pos = pos - 1;
			return;
		}
		if (tree[right] <= tree[left])
		{
			swap(tree, n, ptr, left);
			ptr = left;
		}
		else
		{
			swap(tree, n, ptr, right);
			ptr = right;
		}

		left = 2 * ptr;
		right = 2 * ptr + 1;
	}

	if ( tree[ptr] < tree[left])
		swap(tree, n, ptr, left);

	for (int j = 0; j < pos; j++)
	{
		cout <<  tree[j] << " \t\t";

	}
	return;
}

void heapsort(int A[], int n)
{
	for (int j = 0; j < n; j++)
	{
		insheap(A, n, j);

	}
	int m = n;
	while (m > 0)
	{
		delheap(A, n, m);
		m--;
	}

	cout << "sorted list ";
	for (int j = 0; j < n; j++)
	{
		cout << A[j] << " \t\t";

	}
	return;

}



