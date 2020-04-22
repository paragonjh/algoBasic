#include <iostream>
using namespace std;
int n;
int arr[100];

void bubbleSort() {
	for(int i = n-1; i > 0; i--) {
		for(int j = 0; j <i; j++) {
			if(arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main() {
	// your code goes here
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	bubbleSort();
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
