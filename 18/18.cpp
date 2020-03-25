#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, maxAlram = 0;
	int maxCount = -1;
	int count = 0;
	cin >> n >> maxAlram;
	for(int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		if(num >= maxAlram)
			count++;
		else {
			if(count>maxCount)
				maxCount = count;
			count = 0;
		}
	}
	cout << maxCount;
	return 0;
}
