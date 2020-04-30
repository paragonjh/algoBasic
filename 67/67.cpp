#include <iostream>
using namespace std;
int map[21][21] = {0, };
int visit[21] = {0, };
int N = 0;
int minSum = 99999999;

void DFS(int v, int sum)
{
	if(v == N) {
		if(sum  < minSum) {
			minSum = sum;
		}
		return;
	}
	
	for(int i = 1; i <=N; i++) {
		if(visit[i] == 0 && map[v][i] != 0) {
			visit[i] = 1;
			DFS(i, sum+map[v][i]);
			visit[i] = 0;
		}	
	}
}

int main() {
	// your code goes here
	int M = 0;
	int a,b,c;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	visit[1] = 1;
	DFS(1, 0);
	cout << minSum;
	return 0;
}

