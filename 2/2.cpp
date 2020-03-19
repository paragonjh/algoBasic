#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int N,M, SUM = 0;
	cin >> N >> M;
	string s;
	for(int i = N; i <= M; i++){
		SUM += i;
		if(i != M)
			s += to_string(i)+" + ";
		else
		    s += to_string(i);
	}
	cout << s.c_str() << " = " <<SUM <<endl;
	return 0;
}
