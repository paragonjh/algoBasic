#include <iostream>
using namespace std;
int map[8][8] = {0, };
int visit[8][8] = {0, };
int cnt = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int y, int x)
{
	if(y == 7 && x == 7){
		cnt++;
		return;
	}
	for(int i = 0; i < 4; i++){
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		//경계 확인
		if(nextY < 1 || nextY > 7 || nextX < 1 || nextX > 7)
			continue;
		if(map[nextY][nextX] == 0 && visit[nextY][nextX] == 0) {
			visit[nextY][nextX] = 1;
			//map[nextY][nextX] = 2;
			DFS(nextY, nextX);
			visit[nextY][nextX] = 0;
		}
	}
}

int main() {
	// your code goes here
	for(int i = 1; i < 8; i++) {
		for(int j = 1; j < 8; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
		}		
	}
	visit[1][1] = 1;
	DFS(1,1);
	/*
	for(int i = 1; i < 8; i++) {
		for(int j = 1; j < 8; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout <<cnt;
	return 0;
}
