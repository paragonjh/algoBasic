#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}

void quickSort(int* arr, int start, int end)
{
	if(start >= end) return;
	
	int pivot = arr[(start+end)/2];
	int left = start; int right = end;
	
	while(left <= right)
	{
		while(arr[left] < pivot) left++;
		while(arr[right] > pivot) right--;
		if(left <= right)
		{
			swap(arr[left],arr[right]);
			left++; right--;
		}
	}
	quickSort(arr, start, right);
	quickSort(arr, left, end);
}

int main() {
	// your code goes here
	int arr[] = {1,5,3,2,4,9,8,7,6};
	quickSort(arr, 0, 8);
	
	for(int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
