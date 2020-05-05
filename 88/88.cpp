#include <iostream>
#include <queue>
using namespace std;
int map[10][10] = {-1, };
int visit[10][10] = {0, };

class Node
{
public:
	Node(int _x, int _y) : x(_x), y(_y) {};
	int x;
	int y;
};

queue<Node> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
	// your code goes here
	int num = 0;
	for(int i = 1; i <= 7; i++) {
		for(int j = 1; j <=7; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}
	
	q.push(Node(1,1));
	while(!q.empty())
	{
		Node node = q.front(); q.pop();
		visit[node.y][node.x] = 1;
		for(int i = 0; i < 4; i++) {
			int nextX = node.x + dx[i];
			int nextY = node.y + dy[i];
			
			if(nextX < 1 || nextX > 7 || nextY < 1 || nextY > 7)
				continue;
			if((visit[nextY][nextX] == 0) && map[nextY][nextX] == 0)
			{
				map[nextY][nextX] = map[node.y][node.x]+1;
				q.push(Node(nextX, nextY));
			}
		}
	}
	
	//for(int i = 1; i <= 7; i++) {
	//	for(int j = 1; j <=7; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}	
	cout << map[7][7];
	return 0;
}

