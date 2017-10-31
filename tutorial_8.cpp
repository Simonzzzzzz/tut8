//Student name:	ZHOU Zhenghao	
//Studnet ID  :	54381018

// Submission deadline: 5 Nov 2017, Sunday, 11 pm

/*
	Part 1: 
	Implement the function maxSubSeq()
		- return the sum of the max subsequence
		- determine the first node and the last node of the max subsequence
		- refer to the notes for the algorithm to compute the max subsequence

	Part 2:
	Implement a function to sort a linked list into descending order, i.e. large to small.

*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

//----------------------------------- linked list structure and functions prepared for you

struct node 
{
    int info;
    node *link;
};

node* createNode(int info) 
{
	node *p = new node;   
	p->info = info;
	p->link = NULL;
	return p;
}

int genNum(int range, int allowNegative)
{
	int k = rand() % range;
	if (k != 0 && allowNegative)
	{
		if (rand() % 2)
			k = -k;
	}
	return k;
}

node* genList(int n, int allowNeg)
{
	node *list = NULL;	
	if (n > 0)
	{
		int range = 2 * n;
		list = createNode(genNum(range, allowNeg));
		node *p = list;
		for (int i = 1; i < n; i++)
		{		
			p->link = createNode(genNum(range, allowNeg));
			p = p->link;
		}
	}
	return list;
}

void printList(node *list) 
{
    node *p = list;
	int i = 0;

    while (p != NULL) 
	{
        cout << "(" << setw(3) << p->info << ") -> ";
		i++;
		if (i % 8 == 0)  // print up to 8 nodes per line
			cout << endl;
        p = p->link;
    }
    cout << "NULL\n\n";
}

// ------------------------------------------------- functions to be implemented by you

int maxSubSeq(node *list, node*& first, node*& last)
{
	// Return the sum of the max subsequence.
	// Determine first and last, i.e. the first and last node of the max subsequence.
	if(list!=NULL){
	node *cur=list;
	int max=cur->info;
	int curSub=cur->info;
	first=NULL;
	last=NULL;
	node *curStart=cur;
	node *curEnd=cur;
	cur=cur->link;
	while(cur!=NULL){
		if(curSub>0){
			curSub+=cur->info;
			curEnd=cur;
			cur=cur->link;
		}
		else{
			curSub=cur->info;
			curStart=cur;
			cur=cur->link;
		}
		if(curSub>max){
			max=curSub;
			first=curStart;
			last=curEnd;
		}
	}
	return max;
	}
	else{
		return 0;
	}
}



// Put your function sortDescending( ??? parameter ??? ) here.
// Sort a linked list into descending order, i.e. large to small.
// DO NOT copy data from one node to another node.
// Sort the list by reorganizing the links.
void sortDescending(node *list){
	

}


// -------------------------------------------- main function and test function

void test(node *list)
{
	node *s, *e;
	s = e = NULL;
	int max = maxSubSeq(list, s, e);

	cout << "Nodes in maxSubSeq : \n";
	if (s == NULL)
		cout << "  empty subsequence\n\n";
	else
	{
		int i = 0;
		node *p = s;
		bool done = false;
		while (!done)
		{			
			cout << "(" << setw(3) << p->info << ")";
			if (p != e)				
			{
				cout << " -> ";
				p = p->link;
				i++;
				if (i % 8 == 0)
					cout << endl;
			}
			else
			{
				done = true;
				cout << "\n\n";
			}
		}
	}
	cout << "Sum of maxSubSeq = " << max << endl;
}

int main() 
{
	// Part-1

	srand((unsigned)time(NULL));
	int n = 20;
	int allowNeg = 1;
	node *listA = genList(n, allowNeg);

	cout << "List A: \n";
	printList(listA);
	test(listA);

	cout << "----------------------------------------------\n";
	n = 10;
	allowNeg = 0;
	node *listB = genList(n, allowNeg);
	cout << "List B: \n";
	printList(listB);
	test(listB);
	
	cout << "----------------------------------------------\n";
	node *listC = NULL;
	cout << "List C: \n";
	printList(listC);
	test(listC);

	
	// Part-2

	cout << "----------------------------------------------\n";
	cout << "call sortDescending(listB)\n";
	sortDescending(listB);
	cout << "List B: \n";
	printList(listB);

	cout << "----------------------------------------------\n";
	cout << "call sortDescending(listC)\n";
	sortDescending(listC);
	cout << "List C: \n";
	printList(listC);
	
	system("pause");
	return 0;
}

