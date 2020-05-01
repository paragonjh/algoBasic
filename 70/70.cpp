#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M = 0;
vector<int> map[21];
queue<int> q;
int visit[21] = {0, };
int dis[21] = {0, };

void BFS()
{
	while(!q.empty())
	{
		int index = q.front(); q.pop();
		for(int i = 0; i < map[index].size(); i++) {
			if(visit[map[index][i]] == 0) {
				visit[map[index][i]] = 1;
				q.push(map[index][i]);
				dis[map[index][i]] = dis[index] +1;
			}
		}
	}
}

int main() {
	// your code goes here
	int a,b = 0;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		map[a].push_back(b);
	}
	q.push(1);
	visit[1] =1;
	BFS();
	
	for(int i = 2; i <= N; i++) {
		cout << i <<" : "<<dis[i]<<endl;
	}
	return 0;
}
