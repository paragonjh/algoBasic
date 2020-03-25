#include <iostream>
using namespace std;

int num[100];
int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int val = 0;
		cin >> val;
		num[i] = val;
	}
	int count = 0;
	for(int i = 0; i < n-1; i++)
	{
		bool isTallest = true;
		for(int j = i+1; j < n; j++)
		{
			if(num[i] <= num[j]) {
				isTallest = false;
				break;
			}
		}
		if(isTallest == true){
			//cout << num[i] << endl;
			count++;
		}
	}
	cout << count;
	return 0;
}

