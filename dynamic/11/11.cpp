#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, m = 0;
	int num = 0;
	cin >> n;
	vector<int> coin;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		coin.push_back(num);
	}
	cin >> m;
	vector<int> dp(m+1, 0);
	for(int i = 0; i < coin.size(); i++)
	{
		for(int j = coin[i]; j <= m; j++)
		{
			if(dp[j] == 0)
				dp[j] = dp[j-coin[i]] + 1;
			else
				dp[j] = min(dp[j], dp[j-coin[i]] + 1);
		}
		//print
		//for(int i = 0; i <= m; i++)
		//{
		//	cout << dp[i] << " ";
		//}
		//cout << endl;
	}
	
	cout << dp[m];

	return 0;
}
