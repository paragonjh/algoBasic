#include <iostream>
#include <cstring>
using namespace std;

char* reverseStr(char* inputStr, int length)
{
	char* returnStr = new char[length+1];
	int index = 0;
	for(int i = length-1; i >= 0; i--)
	{
		returnStr[index++] = inputStr[i];
	}
	returnStr[index] = '\0';
	return returnStr;
}

int main() {
	// your code goes here
	char str[] = "Hello world";
	char* resultStr = reverseStr(str, strlen(str));
	cout << str << endl;
	cout << resultStr << endl;
	delete resultStr;
	return 0;
}
