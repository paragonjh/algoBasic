#include <iostream>
using namespace std;
int N = 0;
int nArr[10] = {0, };
int checkArr[10] = {0, };
bool isFinished = false;

bool IsSumSame()
{
	int sum1=0;
	int sum2=0;
	
	for(int i = 0; i < N; i++){
		if(checkArr[i] == 0) {
			sum1 += nArr[i];
		}
		else {
			sum2 += nArr[i];
		}
	}
	/*
	cout << "print1 {";
	for(int i = 0; i < N; i++){
		if(checkArr[i] == 0) {
			cout << nArr[i] <<" ";
		}
	}
	cout<< "}" << endl;
	
	cout << "print2 {";
	for(int i = 0; i < N; i++){
		if(checkArr[i] == 1) {
			cout << nArr[i] <<" ";
		}
	}
	cout<< "}" << endl;
	
	cout << "sum1:"<<sum1<<" sum2:"<<sum2<<endl;
	*/
	return sum1 == sum2 ? true: false;
}

void DFS(int level)
{
	if(isFinished)
		return;
		
	if(level > N)
	{
		isFinished = IsSumSame();
		return;
	}
	
	checkArr[level] = 1;
	DFS(level+1);
	
	checkArr[level] = 0;
	DFS(level+1);
}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> nArr[i];
	}
	DFS(0);
	if(isFinished)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
