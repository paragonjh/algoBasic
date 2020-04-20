#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool down(int a ,int b)
{
    return a > b ? true : false;
}
int n = 0;
vector<int> num;
int main() {
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val = 0;
		cin >> val;
		num.push_back(val);
	}
	
	sort(num.begin(), num.end(), down);
	
	for(int i = 0; i < n; i++){
		cout << num[i] << " ";
	}
	cout << endl;
	int val = num[0];
	int cnt = 0;
	for(int i = 1; i < n; i++){
		if(val != num[i]) {
			val = num[i];
			cnt++;
		}
		
		if(cnt == 2) {
			cout << num[i] << endl;
			break;
		}
	}
	return 0;
}
