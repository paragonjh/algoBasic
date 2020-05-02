#include <iostream>
using namespace std;

int memo[21][21] = {0, };

int DFS(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	
	if(memo[n][r] != 0)
		return memo[n][r];
		
	return DFS(n-1, r-1) + DFS(n-1, r);
}

int main() {
	// your code goes here
	int N, R = 0;
	cin >> N >> R;
	cout << DFS(N,R);
	return 0;
}
