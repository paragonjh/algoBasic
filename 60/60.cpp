#include <iostream>
using namespace std;
int arr[11] = {0, };
int N, totalSum = 0;
bool isFinished = false;

void DFS(int level, int sum)
{
	if(sum > totalSum/2)
		return;
	if(isFinished)
		return;
	if(level > N) {
		if(2*sum == totalSum)
			isFinished = true;
		return;
	}
	
	DFS(level+1, sum+arr[level]);
	DFS(level+1, sum);
}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
		totalSum += arr[i];
	}
	
	DFS(1, 0);
	if(isFinished) cout << "YES";
	else cout << "NO";
	return 0;
}
