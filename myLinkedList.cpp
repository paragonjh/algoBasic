#include <iostream>
using namespace std;

class Node
{
public:
	Node(void)
	{
		nextNode = nullptr;
		data = 0;
	}
	int data;
	Node* nextNode;
};

class LinkedList
{
public:
	LinkedList(){ 
		head = nullptr;
		nodeSize = 0;
	}
	~LinkedList(){}

	void addNode(int data)
	{
		if(nodeSize == 0)
		{
			head = new Node;
			head->data = data;
			head->nextNode = nullptr;
		}
		else
		{
			Node *nextNode = new Node;
			nextNode->data = data;
			Node *nodeItor = head;
			while(nodeItor->nextNode != nullptr)
			{
				nodeItor = nodeItor->nextNode;
			}
			nodeItor->nextNode = nextNode;
		}
		nodeSize++;
	}

	void deleteNode(int index)
	{
		Node *tempNode = head;
		Node *willDeleteNode;
		Node *swapNode;
		
		if(index != 0) {
			for(int i = 0; i < index-1; i++)
			{
				tempNode = tempNode->nextNode;
			}
			willDeleteNode = tempNode->nextNode;
			swapNode = willDeleteNode->nextNode;
			tempNode->nextNode = swapNode;
		}
		else {
			head = tempNode->nextNode;
			willDeleteNode = tempNode;
		}
		delete willDeleteNode;
	}
	
	int getListSize(void)
	{
		return nodeSize;
	}
	
	void printData(void)
	{
		Node *nodeItor = head;
		
		for(int i = 0; i < nodeSize; i++)
		{
			cout << nodeItor->data << endl;
			nodeItor = nodeItor->nextNode;
		}
	}
private:
	Node *head;
	int nodeSize;
};

int main() {
	// your code goes here
	LinkedList li;
	
	li.addNode(1);
	li.addNode(2);
	li.addNode(3);
	li.printData();
	cout <<"==========" << endl;
	li.deleteNode(1);
	li.printData();
	return 0;
}
