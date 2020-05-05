#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
	Node (int _x, int _y) : x(_x), y(_y) {}; 
	int x;
	int y;
	int distance;
	int calcDistance(Node node){
		int retX = x-node.x;
		if (retX < 0)
			retX = retX * -1;
		int retY = y-node.y;
		if(retY < 0)
			retY = retY * -1;
		return retX + retY;
	}
};

vector<Node> house;
vector<Node> pizza;

int main() {
	// your code goes here
	int N, M = 0;
	int val = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> val;
			if(val == 1) {
				//house
				house.push_back(Node(j,i));
			} else if(val == 2) {
				//pizza
				pizza.push_back(Node(j,i));
			}
		}
	}
	
	vector<int> selectPizza;
	for(int i = 0; i < pizza.size()-M; i++) {
		selectPizza.push_back(0);
	}
	for(int i = 0; i < M; i++) {
		selectPizza.push_back(1);
	}
	int minDistance = 999999;
	do {
		for(int i = 0; i < selectPizza.size(); i++)
		{
			if(selectPizza[i]) {
				//cout << i << " ";
				for(int j = 0; j < house.size(); j++){
					int distance = house[j].calcDistance(pizza[i]);
					//cout << "pizza shop:("<<pizza[i].y <<","<< pizza[i].x << ") house:(" <<house[j].y<<","<<house[j].x <<") distance:"<<distance<<endl;
					if(distance < house[j].distance)
						house[j].distance = distance;
				}
			}
		}
		//cout << endl;
		int sumDistance = 0;
		for(int i = 0; i < house.size(); i++) {
			sumDistance += house[i].distance;
		}
		if(sumDistance < minDistance)
			minDistance = sumDistance;
	} while(next_permutation(selectPizza.begin(), selectPizza.end()));
	cout << minDistance;
	return 0;
}
