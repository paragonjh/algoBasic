#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 문자열에서 반복되지 않는 첫번째 문자를 찾아내는 효율적인 함수를 작성해라.
 * “total” =>”o” , “teeter” = > “r”
*/

char findFirstString(string str)
{
	unordered_map<char, int> arr;
	char returnStr;
	//cout << str.size() << endl;
	for(int i = 0; i < str.size(); i++)
	{
		char tempChar = str.at(i);
		//cout << tempChar << endl;
		auto itor = arr.find(tempChar);
		if(arr.end() == itor)
		{
			arr.insert(make_pair(tempChar, 1));
		}
		else
		{
			itor->second++;
		}
	}

	for(int i = 0; i < str.size(); i++)
	{
		auto itor = arr.find(str.at(i));
		if(itor->second == 1)
		{
			returnStr = itor->first;
			break;
		}
	}

	return returnStr;
}

int main() {
	// your code goes here
	string example[2] = {"total", "teeter"};
	for(int i = 0; i < 2; i++)
	{
		cout << findFirstString(example[i]) << endl;
	}
	
	return 0;
}
