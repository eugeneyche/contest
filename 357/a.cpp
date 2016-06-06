#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_D (30000)

int main()
{
    int n_coins = 5;
    int coins [] = {1, 5, 10, 25, 50};
    int64_t dp [n_coins][MAX_D + 1];
    for (int i = 0; i < n_coins; i++) {
        int coin = coins[i];
        dp[i][0] = 1;
        for (int j = 1; j <= MAX_D; j++) {
            dp[i][j] = 0;
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= coins[i]) {
                dp[i][j] += dp[i][j - coin];
            }
        }
    }
    int d;
    while (cin >> d) {
        int64_t num_ways = dp[n_coins - 1][d];
        if (num_ways == 1) {
            cout << "There is only 1 way to produce " << d << " cents change." << endl;
        } else {
            cout << "There are " << num_ways << " ways to produce " << d << " cents change." << endl;
        }
    }
}
