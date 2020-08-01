#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int *arr, int start, int end)
{
	if(arr == nullptr)
		return;
	if(start >= end)
		return;
	
	int left = start;
	int right = end;
	int pivot = arr[(start+end)/2];
	
	while(left <= right)
	{
		while(arr[left] < pivot) left++;
		while(arr[right] > pivot) right--;
		if(left <= right)
		{
			swap(&arr[left], &arr[right]);
			left++; right--;
		}
	}
	quickSort(arr, start, right);
	quickSort(arr, left, end);
}

int binarySearch(int *arr, int arrSize, int val)
{
	int retIndex = -1;

	int start = 0;
	int end = arrSize-1;

	while(start <= end)
	{
		int mid = (start+end)/2;
		if(arr[mid] == val)
		{
			retIndex = mid;
			return retIndex;
		}
		else if(arr[mid] < val)
			start = mid + 1;
		else
			end = mid - 1;
	}
	
	return retIndex;
}

int main() {
	// your code goes here
	int arr[] = {5,4,3,2,1};
	quickSort(arr, 0, 4);
	for(int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	} cout << endl;
	
	int index = binarySearch(arr, 5, 3);
	cout << index << endl;
	return 0;
}
