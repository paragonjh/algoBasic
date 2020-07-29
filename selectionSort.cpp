#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//오름차순 정렬일때 해당하는 배열 안에서 가장 작은 값부터 찾아서 맨 앞부터 정렬시키는 방법
void selectionSort(int* arr, int len)
{
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}	
}

int main() {
	// your code goes here
	int *arr = new int[5];
	for(int i = 0; i < 5; i++)
		arr[i] = 5-i;
	
	selectionSort(arr,5);

	for(int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	return 0;
}
