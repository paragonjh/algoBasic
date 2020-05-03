#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DATA
{
public:
	DATA(int _indexA, int _indexB, int _value) : indexA(_indexA), indexB(_indexB), value(_value) {};
	
	int indexA;
	int indexB;
	int value;
};

bool cmp(DATA a, DATA b)
{
	return a.value < b.value ? true:false;
}

int map[10001] = {0, };

int Find(int num)
{
	if(map[num] == num)
		return num;
	else
		return map[num] = Find(map[num]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);
	if(x != y)
		map[x] = y;
}

int main() {
	// your code goes here
	vector<DATA> data;
	int V , E = 0;
	cin >> V >> E;
	for(int i = 1; i <= V; i++) {
		map[i] = i;
	}
	
	int a,b,v = 0;
	int sum = 0;
	for(int i = 0; i < E; i++) {
		cin >> a >> b >> v;
		data.push_back(DATA(a,b,v));
	}
	sort(data.begin(), data.end(), cmp);
	
	for(int i = 0; i < data.size(); i++) {
		cout << data[i].indexA << "," <<data[i].indexB <<":"<<data[i].value<<endl;
	}
	
	for(int i = 0; i < E; i++) {
		int x = Find(data[i].indexA);
		int y = Find(data[i].indexB);
		if(x != y) {
			sum += data[i].value;
			Union(data[i].indexA, data[i].indexB);
		}
	}
	cout << sum << endl;
	
	//for(int i = 1; i <= V; i++)
	//{
	//	cout << map[i] << " ";
	//}
	//cout << endl;
	return 0;
}
