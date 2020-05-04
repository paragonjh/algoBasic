#include <iostream>
using namespace std;

int arr[16] = {0, };
int visit[16] = {0, };
int val[16] = {0, };

int N, R, cnt = 0;
void DFS(int level)
{
	if(level > R)
	{
		//print
		for(int i = 1; i <= R; i++){
			cout << val[i] << " ";
		}
		cout << endl;
		cnt++;
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(visit[i] == 0){
			val[level] = arr[i];
			visit[i] = 1;
			DFS(level+1);
			visit[i] = 0;
		}
	}
}

int main() {
	// your code goes here
	cin >> N >> R;
	
	for(int i = 1; i <= N; i++) {
		int a = 0;
		cin >> a;
		arr[i] = a;
	}
	
	DFS(1);
	cout << cnt;
	return 0;
}
