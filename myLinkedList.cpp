#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* nextNode;
};

class LinkedList
{
public:
	LinkedList() {
		size = 0;
	}
	~LinkedList() {
		Node *itor = head;
		for(int i = 0; i < size; i++)
		{
			Node *nextNode = itor->nextNode;
			delete itor;
			itor = nextNode;
		}
		size = 0;
	}a
	void addNode(int data)
	{
		if(size == 0)
		{
			head = new Node;
			head->data = data;
			head->nextNode = nullptr;
		}
		else
		{
			Node *nextNode = new Node;
			nextNode->data = data;
			nextNode->nextNode = nullptr;
			
			Node *itor = head;
			while(itor->nextNode != nullptr)
				itor = itor->nextNode;
			itor->nextNode = nextNode;
		}
		size++;
	}
	
	void deleteNode(int index)
	{
		if(index > size-1 || index < 0)
			return;
		Node *deleteNode;
		Node *tempNode = head;
		Node *itor = head;
		if(index == 0)
		{
			head = head->nextNode;
			deleteNode = tempNode;
		}
		else
		{
		    for(int i = 0; i < index-1; i++)
		    {
				itor = itor->nextNode;
			}
			Node *deleteNode = itor->nextNode;
			Node *swapNode = deleteNode->nextNode;
			itor->nextNode = swapNode;
		}
		delete deleteNode;
		size--;
	}
	
	int getSize(void){ return size; }
	void printData()
	{
		Node* itor = head;

		for(int i = 0; i < size; i++)
		{
			cout << itor->data <<" ";
			itor = itor->nextNode; 
		}
		cout << endl;
	}
private:
	int size;
	Node* head;
};

int main() {
	// your code goes here
		// your code goes here
	LinkedList li;
	
	li.addNode(1);
	li.addNode(2);
	li.addNode(3);
	li.printData();
	cout <<"size:"<< li.getSize() << endl;
	cout <<"==========" << endl;
	li.deleteNode(1);
	li.printData();
	cout <<"size:"<< li.getSize() << endl;
	return 0;
}
