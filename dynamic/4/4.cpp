#include <iostream>
using namespace std;

int main() {
        // your code goes here
        int n = 0;
        int dp[46] = {0, };

        cin >> n;
        dp[1] = 1;
        dp[2] = 2
        for(int i = 3; i <= n; i++)
        {
                dp[i] = dp[i-1] + dp[i-2];
        }
        cout <<dp[n];
        return 0;
}
