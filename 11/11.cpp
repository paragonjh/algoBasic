#include <iostream>
using namespace std;

int findDigit(int num)
{
	int count = 0;
	while(num != 0){
		num = num/10;
		count++;
	}
	return count;
}

int main() {
	// your code goes here
	int num = 0;
	cin >> num;
	int digit = findDigit(num);
	//cout << findDigit(num);
	//9 * 1,90 * 2, 900 * 3,	
	int sum = 0;
	for(int i = 1; i < digit; i++){
		int x = 1;
		if(i != 1)
			for(int j = 1; j <i; j++)
				x *= 10;
		
		sum += 9 * x * i;
	}
	//cout << sum << endl;
	int minusVal = 1;
	for(int i = 1; i < digit; i++)
		minusVal *= 10;
	//cout << minusVal << endl;
	sum += (num - minusVal + 1)*digit;
	cout << sum;
	return 0;
}
