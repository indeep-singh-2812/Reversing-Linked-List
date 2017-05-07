// Example program to describe the source code to perform reverse operation on a linked list and the printing it. 
// Authro - Indeep Singh
// Date - 05/07/2017

#include <iostream>
#include <string>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class linkedList{
	Node* head;
	public:
		linkedList(){
			head = NULL;
		}
		void Insert(int);
		void ReverseLinkedList();
		void Print();
};

void linkedList::Insert(int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void linkedList::Print(){
	Node* counter = head;
	cout<<"List is :";
	while(counter !=NULL){
		cout<<" "<<counter->data;
		counter = counter->next;
	}
	cout<<"\n";
}

void linkedList::ReverseLinkedList(){
	Node* currentNode;
	Node* prevNode = NULL;
	Node* nextNode;
	currentNode = head;
	while(currentNode != NULL){
		nextNode = currentNode->next; // pointing next node to current->next
		currentNode->next = prevNode; // then, for revering the pointer, current->next is previous.
		prevNode = currentNode; // then pointing prev node to current node.
		currentNode = nextNode; // then updating the current node for the while loop.
	}
	head = prevNode; // atlast, pointing the head to prev node.
}

int main()
{
	linkedList l1;
	l1.Insert(1); 
	l1.Insert(2);
	l1.Insert(3);
	l1.Insert(5);
	l1.Insert(6);
	cout<<"\n Before reversing the linked list. \n";
	l1.Print();
	
	//Performing reverse operation in linked  list.
	l1.ReverseLinkedList();
	cout<<"\n After reversing the linked list. \n";
	l1.Print();
}
