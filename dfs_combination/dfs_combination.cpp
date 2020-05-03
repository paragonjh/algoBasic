#include <iostream>
#include <vector>

using namespace std;
int N,M = 0;
vector<int> list;
int cnt = 0;
void DFS(int index)
{
	if(list.size() == M)
	{
		cnt++;
		for(int i = 0; i < list.size(); i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}
	
	for(int i = index; i <= N; i++)
	{
		list.push_back(i);
		DFS(i+1);
		list.pop_back();
	}
}

int main() {
	// your code goes here
	cin >> N >> M;
	DFS(1);
	cout << cnt;
	return 0;
}
