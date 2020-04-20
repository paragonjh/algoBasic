#include <iostream>
using namespace std;

int n;
int arr[100] = {0,};

void insertionSort()
{
    int minIndex = 0;
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        //swap
        int tmp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = tmp;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    insertionSort();
    
    for(int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
