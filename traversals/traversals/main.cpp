#include <iostream>
#include <stdlib.h>
#include <process.h>

using namespace std;

struct NODE
{
	int	info;
	struct NODE *Left;
	struct NODE *Right;
};



struct NODE *Root = NULL;

void AttachNode(struct NODE *pRoot, struct NODE *pNew)
{
	if (Root == NULL) // to attach  first node with tree
	{
		Root = pNew;  return;
	}  // attaches node on first root 
	if (pNew->info < pRoot->info)
	{   // traverse to left sub-tree and find null at left
		if (pRoot->Left != NULL)
			AttachNode(pRoot->Left, pNew);
		else
			pRoot->Left = pNew;  // attaches node on left

	}
	else
	{   // traverse to right sub-tree and find null at right
		if (pRoot->Right != NULL)
			AttachNode(pRoot->Right, pNew);
		else
			pRoot->Right = pNew; // attaches node on right
	}
}
void   Insert(int x)
{
	struct NODE *NewNode = new NODE;

	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->info = x;
	AttachNode(Root, NewNode);

}
void Pre_Order(NODE *pRoot)
{
	if (pRoot)
	{
		cout << pRoot->info << "\t";
		Pre_Order(pRoot->Left);
		Pre_Order(pRoot->Right);
	}
}

void   Post_Order(struct NODE *pRoot)
{
	if (pRoot)
	{
		Post_Order(pRoot->Left);
		Post_Order(pRoot->Right);
		cout << pRoot->info << "\t";
	}
}

void  In_Order(NODE *pRoot)
{
	if (pRoot)
	{
		In_Order(pRoot->Left);
		cout << pRoot->info << "\t";
		In_Order(pRoot->Right);
	}
}
void   DisplayDescending(NODE *pRoot)
{
	if (pRoot)
	{
		DisplayDescending(pRoot->Right);
		cout << pRoot->info << "\t";
		DisplayDescending(pRoot->Left);
	}
}
void DeleteTree(struct NODE *pRoot)
// This function deletes all nodes in the tree
//  and   make  Tree  empty
{
	if (pRoot)
	{
		if (pRoot->Right)
		{
			DeleteTree(pRoot->Right);
		}

		if (pRoot->Left)
		{
			DeleteTree(pRoot->Left);
		}

		delete (pRoot);
	}
}
int main(void)
{
	int ch, item;
	while (1)
	{
		cout << "\n\n\n   Binary Search Tree Functions\n\n";
		cout << "\n1. Insert a New Node";
		cout << "\n2. Remove Existing Node";
		cout << "\n3. In-Order Traverse  (Ascending Order)";
		cout << "\n4. Pre-Order Traverse ";
		cout << "\n5. Post-Order Traverse ";
		cout << "\n6. Display in Descending Order   (Reverse)";
		cout << "\n7. Exit";
		cout << "\n Enter you choice: ";
		cin >> ch;
		switch (ch)
		{
		case   1:
			cout << "\n\n put a number: ";     cin >> item;
			Insert(item);
			break;
		case   2:
			//  Remove();  // This function is not defined.
			break;   //  Students shall write this function as home work.
		case 3:
			cout << "\n\n\n In-Order Traverse  \n";
			In_Order(Root);  
			cout << "\n\n";
			break;
		case 4:
			cout << "\n\n\n Pre-Order Traverse \n";
			Pre_Order(Root);
			cout << "\n\n";
			break;
		case 5:
			cout << " \n\n\n Post-Order Traverse \n";
			Post_Order(Root);
			cout << "\n\n";
			break;
		case 6:
			cout << "\n\n\nDESCENDING ORDER  (Reverse )\n";
			DisplayDescending(Root);
			cout << "\n\n";
			break;
		case 7:
			DeleteTree(Root);
			exit(0);   //  it  stops the execution of the program
		default:
			cout << "\n\nInvalid Input";
		} // end of switch
	} // end of while loop
} // end of main( ) function

