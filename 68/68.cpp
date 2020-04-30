#include <iostream>
#include <vector>
using namespace std;

class NodeInfo
{
public:
	NodeInfo(int _adjNode, int _cost) : adjNode(_adjNode), cost(_cost) {};
	
	int adjNode;
	int cost;
};

vector<NodeInfo> map[21];
int N = 0;
int visit[21] = {0,};
int minSum = 999999;

void DFS(int node, int sum)
{
	if(node == N){
		if(sum < minSum)
			minSum = sum;
		return;
	}
	
	for(int i = 0; i < map[node].size(); i++){
		if(visit[map[node][i].adjNode] == 0){
			visit[map[node][i].adjNode] = 1;
			DFS(map[node][i].adjNode, sum+map[node][i].cost);
			visit[map[node][i].adjNode] = 0;
		}
	}
}

int main() {
	// your code goes here
	int M = 0;
	int a,b,c = 0;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		map[a].push_back(NodeInfo(b,c));
	}
	visit[1] = 1;
	DFS(1, 0);
	cout << minSum;
	return 0;
}
