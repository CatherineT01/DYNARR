#ifndef _BST_H
#define _BST_H

#include <iostream>
using namespace std;

template <class Type> 
class BNode {
	Type data;
	BNode* left;
	BNode* right;
	BNode();
	BNode(Type e);
	BNode(Type e, BNode* l, BNode* r);
	template <class T>
	friend ostream& operator<<(ostream& os, const BNode<T>& b);
	template <class T>
	friend class BST;

};
template <class Type> 
class BST {
	BNode<Type>* root;
	bool InsertHelper(Type e, BNode<Type>*& subroot);
	void PrintInOrderHelper(BNode<Type>* subroot)const;
	int Count(BNode<Type>* subroot)const;
	void OtherCount(BNode<Type>* subroot, int& c)const;
public:
	BST();
	bool Insert(Type e);
	void PrintInOrder()const;
	int Count()const;
	int OtherCount()const;
};





template <class Type>
BNode<Type>::BNode() :left(nullptr), right(nullptr) {}

template <class Type>
BNode<Type>::BNode(Type e) :data(e), left(nullptr), right(nullptr) {}

template <class Type>
BNode<Type>::BNode(Type e, BNode<Type>* l, BNode<Type>* r) :data(e), left(l), right(r) {}


template <class Type>
ostream& operator<<(ostream& os, const BNode<Type>& b) {
	os << b.data;
	return os;
}

template <class Type>
BST<Type>::BST() :root(nullptr) {}

template <class Type>
bool BST<Type>::Insert(Type e) {
	return InsertHelper(e, root);
}


template <class Type>
bool BST<Type>::InsertHelper(Type e, BNode<Type>*& subroot) {
	bool success = false;
	if (subroot == nullptr) { //if subroot is null, we need to insert here
		subroot = new BNode(e); // allocate space for a Node at subroot
		if (subroot != nullptr)
			success = true;
	}
	else {
		if (e == subroot->data) { //duplicate
			cout << "No dupes!" << endl;
		}
		else if (e < subroot->data) {
			success = InsertHelper(e, subroot->left);
		}
		else // e > subroort->data
			success = InsertHelper(e, subroot->right);
	}
	return success;
}


template <class Type>
void BST<Type>::PrintInOrder()const {
	PrintInOrderHelper(root);
}


template <class Type>
void BST<Type>::PrintInOrderHelper(BNode<Type>* subroot)const {
	if (subroot != nullptr) {
		PrintInOrderHelper(subroot->left);
		cout << subroot->data << endl;
		PrintInOrderHelper(subroot->right);
	}


}


template <class Type>
int BST<Type>::Count(BNode<Type>* subroot)const {
	int retval = 0;
	if (subroot != nullptr)
		retval = 1 + Count(subroot->left) + Count(subroot->right);
	return retval;
}


template <class Type>
int BST<Type>::Count()const {
	return Count(root);

}


template <class Type>
void BST<Type>::OtherCount(BNode<Type>* subroot, int& c)const {
	if (subroot != nullptr) {
		c++;
		OtherCount(subroot->left, c);
		OtherCount(subroot->right, c);
	}

}


template <class Type>
int BST<Type>::OtherCount()const {
	int count = 0;
	OtherCount(root, count);
	return count;
}




#endif