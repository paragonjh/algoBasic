#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Node
{
public:
	Node(int _x, int _y) : x(_x), y(_y) {};
	int x;
	int y;
};
vector<Node> startNode;
queue<Node> q;

int map[1001][1001] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int zeroCnt = 0;
int x,y = 0;
int BFS()
{
	if(zeroCnt == 0)
		return 0;

	int maxDay = 0;
	for(int i = 0; i < startNode.size(); i++)
	{
		q.push(startNode[i]);
	}
	
	while(!q.empty())
	{
		Node node = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int nextX = node.x + dx[i];
			int nextY = node.y + dy[i];
			if(map[nextY][nextX] == 0) {
				if((nextX>=0) && (nextX<x) && (nextY>=0) && (nextY<y))
				{
					zeroCnt--;
					int day = map[nextY][nextX] = map[node.y][node.x]+1;
					if(maxDay < day)
						maxDay = day;
					q.push(Node(nextX, nextY));
				}
			}
		}
	}
	if(zeroCnt != 0)
		return -1;
	return maxDay-1;
}

int main() {
	// your code goes here
	cin >> x >> y;
	int num = 0;
	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			cin >> num;
			if(num == 0)
				zeroCnt++;
			else if(num == 1) {
				startNode.push_back(Node(j, i));
			}
			map[i][j] = num;
		}
	}
	
	/*
	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
	//cout << "--------"<<endl;
	cout << BFS();
	//cout << zeroCnt << endl;
	/*
	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
