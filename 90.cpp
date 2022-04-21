#include <iostream>
#include <queue>
using namespace std;

int map[21][21], ch[21][21];
// up,down,right,left
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct State{
	int x , y ,dis;
	State(int a, int b, int c) {
		x = a;
		y = b;
		dis = c;
	}
	bool operator<(const State &b)const{
		if(dis!=b.dis) return dis>b.dis;
		if(y!=b.y) return y>b.y;
		else return x>b.x;
	}
};

struct Lion{
	int x, y, size, ate;
	void sizeUp() {
		size++;
		ate = 0;
	}
};

int main() {
	// your code goes here
	int n, i, j, res = 0;
	priority_queue<State> Q;
	Lion simba;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) {
				simba.x = j;
				simba.y = i;
				map[i][j] = 0;
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0));
	simba.size = 2;
	simba.ate = 0;
	
	while(!Q.empty()) {
		State tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		
		// ate animal
		if(map[y][x] != 0 && map[y][x] < simba.size) {
			simba.x=x;
			simba.y=y;
			simba.ate++;
			if(simba.ate>=simba.size) simba.sizeUp();
			map[y][x] = 0;
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					ch[i][j] = 0;
				}
			}
			while(!Q.empty()) Q.pop();
			res=tmp.dis;
		}
		// find next
		for(i = 0; i < 4; i++) {
			int nextX = x+dx[i];
			int nextY = y+dy[i];
			if(nextX < 1 || nextX > n || nextY < 1 || nextY > n || ch[nextY][nextX] > 0) continue;
			Q.push(State(nextX,nextY,z+1));
			ch[nextY][nextX] = 1;
		}
	}
	cout << res;
	
	return 0;
}
