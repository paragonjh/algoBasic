#include <iostream>
#include <algorithm>
using namespace std;
int map[21][21] = {0, };
int dp[21][21] = {0, };


int DFS(int x, int y)
{
	if(x == 0 && y == 0)
		return dp[y][x] = map[y][x];
		
	if(dp[y][x] != 0)
		return dp[y][x];
	
	if(x ==0)
		return dp[y][x] = DFS(x, y-1) + map[y][x];
	else if(y == 0)
		return dp[y][x] = DFS(x-1, y) + map[y][x];
	else
		return dp[y][x] = min(DFS(x,y-1), DFS(x-1,y)) + map[y][x];
}

int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int num = 0;
			cin >> num;
			map[i][j] = num;
		}
	}
	
	cout<< DFS(n-1,n-1) << endl;
	return 0;
}
