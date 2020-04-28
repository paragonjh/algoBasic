#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N, M = 0;
	int p1, p2, p3 = 0;
	
	int arr1[101] = {0, };
	int arr2[101] = {0, };
	int arr3[201] = {0, };
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> arr2[i];
	}
	
	while((p1 < N) && (p2 < M)) {
		if(arr1[p1] < arr2[p2]) {
			arr3[p3++] = arr1[p1++];
		} else {
			arr3[p3++] = arr2[p2++];
		}
	}
	
	while(p1 < N){
		arr3[p3++] = arr1[p1++];
	}
	
	while(p2 < M){
		arr3[p3++] = arr2[p2++];
	}
	
	for(int i = 0; i < N+M; i++) {
		cout << arr3[i] << " ";
	}
	return 0;
}
