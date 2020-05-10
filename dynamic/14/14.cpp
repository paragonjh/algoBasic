#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
	for(int i = 0; i <=n; i++)
		dis[i][i] = 0;

	while(1)
	{
		int a ,b = 0;
		cin >> a >> b;
		if(a == -1)
			break;
		dis[a][b] = 1;
		dis[b][a] = 1;
	}
	
	//for(int i = 1; i <= n; i++)
	//{
	//	for(int j = 1; j <= n; j++)
	//	{
	//		cout << dis[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	//cout << endl;
	//for(int i = 1; i <= n; i++)
	//{
	//	int max = 0;
	//	for(int j = 1; j <= n; j++)
	//	{
	//		if(dis[i][j] == 5000)
	//			dis[i][j]  = 0;
	//		cout << dis[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	vector<int> res(n+1);
	int score = 100;
	for(int i =1; i<=n; i++) {
		for(int j = 1; j <=n; j++) {
			res[i] = max(res[i], dis[i][j]);
		}
		score = min(score, res[i]);
	}
	int cnt = 0;
	for(int i = 1; i<=n; i++){
		if(res[i] == score) cnt++;
	}
	cout << score<<" " <<cnt << endl;
	for(int i = 1; i<=n; i++) {
		if(res[i] == score)
			cout << i << " ";
	}

	return 0;
}
