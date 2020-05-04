#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;

void stl_combination(vector<int>arr, int N, int R)
{
	vector<int> check;
	for(int i = 0; i < N-R; i++)
	{
		check.push_back(0);
	}
	
	for(int i = 0; i < R; i++)
	{
		check.push_back(1);
	}
	
	sort(check.begin(), check.end());
	
	do {
		for(int i = 0; i < check.size(); i++)
		{
			if(check[i] == 1)
			{
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		cnt++;
	} while(next_permutation(check.begin(), check.end()));
}

int main() {
	// your code goes here
	int N, R = 0;
	int num = 0;
	cin >> N >> R;
	vector<int> arr;
	for(int i = 0; i < N; i++){
		cin >> num;
		arr.push_back(num);
	}
	stl_combination(arr, N, R);
	cout << cnt;
	return 0;
}
