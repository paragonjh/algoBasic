#include <iostream>
using namespace std;
int map[30][30] = {0, };
int visit[30] = {0, };
int cnt = 0;
void DFS(int start, int end)
{
	if(start == end) {
		cnt++;
		for(int i = 1; i <= end; i++){
			if(visit[i] == 1)
				cout << i << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i = 1; i <= end; i++) {
		if(map[start][i] == 1 && visit[i] == 0)
		{
			visit[i] = 1;
			DFS(i, end);
			visit[i] = 0;
		}
	}
}

int main() {
	// your code goes here
	int N, M = 0;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int a,b = 0;
		cin >> a >> b;
		map[a][b] = 1;
	}
	visit[1] = 1;
	DFS(1, N);
	cout << cnt;
	return 0;
}
