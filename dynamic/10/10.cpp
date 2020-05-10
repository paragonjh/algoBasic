#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int n =0, m = 0;
    cin >> n >> m;

    vector<int> dy(m+1,0);
    for(int i = 0; i < n; i++)
    {
        int w ,v = 0;
        cin >> w >> v;

        for(int j = w; j <=m; j++)
        {
            dy[j] = max(dy[j], dy[j-w] + v);
        }
    }

    cout << dy[m] << endl;
    //for(int i = 0; i <=m ; i++)
    //{
    //    cout << dy[i] << " ";
    //}
    return 0;
}
