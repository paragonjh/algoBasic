#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Data{
public:
	Data(int _money, int _day): money(_money), day(_day){};
	int day;
	int money;
};

bool compare_day(Data a, Data b)
{
	return a.day > b.day ? true : false;
}

class CompareMoney{
public:
	bool operator()(Data a, Data b){
		return a.money < b.money ? true : false;
	}	
};

priority_queue<Data, vector<Data>, CompareMoney> pQ;
vector<Data> v;

int main() {
	// your code goes here
	int N, M, D = 0;
	int totalSum = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> M >> D;
		v.push_back(Data(M,D));
	}
	sort(v.begin(), v.end(), compare_day);
	
	int index = 0;
	int maxDay = v[0].day;
	while(1)
	{
		if(index > v.size())
			break;
		Data data = v[index++];
		if(data.day == maxDay)
			pQ.push(data);
		else {
			Data MaxVal = pQ.top(); pQ.pop();
			cout << MaxVal.money << endl;
			totalSum += MaxVal.money;
			maxDay = data.day;
			pQ.push(data);
		}
	}
	
	//for(int i = 0; i < v.size(); i++){
	//	cout << v[i].day << " : " << v[i].money << endl;
	//}
	cout <<"totalSum:"<< totalSum;
	
	return 0;
}
