#include <iostream>
using namespace std;

char arr[101];
int index[10];
int main() {
	// your code goes here
	cin >> arr;
	//cout << arr;
	int i = 0;
	while(arr[i] != '\0')
	{
		int n = arr[i] - '0';
		index[n]++;
		i++;
	}
	int max = -1;
	int maxIndex = -1;
	for(int i = 0; i < 10; i++)
	{
		if(max <= index[i]){
			max = index[i];
			maxIndex = i;
		}
	}
	cout << maxIndex;
	return 0;
}
