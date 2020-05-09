#include <iostream>
using namespace std;
int n = 0;
int dp[46] = {0, };

int dfs(int index)
{
	if(index <= 2)
		return index;
	else {
		if(dp[index] != 0)
			return dp[index];
		else
			return dp[index] = dfs(index-1) + dfs(index-2);
	}
}

int main() {
	// your code goes here
	cin >> n;
	cout <<dfs(7);
	return 0;
}
