#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v = {8,6,4,2,1};

bool cmp(int a, int b)
{
	return a < b;
}

bool binarySearch(int num)
{
	bool bRet = false;
	int start = 0;
	int end = v.size()-1;
	while(start <= end)
	{
		int index = (start + end) /2;
		if(num == v[index]) {
			return true;
		}
		else if(num > v[index]) {
			start = index+1;
		}
		else {
			end = index-1;
		}
	}
	
	return bRet;
}

int main() {
	// your code goes here
	sort(v.begin(), v.end(), cmp);

    if(binarySearch(7) == true)
    	cout << "exist";
    else
    	cout << "not exist";

	return 0;
}
