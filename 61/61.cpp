#include <iostream>
using namespace std;
int N, M = 0;
int arr[10];
bool checkArr[10] = {false, };
bool isMinus[10] = {false, };
bool isFinished = false;

void DFS(int level){
	if(isFinished)
		return;
		
	if(level > N) {
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			if(checkArr[i] == true)
			{
				int num = 0;
				if(isMinus[i] == true){
					num = -1*arr[i];
				}
				else
					num = arr[i];
				sum += num;
			}
		}
		if(sum == M)
			isFinished = true;
		return;
	}
	
	checkArr[level] = true;
	isMinus[level] = false;
	DFS(level+1);

	checkArr[level] = true;
	isMinus[level] = true;
	DFS(level+1);
	
	checkArr[level] = false;
	isMinus[level] = false;
	DFS(level+1);
	
	checkArr[level] = false;
	isMinus[level] = true;
	DFS(level+1);
}

int main() {
	// your code goes here
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	DFS(0);
	
	if(isFinished) cout << "YES";
	else cout << "NO";
	return 0;
}
