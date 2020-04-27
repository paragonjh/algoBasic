#include <iostream>
using namespace std;
int N, M = 0;
int arr[10] = {0, };

int cnt = 0;
void DFS(int level, int val){
	if(level >= N) {
		if(val == M) {
			cnt++;
		}
		return;
	}
	
	DFS(level+1, val + arr[level]);
	DFS(level+1, val - arr[level]);
	DFS(level+1, val);
}

int main() {
	// your code goes here
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	DFS(0, 0);
	if(cnt  == 0) cnt = -1;
	cout << cnt << endl;
	return 0;
}

