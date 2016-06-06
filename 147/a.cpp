#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

struct TestCase
{
    float fl_amount;
    int amount;
};

int main()
{
    float float_amount;

    vector<TestCase> test_cases;

    int max_amount = 0;
    TestCase tc;
    while (cin >> tc.fl_amount) {
        tc.amount = static_cast<int>(20 * tc.fl_amount);
        if (tc.amount == 0) break;
        if (tc.amount > max_amount)
            max_amount = tc.amount;
        test_cases.push_back(tc);
    }

    vector<int> coins;
    coins.push_back(5);
    coins.push_back(10);
    coins.push_back(20);
    coins.push_back(50);
    coins.push_back(100);
    coins.push_back(200);
    coins.push_back(500);
    coins.push_back(1000);
    coins.push_back(2000);
    coins.push_back(5000);
    coins.push_back(10000);
    vector<vector<uint64_t> > dp (coins.size());
    for (int i = 0; i < coins.size(); i++) {
        coins[i] /= 5;
        dp[i].resize(max_amount + 1);
    }

    for (int i = 0; i < dp.size(); i++) {
        int coin_val = coins[i];
        dp[i][0] = 1;
        for (int j = 1; j < dp[i].size(); j++) {
            dp[i][j] = 0;
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= coin_val) {
                dp[i][j] += dp[i][j - coin_val];
            }
        }
    }

    for (int i = 0; i < test_cases.size(); i++) {
        const TestCase& test_case = test_cases[i];
        cout << right << setw(6) 
            << setprecision(2) << fixed 
            << test_case.fl_amount
            << setw(17) << dp.back()[test_case.amount]
            << endl;

    }
}
