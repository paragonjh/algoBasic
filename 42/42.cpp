#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

int main() {
	// your code goes here
	cin >> N >> M;
	vector<int> arr;
	for(int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(),arr.end());

	int start = 0;
	int end = N;
	int index = -1;
	
	while(1)
	{
		index = (start+end) / 2;
		if(arr[index] == M)
		{
			break;
		}
		else if(arr[index] < M)
		{
			start = index + 1;
		}
		else
		{
			end = index - 1;
		}
	}

	cout << index +1 << endl;
/*
	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
*/
	return 0;
}
