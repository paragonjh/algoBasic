#include <iostream>
using namespace std;
int maxSum = -999999;
int minSum = 999999;
int n, num = 0;
int arr[10] = {0, };
int calc[4] = {0, };

void DFS(int level, int sum)
{
	if(level == n)
	{
		if(sum > maxSum)
			maxSum = sum;
		if(sum < minSum)
			minSum = sum;
		return;
	}
	
	if(calc[0] > 0) {
		calc[0]--;
		DFS(level+1, sum+arr[level]);
		calc[0]++;
	}
	
	if(calc[1] > 0) {
		calc[1]--;
		DFS(level+1, sum-arr[level]);
		calc[1]++;		
	}
	
	if(calc[2] > 0) {
		calc[2]--;
		DFS(level+1, sum*arr[level]);
		calc[2]++;
	}
	
	if(calc[3] > 0) {
		calc[3]--;
		DFS(level+1, sum/arr[level]);
		calc[3]++;
	}
}

int main() {
	// your code goes here
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	
	for(int i = 0; i < 4; i++)
	{
		cin >> num;
		calc[i] = num;
	}
	
	DFS(1, arr[0]);
	
	cout << maxSum << endl;
	cout << minSum << endl;
	
	return 0;
}
