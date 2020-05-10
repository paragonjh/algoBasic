#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, m = 0;
	int a,b,c = 0;
	cin >> n >> m;

	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
	
	for(int i = 0; i <= n; i++)
		dis[i][i] = 0;

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dis[a][b] = c;
	}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			if(dis[i][j] == 5000)
				cout << "M ";
			else
				cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
