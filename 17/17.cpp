#include <iostream>
using namespace std;

int makeSum(int index)
{
	return (index*(index+1))/2;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int index, result = 0;
		cin >> index >> result;
		if(makeSum(index) == result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

