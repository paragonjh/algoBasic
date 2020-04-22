#include <iostream>
using namespace std;
int n;
int arr[100];
void insertionSort(void){
	
	for(int i = 1; i < n; i++) {
		int j = 0;
		int tmp = arr[i];
		for(j = i-1; j >= 0; j--) {
			if(arr[j] > tmp)
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = tmp;
	}
	
}

int main() {
	// your code goes here
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	insertionSort();
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
