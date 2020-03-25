#include <iostream>
using namespace std;

void makeBinary(int n)
{
	if(n == 0){
		return;
	}
	else {
		int val = n/2;
		int mod = n%2;
		makeBinary(val);
		cout<<mod;
	}
}

int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	makeBinary(n);
	return 0;
}
