#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class DATA
{
public:
	DATA(int _index, int _value) : index(_index), value(_value) {};
	int index;
	int value;
};

struct cmp{
	bool operator()(DATA a, DATA b){
		return a.value > b.value ? true : false;
	}	
};

vector<DATA> data[101];
priority_queue<DATA, vector<DATA>, cmp> pQ;
int visit[101] = {0, };
int main() {
	// your code goes here
	int V, E = 0;
	int a,b,c = 0;
	cin  >> V >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		data[a].push_back(DATA(b,c));
		data[b].push_back(DATA(a,c));
	}
	pQ.push(DATA(1,0));
	int sum = 0;
	while(!pQ.empty()) {
		DATA checkData = pQ.top(); pQ.pop();
		if(visit[checkData.index] == 0){
			sum += checkData.value;
			visit[checkData.index] = 1;
			for(int i = 0; i < data[checkData.index].size(); i++) {
				pQ.push(DATA(data[checkData.index][i].index,data[checkData.index][i].value));
			}
		}
	}
	cout << sum;
	return 0;
}
