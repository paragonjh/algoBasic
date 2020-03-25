#include <iostream>
using namespace std;

void recur(int n)
{
	if(n == 0)
		return;
	else
	{
		recur(n-1);
		cout << n << " ";
	}
}

int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	
	recur(n);
	return 0;
}
