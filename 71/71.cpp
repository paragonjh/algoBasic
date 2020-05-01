#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int myDis, cowDis = 0;
int minDis = 999999;
int visit[10010] = {0, };
int dis[10010] = {0, };
queue<int> q;
int d[] = {1, -1, 5};

void BFS()
{
	while(!q.empty()) {
		int currIndex = q.front(); q.pop();
		if(currIndex > 10000 || currIndex < 1 || currIndex == cowDis)
			continue;

		for(int i = 0; i < 3; i++) {
			int nextIndex = currIndex + d[i];
			if(visit[nextIndex] == 0) {
				visit[nextIndex] = 1;
				q.push(nextIndex);
				dis[nextIndex] = dis[currIndex] + 1;
			}
		}
	}
	return;
}

int main() {
	// your code goes here
	cin >> myDis >> cowDis;

	visit[myDis] = 1;
	q.push(myDis);
	BFS();

	cout << dis[cowDis];	
	return 0;
}
