#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n,m = 0;
	cin >> n >> m;
	int dp[m+1] = {0, };
	for(int i = 0; i < n; i++) {
		int score, time = 0;
		cin >> score >> time;
		for(int j = m; j >= time; j--)
		{
			dp[j] = max(dp[j], dp[j-time] + score);
		}
	}
	
	//for(int i = 0; i <= m; i++)
	//{
	//	cout << dp[i] << " ";
	//}
	
	cout << dp[m];
	return 0;
}
