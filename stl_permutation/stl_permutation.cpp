#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt = 0;
void permutation_stl(vector<int> arr, int n, int r)
{
	do {
		cnt++;
		for(int i = 0; i < r; i++) {
			cout << arr[i] <<" ";
		}
		cout << endl;
	} while(next_permutation(arr.begin(), arr.end()));
}

int main() {
	// your code goes here
	int n,r = 0;
	int num = 0;
	vector<int> arr;
	cin >> n >> r;
	for(int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	permutation_stl(arr, n, r);
	cout << cnt ;
	return 0;
}
