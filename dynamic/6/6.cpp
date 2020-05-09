#include <iostream>
using namespace std;
int arr[1001] = {0, };
int dp[1001] = {0, };

int main() {
	// your code goes here
	int n = 0, num = 0, maxVal = 0, maxValIndex = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
		if(num > maxVal)
		{
			maxVal = num;
			maxValIndex = i;
		}
	}
	//cout << maxVal <<","<< maxValIndex<<endl;
	dp[0] =1;
	for(int i = 1; i < n; i++)
	{
		int max = 0;
		for(int j = i; j > 0; j--)
		{
			if(arr[i] > arr[j]) {
				if(dp[j] > max)
					max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	
	cout << dp[maxValIndex];
	return 0;
}
