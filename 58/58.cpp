#include <iostream>
using namespace std;

void preOrder(int n){
	if(n > 7) {
		return;
	} else {
		cout << n << " ";
		preOrder(n*2);
		preOrder(n*2+1);
	}
}

void inOrder(int n) {
	if(n > 7) {
		return;
	} else {
		inOrder(n*2);
		cout << n << " ";
		inOrder(n*2+1);
	}
}

void postOrder(int n){
	if(n > 7) {
		return;
	} else {
		postOrder(n*2);
		postOrder(n*2+1);
		cout << n << " ";
	}
}

int main() {
	// your code goes here
	cout << "preOrder:";
	preOrder(1);
	cout << endl << "inOrder:";
	inOrder(1);
	cout << endl << "postOrder:";
	postOrder(1);
	return 0;
}
