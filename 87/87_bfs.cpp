#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, num = 0;
int map[20][20] = {0, };
int landCnt = 0;
int dx[8] = {0,0,1,-1,-1,1,1,-1};
int dy[8] = {-1,1,0,0,-1,1,-1,1};

class Node
{
public:
	Node(int _x, int _y) : x(_x), y(_y) {};
	int x;
	int y;
};
queue<Node> q;
void BFS(Node startNode)
{
	q.push(startNode);
	map[startNode.y][startNode.x] = landCnt + 10;
	
	while(!q.empty())
	{
		Node node = q.front(); q.pop();
		for(int i = 0; i < 8; i++)
		{
			int nextX = node.x + dx[i];
			int nextY = node.y + dy[i];
			if(map[nextY][nextX] == 1) {
				map[nextY][nextX] = landCnt + 10;
				q.push(Node(nextX, nextY));
			}
		}
	}
}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> num;
			map[i][j] = num; 
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] == 1) {
				landCnt++;
				BFS(Node(j,i));
			}
		}
	}
	
	cout << landCnt <<endl;;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
