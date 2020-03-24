#include <iostream>
#include <vector>
using namespace std;


char sArr1[101];
char sArr2[101];
int alpha_upper1[25];
int alpha_lower1[25];
int alpha_upper2[25];
int alpha_lower2[25];

bool ana()
{
	int bRet = true;
	for(int i = 0; i < 25; i++){
		cout << alpha_upper1[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < 25; i++){
		cout << alpha_upper2[i] << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < 25; i++){
		if(alpha_upper1[i] != alpha_upper2[i])
			return false;
		if(alpha_lower1[i] != alpha_lower2[i])
			return false;
	}
	return bRet;
}

int main() {
	// your code goes here
	scanf("%s",sArr1);
	scanf("%s",sArr2);
	cout << sArr1<< ":" << sArr2 << endl;;
	int i = 0;
	while(sArr1[i] != '\0')
	{
		if(sArr1[i] <= 'Z') {
			int n = sArr1[i] - 'A';
			alpha_upper1[n]++;
		}else {
			int n = sArr1[i] - 'a';
			alpha_lower1[n]++;
		}
		i++;
	}
	i = 0;
	while(sArr2[i] != '\0')
	{
		if(sArr2[i] <= 'Z') {
			int n = sArr2[i] - 'A';
			alpha_upper2[n]++;
		}else {
			int n = sArr2[i] - 'a';
			alpha_lower2[n]++;
		}
		i++;
	}
	cout << (ana() == true ? "YES" : "NO");
	return 0;
}
