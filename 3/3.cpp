#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int N, SUM = 1;
	cin >> N;
	cout << "1";
	for(int i = 2; i < N; i++)
	{
		if(N % i == 0) {
			SUM += i;
			cout <<" + "<< i;
		}
	}
	cout << " = " << SUM << endl;
	return 0;
}
