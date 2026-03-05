#ifndef _LL_H
#define _LL_H

#include <iostream>
using namespace std;

// Class Node Header ( House)
class Node {
	int data;
	Node* next;
	Node();
	Node(int d);
	Node(int d, Node* n);
	friend class LL;
};
// Class Linked List (LL... aka Scavenger Hunt)
class LL {
	Node* head;
public:
	LL();
	bool Insert(int e);
	void Print()const;
	Node* Search(int e)const;
	double GetAverage()const;
	bool Remove(int e);
	bool Copy(LL ref);
};






#endif 
