#include "LL.h"

Node::Node():next(nullptr) {}
Node::Node(int d):data(d), next(nullptr) {}
Node::Node(int d, Node* n):data(d), next(n) {}

LL::LL():head(nullptr) {}

bool LL::Insert(int e) {
	bool success = true;
	if (head == nullptr || e < head->data  )
		head = new Node(e, head);	
	else {
		Node* curr = head;
		Node* prev = head;
		while (curr != nullptr && e > curr->data) {
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr && e == curr->data) {
			cout << "No duplicates allowed" << endl;
			success = false;
		}
		else
			prev->next = new Node(e, prev->next);
	}

	return success;
}
Node* LL::Search(int e)const {
	Node* found = nullptr;

	Node* curr = head;
	while (curr != nullptr && found == nullptr) {
		if (e < curr->data)
			break;
		if (e == curr->data)
		{
			found = curr;
			break;
		}
		curr = curr->next;
	}
	return found;
}



void LL::Print()const {

	Node* temp = head;				//start at the beginning
	while (temp != nullptr) {		//loop while we are not at the end
		cout << temp->data << endl;  //  "\t" << temp << "\t" << temp->next << endl;    //accessing the current item
		temp = temp->next;					  //moving the iterator to the next item

	}
	/*
	Node* temp = head;				//start at the beginning
	while (temp != nullptr) {		//loop while we are not at the end
		cout << (*temp).data << endl;    //accessing the current item
		temp = (*temp).next;					  //moving the iterator to the next item

	}
	*/


}


double LL::GetAverage()const
{
	int numItems = 0;
	int sum = 0;
	Node* temp = head;

	while (temp != nullptr) {
		sum += temp->data;
		numItems++;

		temp = temp->next;
	}
	return (sum / numItems);
}

bool LL::Remove(int e) {
	bool success = true;

	if (head == nullptr || e < head->data)
		success = false;
	else {
		Node* curr = head;
		Node* prev = head;
		while (curr != nullptr && e > curr->data) {
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr && e == curr->data) {
			if (curr == head)
				head = curr->next;
			else
			{
				prev->next = curr->next;
			}
			cout << "deleting " << curr->data << " from the list." << endl;
			delete curr;
		}
		return success;
	}
}

bool LL::Copy(LL ref) {
	bool success = false;

	if (ref.head != nullptr) {
		Node* temp = ref.head;
		while (temp != nullptr) {
			Insert(temp->data);
			temp = temp->next;
		}
		success = true;
		cout << "The list was copied" << endl;
	}
	else
		cout << "The list was not copied" << endl;

	return success;
}

bool LL::Destroy() {
	bool success = false;

	if (head != nullptr) {
		Node* curr = head;
		Node* temp = head;

		if (curr->next != nullptr)
			temp = temp->next;

		while (temp != nullptr) {
			delete curr;
			curr = temp;
			temp = temp->next;
		}
		if (temp != nullptr) {
			delete temp;
		}

		success = true;

	}



	return success;
}