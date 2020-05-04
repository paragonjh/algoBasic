#include <iostream>
#include <vector>
using namespace std;
int n = 0;

class DATA
{
public:
	DATA(int t, int p) : T(t), P(p) {};
	int T;
	int P;
};

vector<DATA> data;
int maxSum = -9999999;

void DFS(int level, int sum)
{
	if(level == n+1) {
		if(sum > maxSum)
			maxSum = sum;
		return;
	}
	
	if(level > n+1)
		return;
		
	//선택하는 경우
	if(level+data[level].T <= n+1) {
		DFS(level+data[level].T, sum + data[level].P);
	}
	//선택하지 않는 경우
	DFS(level+1, sum);
}

int main() {
	// your code goes here
	int a,b = 0;
	cin >> n;
	data.push_back(DATA(0,0));
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		data.push_back(DATA(a,b));
	}
	DFS(1,0);
	cout << maxSum;
	return 0;
}
