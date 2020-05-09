#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
	Node(int s,int h,int w) : size(s), height(h), weight(w) {};
	int size;
	int height;
	int weight;
};
vector<Node> arr;
int dp[101] = {0, };

bool cmp(Node a, Node b)
{
	return a.size > b.size;
}

int main() {
	// your code goes here
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int s,h,w;
		cin >> s >> h >> w;
		arr.push_back(Node(s,h,w));
	}
	sort(arr.begin(),arr.end(), cmp);

	dp[0] = arr[0].height;
	int maxHeightIndex = 0;
	int maxHeight = 0;
	for(int i = 1; i < arr.size(); i++)
	{
		int max_h = 0;
		for(int j = i-1; j >= 0; j--)
		{
			if(arr[i].weight < arr[j].weight) {
				if(max_h < dp[j])
					max_h = dp[j];
			}
		}
		dp[i] = max_h + arr[i].height;
		if(maxHeight < dp[i])
		{
			maxHeight = dp[i];
			maxHeightIndex = i;;
		}
	}
	cout << maxHeight <<endl;
	return 0;
}
