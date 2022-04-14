#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int next;
	int cost;
	Node(int _n, int _c) {
		next = _n; cost = _c;
	}
	bool operator<(const Node &n) const {
		return cost > n.cost;
	}
};

priority_queue<Node> pQ;

int main() {
	int N,M = 0;
	cin >> N >> M;
	vector<Node> map[N+1];
	int maxInt = numeric_limits<int>::max();
	int visit[N+1];
	fill_n(visit, N+1, maxInt);

	for(int i = 1; i <= M; i++) {
		int cur,next,cost = 0;
		cin >> cur >> next >> cost;
		map[cur].push_back(Node(next,cost));
	}
	
	visit[1] = 0;
	pQ.push(Node(1,0));
	
	while(!pQ.empty()) {
		int cur = pQ.top().next;
		int curCost = pQ.top().cost;
		pQ.pop();
		
		if(curCost > visit[cur]) continue;
		for(int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].next;
			int nextCost = map[cur][i].cost;
			if(visit[next] > curCost + nextCost) {
				visit[next] = curCost + nextCost;
				pQ.push(Node(next, curCost + nextCost));
			}
		}
	}
	
	for(int i = 2; i <= N; i++) {
		cout << i << " : ";
		if (visit[i] == maxInt) {
			cout << "impossible" << endl;
		} else {
			cout << visit[i] << endl;
		}
	}
	
	return 0;
}
