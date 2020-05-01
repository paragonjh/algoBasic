#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
	// your code goes here
	int N, K, cnt = 0;
	cin >> N >> K;
	for(int i = 1;  i <= N; i++)
		q.push(i);

	while(!q.empty()) {
		int num = q.front(); q.pop();
		cnt++;
		if(cnt != K) {
			q.push(num);
		} else {
			cnt = 0;
		}
		
		if(q.size() == 1) {
			break;
		}
	}
	cout << q.front();
	return 0;
}
