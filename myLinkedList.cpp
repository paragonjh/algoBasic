#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* nextNode;
	Node(int _data) : data(_data), nextNode(nullptr) {}
};

class LinkedList
{
private:
	int size;
	Node* head;

public:
	LinkedList()
	{
		size = 0;
		head = nullptr;
	}
	~LinkedList()
	{
		/*
		if(size > 0)
		{
			Node *itor = head;
			for(int i = 0; i < size; i++)
			{
				Node *deleteNode = itor;
				itor = itor->nextNode;
				delete deleteNode;
			}
		}
		head = nullptr;
		size = 0;
		*/
	}
	int getSize() { return size; }

	void printNode()
	{
		Node *itor = head;
		for(int i = 0; i < size; i++)
		{
			cout << itor->data << " ";
			itor = itor->nextNode;
		}
		cout << endl;
	}

	void addNode(int data)
	{
		if(size == 0)
		{
			head = new Node(data);
			//head->data = data;
			//head->nextNode = nullptr;
		}
		else
		{
			Node *newNode = new Node(data);
			//newNode->data = data;
			//newNode->nextNode = nullptr;
			
			Node *itor = head;
			while(itor->nextNode != nullptr)
			{
				itor = itor->nextNode;
			}
			itor->nextNode = newNode;
		}
		size++;
	}
	
	void deleteNode(int data)
	{
		if(size == 0) return;
		
		Node* itor = head;
		Node* prevNode = nullptr;
		
		if(head->data == data)
		{
			Node* tempNode = head;
			head = tempNode->nextNode;
			delete tempNode;
			size--;
		}
		else
		{
			prevNode = head;
			Node *itor = head->nextNode;
			for(int i = 0; i < size-1; i++)
			{
				if(itor->data == data)
				{
					prevNode->nextNode = itor->nextNode;
					delete itor;
					size--;
					break;
				}
				itor = itor->nextNode;
			}
		}
	}
};

int main() {
	// your code goes here
	LinkedList li;
	
	li.addNode(1);
	li.addNode(2);
	li.addNode(3);
	cout << "Node Size:" << li.getSize() << endl;
	li.printNode();
	
	li.deleteNode(1);
	cout << "Node Size:" << li.getSize() << endl;
	li.printNode();
	
	li.deleteNode(3);
	cout << "Node Size:" << li.getSize() << endl;
	li.printNode();
	return 0;
}
