#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int A[3][3] = {{1,1,1},
                   {2,2,2},
                   {3,3,3}};                
    int B[3][3] = {{1,2,3},
                   {1,2,3},
                   {1,2,3}};
    int C[3][3] = {0,};
    
    for(int i = 0; i < 3; i++)
    {
    	for(int j = 0; j < 3; j++)
    	{
    		for(int k = 0; k < 3; k++)
    		{
    			C[i][j] += A[i][k] * B[k][j]; 
    		}
    	}
    }
    
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
