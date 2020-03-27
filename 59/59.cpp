#include <iostream>
using namespace std;
int index = 0;
int arr[11] = {0,};
using namespace std;
void DFS(int n)
{
	if(n == index+1) {
		bool bExist = false;
		for(int i = 1; i <= index; i++) {
			if(arr[i] == 1) {
				cout << i << " ";
				bExist = true;
			}
		}
		if(bExist)
			cout << endl;
	}
	else {
		arr[n] = 1;
		DFS(n+1);
		arr[n] = 0;
		DFS(n+1);
	}
}

int main() {
	// your code goes here
	cin >> index;
	DFS(1);
	return 0;
}
