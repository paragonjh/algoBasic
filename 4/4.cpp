#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
	// your code goes here
	int num = 0;
	cin >> num;
	int min = INT_MAX;
	int max = INT_MIN;
	for(int i = 0; i < num; i++)
	{
		int n = 0;
		cin >> n;

		if(n > max)
		 max = n;
		if(n < min)
		 min = n;
	}
	cout << max - min << endl;
	return 0;
}
