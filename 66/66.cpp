#include <iostream>
#include <vector>
using namespace std;

vector<int> map[21];
int visit[21] = {0, };
int N, cnt = 0;

void DFS(int v)
{
	if(v == N){
		cnt++;
		return;
	}
	
	for(int i = 0; i < map[v].size(); i++) {
		if(visit[map[v][i]] == 0)
		{
			visit[map[v][i]] = 1;
			DFS(map[v][i]);
			visit[map[v][i]] = 0;
		}
	}
}

int main() {
	// your code goes here
	int M, a, b = 0;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}
	visit[1] = 1;
	DFS(1);
	cout << cnt;
	return 0;
}
