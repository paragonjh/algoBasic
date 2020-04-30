#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> map[10];
int visit[10];

void bfs()
{
	while(!q.empty()){
		int index = q.front(); q.pop();
		cout << index << " ";
		for(int i = 0; i < map[index].size(); i++){
			if(visit[map[index][i]] == 0) {
				visit[map[index][i]] = 1;
				q.push(map[index][i]);
			}
		}
	}
}

int main() {
	// your code goes here
	int a,b = 0;
	
	for(int i = 0; i < 7; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	q.push(1);
	visit[1] = 1;
	bfs();
	return 0;
}
