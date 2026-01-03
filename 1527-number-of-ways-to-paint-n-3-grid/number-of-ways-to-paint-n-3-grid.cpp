#include <bits/stdc++.h>
#define MMOD ((lng)(1e9+7))
#define lng long long int

using namespace std;

class Solution {
public:
    // dp is [number of rows][number of ways to paint them for 2 or 3 colors]
    // [n][0] is 2 colors
    // [n][1] is 3 colors
    lng dp[5001][2];

    int numOfWays(int n) {
        dp[1][0] = 6;
        dp[1][1] = 6;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (3*dp[i-1][0]%MMOD + 2*dp[i-1][1]%MMOD)%MMOD;
            dp[i][1] = (2*dp[i-1][0]%MMOD + 2*dp[i-1][1]%MMOD)%MMOD;
        }
        return (dp[n][0]%MMOD+dp[n][1]%MMOD)%MMOD;
    }
};